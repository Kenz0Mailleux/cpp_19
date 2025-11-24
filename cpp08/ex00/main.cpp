/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:49:28 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 16:50:22 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "include/easyfind.hpp"

int main(void)
{
	// Test avec std::vector
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i * 2); // 0, 2, 4, 6, 8, ...

	try
	{
		std::vector<int>::iterator it = easyfind(v, 6);
		std::cout << "Found 6 in vector at position: "
		          << std::distance(v.begin(), it) << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyfind(v, 7); // ne se trouve pas
		std::cout << "Found 7 in vector" << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception (vector): " << e.what() << std::endl;
	}

	// Test avec std::list
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	try
	{
		std::list<int>::const_iterator it = easyfind(static_cast<std::list<int> const &>(lst), 20);
		std::cout << "Found 20 in list" << std::endl;
		(void)it;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception (list): " << e.what() << std::endl;
	}

	return 0;
}
