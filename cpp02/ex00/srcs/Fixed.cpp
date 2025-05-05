/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:41:41 by kmailleu          #+#    #+#             */
/*   Updated: 2025/04/11 15:12:46 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed& other){
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed& Fixed::operator=(Fixed& other){
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void){
    std::cout << "getRawBits member function called\n";
    return this->_rawBits;

}

void Fixed::setRawBits(int rawBits){
    this->_rawBits = rawBits;
}