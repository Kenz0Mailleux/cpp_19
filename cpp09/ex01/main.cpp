/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:00:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/02/10 15:00:00 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		long result = RPN::evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (std::exception const &)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
