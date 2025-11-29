/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:00:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/02/10 15:00:00 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	explicit BitcoinExchange(const std::string &databasePath);
	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange &operator=(BitcoinExchange const &other);
	~BitcoinExchange();

	void processFile(const std::string &inputPath) const;

private:
	void loadDatabase(const std::string &databasePath);

	static bool     isValidDate(const std::string &date);
	static bool     parseValue(const std::string &token, double &out);
	static std::string trim(const std::string &s);
	double          rateForDate(const std::string &date) const;

	std::map<std::string, double> _rates;
};

#endif
