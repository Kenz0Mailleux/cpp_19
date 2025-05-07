/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:28:04 by kenzo             #+#    #+#             */
/*   Updated: 2025/05/07 18:59:18 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include/Bureaucrat.hpp"

int main()
{

	try
	{
		Bureaucrat a("Lagea", 1);
		Bureaucrat b("Lagea", 150);
		Form c("Form1", 1, 1);
		Form d("Form2", 150, 150);
		Form e("Form3", 0, 0);
		Form f("Form4", 151, 151);
		Form g("Form5", 1, 151);
		Form h("Form6", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}