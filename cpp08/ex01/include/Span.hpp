/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:51:01 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 17:01:48 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>

class Span
{
public:
	Span(unsigned int n);
	Span(Span const &other);
	~Span();

	Span &operator=(Span const &other);

	void addNumber(int value);

	template <typename It>
	void addRange(It first, It last)
	{
		std::size_t dist = std::distance(first, last);
		if (_numbers.size() + dist > _maxSize)
			throw std::runtime_error("Span::addRange: not enough space");
		_numbers.insert(_numbers.end(), first, last);
	}

	int shortestSpan() const;
	int longestSpan() const;

private:
	Span();

	unsigned int     _maxSize;
	std::vector<int> _numbers;
};

#endif
