/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:10:37 by kmailleu          #+#    #+#             */
/*   Updated: 2025/04/02 18:14:40 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
    Weapon& weapon;

public:
    HumanA(std::string name, Weapon& weapon);
	~HumanA();

    void attack();
};

#endif
