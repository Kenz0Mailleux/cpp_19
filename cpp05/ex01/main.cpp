/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:45:02 by kenzo             */
/*   Updated: 2025/11/13 19:05:21 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int main(void)
{
    try {
        Bureaucrat alice("Alice", 20);
        Bureaucrat bob("Bob", 120);

        Form easy("EasyForm", 140, 100);
        Form medium("MediumForm", 50, 30);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << easy << std::endl;
        std::cout << medium << std::endl;

        // Bob peut signer easy (140 requis, il a 120)
        bob.signForm(easy);

        // Bob ne peut PAS signer medium (50 requis, il a 120)
        bob.signForm(medium);

        // Alice peut signer medium (20 <= 50)
        alice.signForm(medium);

        std::cout << easy << std::endl;
        std::cout << medium << std::endl;

        return 0;
    }
    catch (std::exception &e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
}

