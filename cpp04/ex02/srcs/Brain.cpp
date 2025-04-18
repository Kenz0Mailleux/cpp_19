/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:56:52 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/18 17:10:17 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; ++i) {
        _ideas[i] = "idea " + std::to_string(i);
    }
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
    for (int i = 0; i < 100; ++i) {
        _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            _ideas[i] = other._ideas[i];
        }
        std::cout << "Brain assignment operator called" << std::endl;
    }
    return *this;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
    else
        std::cerr << "Invalid index in setIdea: " << index << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return _ideas[index];
    else {
        std::cerr << "Invalid index in getIdea: " << index << std::endl;
        return "";
    }
}
