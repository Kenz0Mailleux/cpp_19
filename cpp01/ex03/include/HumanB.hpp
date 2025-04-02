/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:10:35 by kmailleu          #+#    #+#             */
/*   Updated: 2025/04/02 18:18:22 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
    Weapon* weapon;
    int equiped;

public:
    HumanB(std::string name);
	~HumanB();

    void setWeapon(Weapon& type);
    void attack();
};

#endif
