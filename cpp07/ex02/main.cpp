/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:37:40 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 16:38:08 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Array.hpp"

int main(void)
{
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = i * 10;

	std::cout << "Array a:" << std::endl;
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << a[i] << std::endl;

	Array<int> b(a);

	a[0] = 999;
	std::cout << "a[0] = " << a[0] << std::endl;
	std::cout << "b[0] = " << b[0] << " (should NOT change)" << std::endl;

	Array<std::string> s(3);
	s[0] = "Hello";
	s[1] = "Array";
	s[2] = "Template";

	for (unsigned int i = 0; i < s.size(); ++i)
		std::cout << s[i] << std::endl;

	try {
		std::cout << a[10] << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
