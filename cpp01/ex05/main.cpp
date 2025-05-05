/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:19:14 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/10 14:59:51 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Harl.hpp"

int main(int argc, char **argv)
{
	Harl Harl;

	if (argc == 2)
	{
		Harl.complain(argv[1]);
	}
	else 
	{
		std::cout << "Bad input" << std::endl;
	}
	return 0;
}