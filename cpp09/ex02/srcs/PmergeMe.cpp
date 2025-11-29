/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:00:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/02/10 15:00:00 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <cstdlib>
#include <cerrno>
#include <climits>
#include <stdexcept>
#include <algorithm>
#include <utility>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &)
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &)
{
	return *this;
}

PmergeMe::~PmergeMe()
{
}

template <typename T>
struct PairFirstLess
{
	bool operator()(std::pair<T, T> const &a, std::pair<T, T> const &b) const
	{
		return a.first < b.first;
	}
};

static long strToLong(const std::string &s)
{
	char *end = 0;
	errno = 0;
	long value = std::strtol(s.c_str(), &end, 10);
	if (errno || end == s.c_str() || *end != '\0')
		throw std::runtime_error("invalid number");
	return value;
}

std::vector<int> PmergeMe::parseArgs(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("no input");

	std::vector<int> numbers;
	for (int i = 1; i < argc; ++i)
	{
		long v = strToLong(argv[i]);
		if (v <= 0 || v > INT_MAX)
			throw std::runtime_error("invalid number");
		numbers.push_back(static_cast<int>(v));
	}
	return numbers;
}

// Simple binary insertion into a sorted container
template <typename Container>
static void binaryInsert(Container &c, typename Container::value_type value)
{
	typename Container::iterator pos = std::lower_bound(c.begin(), c.end(), value);
	c.insert(pos, value);
}

// Generate insertion order using Jacobsthal numbers to mimic merge-insert behavior
static std::vector<std::size_t> jacobsthalOrder(std::size_t n)
{
	std::vector<std::size_t> order;
	if (n == 0)
		return order;
	std::vector<std::size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < n)
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

	std::vector<bool> used(n, false);
	for (std::size_t i = 1; i + 1 < jacob.size() && jacob[i] < n; ++i)
	{
		std::size_t start = jacob[i];
		std::size_t end = std::min(jacob[i + 1], n);
		for (std::size_t k = end; k > start; --k)
		{
			if (!used[k - 1])
			{
				order.push_back(k - 1);
				used[k - 1] = true;
			}
		}
	}
	for (std::size_t i = 0; i < n; ++i)
	{
		if (!used[i])
			order.push_back(i);
	}
	return order;
}

template <typename Container>
static void fordJohnson(Container &data)
{
	if (data.size() <= 1)
		return;

	typedef typename Container::value_type value_type;
	typedef std::pair<value_type, value_type> Pair;

	std::vector<Pair> pairs;
	bool hasStraggler = false;
	value_type straggler = value_type();

	typename Container::iterator it = data.begin();
	while (it != data.end())
	{
		value_type first = *it++;
		if (it == data.end())
		{
			hasStraggler = true;
			straggler = first;
			break;
		}
		value_type second = *it++;
		if (first < second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}

	std::sort(pairs.begin(), pairs.end(), PairFirstLess<value_type>());

	Container mainChain;
	std::vector<value_type> pend;
	pend.reserve(pairs.size() + (hasStraggler ? 1 : 0));

	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	if (hasStraggler)
		pend.push_back(straggler);

	// Insert second elements following Jacobsthal order
	std::vector<std::size_t> order = jacobsthalOrder(pend.size());
	for (std::size_t idx = 0; idx < order.size(); ++idx)
	{
		std::size_t pendIdx = order[idx];
		if (pendIdx < pend.size())
			binaryInsert(mainChain, pend[pendIdx]);
	}

	data.assign(mainChain.begin(), mainChain.end());
}

void PmergeMe::sortVector(std::vector<int> &data)
{
	fordJohnson(data);
}

void PmergeMe::sortDeque(std::deque<int> &data)
{
	fordJohnson(data);
}
