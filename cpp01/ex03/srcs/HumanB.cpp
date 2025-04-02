/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:09:59 by kmailleu          #+#    #+#             */
/*   Updated: 2025/04/02 18:19:53 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB (std::string name) : name(name), equiped(0), weapon(nullptr){}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& type) {
    this->weapon = &type;
    this->equiped = 1;
}

void HumanB::attack() {
    if (equiped)
        std::cout << name << " attacks with " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon equiped" << std::endl;
}
