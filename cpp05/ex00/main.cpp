/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:45:02 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/13 15:23:34 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Bureaucrat.hpp"

int main(void)
{
    std::cout << "===== TEST 1: Construction valide =====" << std::endl;
    try {
        Bureaucrat a("Alice", 42);
        Bureaucrat b("Bob", 1);
        Bureaucrat c("Charlie", 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Construction invalide =====" << std::endl;
    try {
        Bureaucrat x("Xavier", 0);      // trop haut
    }
    catch (std::exception &e) {
        std::cerr << "Exception attendue: " << e.what() << std::endl;
    }

    try {
        Bureaucrat y("Yves", 151);      // trop bas
    }
    catch (std::exception &e) {
        std::cerr << "Exception attendue: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: incrementGrade() =====" << std::endl;
    try {
        Bureaucrat b("Benoit", 3);
        std::cout << b << std::endl;

        b.incrementGrade();
        std::cout << b << std::endl;    // 2

        b.incrementGrade();
        std::cout << b << std::endl;    // 1

        b.incrementGrade();             // dépasse
        std::cout << b << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: decrementGrade() =====" << std::endl;
    try {
        Bureaucrat c("Clement", 149);
        std::cout << c << std::endl;

        c.decrementGrade();
        std::cout << c << std::endl;    // 150

        c.decrementGrade();             // dépasse
        std::cout << c << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST FINAL: operator<< =====" << std::endl;
    Bureaucrat d("Dorian", 42);
    std::cout << d << std::endl;

    return 0;
}
