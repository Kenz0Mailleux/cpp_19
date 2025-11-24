/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:36:12 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 17:27:41 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "include/iter.hpp"

template <typename T>
void printElem(T const &x)
{
	std::cout << x << std::endl;
}

void increment(int &x)
{
	++x;
}

int main(void)
{
	int arr[5] = {0, 1, 2, 3, 4};

	std::cout << "Before increment:" << std::endl;
	iter(arr, 5, printElem<int>);

	iter(arr, 5, increment);

	std::cout << "After increment:" << std::endl;
	iter(arr, 5, printElem<int>);

	std::string strs[3] = {"Hello", "Iter", "Template"};
	iter(strs, 3, printElem<std::string>);

	const char *cstrs[3] = {"const", "char*", "array"};
	iter(cstrs, 3, printElem<const char*>);

	return 0;
}
