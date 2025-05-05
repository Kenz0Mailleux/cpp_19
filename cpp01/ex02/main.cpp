/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:06:13 by kmailleu          #+#    #+#             */
/*   Updated: 2025/04/10 15:09:14 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;

    std::string& stringREF = brain;

    std::cout << "Memory address of the string variable  : " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR       : " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF       : " << &stringREF << std::endl;

    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;

    std::cout << "Value of the string variable           : " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR          : " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF          : " << stringREF << std::endl;

    return 0;
}
