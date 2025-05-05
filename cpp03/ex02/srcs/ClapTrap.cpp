/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:33:06 by kmailleu          #+#    #+#             */
/*   Updated: 2025/04/14 15:17:48 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ClapTrap)
{
    std::cout << "Copy ClapTrap assignment operator called" << std::endl;
    if (this != &ClapTrap)
    {
        this->_name = ClapTrap._name;
        this->_hitPoints = ClapTrap._hitPoints;
        this->_energyPoints = ClapTrap._energyPoints;
        this->_attackDamage = ClapTrap._attackDamage;    
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack. No hit or energy points left!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! " << "Remaining HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't repair. No hit or energy points left!" << std::endl;
        return;
    }
    _hitPoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! " << "Current HP: " << _hitPoints << std::endl;
}
