/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:37:40 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/25 17:41:55 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include "include/Array.hpp"

// int main(void)
// {
// 	Array<int> a(5);
// 	for (unsigned int i = 0; i < a.size(); ++i)
// 		a[i] = i * 10;

// 	std::cout << "Array a:" << std::endl;
// 	for (unsigned int i = 0; i < a.size(); ++i)
// 		std::cout << a[i] << std::endl;

// 	Array<int> b(a);

// 	a[0] = 999;
// 	std::cout << "a[0] = " << a[0] << std::endl;
// 	std::cout << "b[0] = " << b[0] << " (should NOT change)" << std::endl;

// 	Array<std::string> s(3);
// 	s[0] = "Hello";
// 	s[1] = "Array";
// 	s[2] = "Template";

// 	for (unsigned int i = 0; i < s.size(); ++i)
// 		std::cout << s[i] << std::endl;

// 	try {
// 		std::cout << a[10] << std::endl;
// 	}
// 	catch (std::exception const &e) {
// 		std::cout << "Exception: " << e.what() << std::endl;
// 	}

// 	return 0;
// }

#include <iostream>
#include "include/Array.hpp"
#include <cstdlib>


#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}