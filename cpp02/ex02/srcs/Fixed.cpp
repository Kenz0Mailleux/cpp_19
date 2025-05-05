/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:41:41 by kmailleu          #+#    #+#             */
/*   Updated: 2025/04/11 16:57:44 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    //std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other){
    //std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed::Fixed(const int value) {
    //std::cout << "Int constructor called\n";
    _rawBits = value << _fractional;
}

Fixed::Fixed(const float value) {
    //std::cout << "Float constructor called\n";
    _rawBits = roundf(value * (1 << _fractional));
}

Fixed& Fixed::operator=(const Fixed& other){
    //std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat(); 
    return out;
}

Fixed::~Fixed(){
    //std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
    return this->_rawBits;
}

void Fixed::setRawBits(int rawBits) {
    this->_rawBits = rawBits;
}

float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractional);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractional;
}

//ex02

/*Comparaison*/
bool Fixed::operator>(const Fixed& other) const {
    return _rawBits > other._rawBits; }

bool Fixed::operator<(const Fixed& other) const {
    return _rawBits < other._rawBits; }

bool Fixed::operator>=(const Fixed& other) const {
    return _rawBits >= other._rawBits; }

bool Fixed::operator<=(const Fixed& other) const {
    return _rawBits <= other._rawBits; }

bool Fixed::operator==(const Fixed& other) const {
    return _rawBits == other._rawBits; }

bool Fixed::operator!=(const Fixed& other) const { 
    return _rawBits != other._rawBits; }

/*Math*/
Fixed Fixed::operator+(const Fixed& other) const {
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return (this->toFloat() / other.toFloat());
}

/*Incrémentation*/
Fixed& Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    _rawBits++;
    return tmp;
}

Fixed& Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    _rawBits--;
    return tmp;
}

/* min/max */
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    return b;
}
