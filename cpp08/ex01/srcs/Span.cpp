/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:51:11 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 16:51:12 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n), _numbers()
{
}

Span::Span(Span const &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span::~Span()
{
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int value)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span::addNumber: container is full");
	_numbers.push_back(value);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Span::shortestSpan: not enough elements");

	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	int minSpan = tmp[1] - tmp[0];
	for (std::size_t i = 1; i < tmp.size() - 1; ++i)
	{
		int span = tmp[i + 1] - tmp[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Span::longestSpan: not enough elements");

	std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> mm;
	mm = std::minmax_element(_numbers.begin(), _numbers.end());
	return *mm.second - *mm.first;
}
