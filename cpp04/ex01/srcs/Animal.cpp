/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:44:49 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/18 17:26:30 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : _type("Metamorph") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        _type = other._type;
        std::cout << "Animal assignment operator called" << std::endl;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal crying" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}

Brain* Animal::getBrain() const {
    return NULL;
}
