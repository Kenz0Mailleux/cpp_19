/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:10:21 by kmailleu          #+#    #+#             */
/*   Updated: 2025/04/02 17:53:16 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
	std::string type;


public:
    Weapon();
    Weapon(std::string type);
	~Weapon();
    
    std::string getType();
    void setType(std::string type);
};

#endif
