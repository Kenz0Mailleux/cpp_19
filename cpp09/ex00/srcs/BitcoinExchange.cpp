/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:00:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/11/29 20:34:50 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string &databasePath)
{
	loadDatabase(databasePath);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
	: _rates(other._rates)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string &databasePath)
{
	std::ifstream db(databasePath.c_str());
	if (!db.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	// skip header
	std::getline(db, line);
	while (std::getline(db, line))
	{
		if (!line.empty() && line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);
		if (line.empty())
			continue;
		std::size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		std::string date = trim(line.substr(0, pos));
		std::string valueStr = trim(line.substr(pos + 1));
		if (!isValidDate(date))
			continue;
		double value;
		if (!parseValue(valueStr, value))
			continue;
		_rates[date] = value;
	}
	if (_rates.empty())
		throw std::runtime_error("Error: database is empty.");
}

std::string BitcoinExchange::trim(const std::string &s)
{
	std::size_t start = 0;
	while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
		++start;
	std::size_t end = s.size();
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		--end;
	return s.substr(start, end - start);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (std::size_t i = 0; i < date.size(); ++i)
	{
		if ((i == 4 || i == 7))
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	int y, m, d;
	std::istringstream iss(date);
	char dash;
	if (!(iss >> y >> dash >> m >> dash >> d))
		return false;
	if (y < 2009 || m < 1 || m > 12 || d < 1)
		return false;
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int dim = daysInMonth[m - 1];
	bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	if (m == 2 && leap)
		dim = 29;
	return d <= dim;
}

bool BitcoinExchange::parseValue(const std::string &token, double &out)
{
	std::string trimmed = trim(token);
	if (trimmed.empty())
		return false;
	std::istringstream iss(trimmed);
	iss >> out;
	if (!iss || !iss.eof())
		return false;
	if (out != out || out == std::numeric_limits<double>::infinity()
		|| out == -std::numeric_limits<double>::infinity())
		return false;
	return true;
}

double BitcoinExchange::rateForDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
	if (it == _rates.end())
	{
		--it;
		return it->second;
	}
	if (it->first == date)
		return it->second;
	if (it == _rates.begin())
		throw std::runtime_error("Error: no rate available for this date.");
	--it;
	return it->second;
}

void BitcoinExchange::processFile(const std::string &inputPath) const
{
	std::ifstream in(inputPath.c_str());
	if (!in.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(in, line))
	{
		if (!line.empty() && line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);
		if (line.empty())
			continue;
		std::string trimmedLine = trim(line);
		if (trimmedLine.empty())
			continue;
		if (trimmedLine == "date | value")
			continue;
		std::size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value;
		if (!parseValue(valueStr, value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			double rate = rateForDate(date);
			std::cout << date << " => " << value << " = " << rate * value << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
