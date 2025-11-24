/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:51:19 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 16:51:47 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "include/Span.hpp"

int main(void)
{
	// Exemple du sujet
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
	}

	// Gros test avec 10 000 nombres
	{
		unsigned int n = 10000;
		Span big(n);

		std::vector<int> tmp;
		tmp.reserve(n);
		for (unsigned int i = 0; i < n; ++i)
			tmp.push_back(i * 2); // nombres pairs

		// Ajout via range d'itérateurs
		big.addRange(tmp.begin(), tmp.end());

		std::cout << "big.shortestSpan(): " << big.shortestSpan() << std::endl;
		std::cout << "big.longestSpan() : " << big.longestSpan() << std::endl;
	}

	// Tests d'erreurs
	{
		Span s(2);
		try
		{
			s.shortestSpan();
		}
		catch (std::exception const &e)
		{
			std::cout << "Error (no elements): " << e.what() << std::endl;
		}

		s.addNumber(42);
		try
		{
			s.shortestSpan();
		}
		catch (std::exception const &e)
		{
			std::cout << "Error (one element): " << e.what() << std::endl;
		}

		s.addNumber(21);
		try
		{
			s.addNumber(84);
		}
		catch (std::exception const &e)
		{
			std::cout << "Error (full): " << e.what() << std::endl;
		}
	}

	return 0;
}
