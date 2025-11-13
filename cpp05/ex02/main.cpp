/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:23:02 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/13 15:36:51 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

// test généré
int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 140);
        Bureaucrat charlie("Charlie", 50);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm   robo("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        bob.signForm(shrub);
        charlie.signForm(robo);
        charlie.signForm(pardon);  // trop bas
        alice.signForm(pardon);    // ok
        bob.executeForm(shrub);    // trop bas pour exec
        charlie.executeForm(robo); // trop bas (45 requis)
        alice.executeForm(robo);   // ok
        alice.executeForm(shrub);  // ok (crée home_shrubbery)
        alice.executeForm(pardon); // ok

        return 0;
    } catch (std::exception &e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
}
