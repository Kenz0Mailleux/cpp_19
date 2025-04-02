/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:10:02 by kmailleu          #+#    #+#             */
/*   Updated: 2025/04/02 18:06:22 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon() {}

Weapon::~Weapon() {}

Weapon::Weapon(std::string type) : type(type) {}

std::string  Weapon::getType() {
    return type;
}

void Weapon::setType(std::string type) {
    //std::cout << type;
    this->type = type;
}