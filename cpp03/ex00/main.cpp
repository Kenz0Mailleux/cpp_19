/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:28:04 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/14 14:41:39 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

int main()
{
    ClapTrap Charles("Charles");
    ClapTrap Magne("Magne");
    Charles.attack("Magne");
    Magne.takeDamage(5);
    Magne.beRepaired(3);
    Magne.attack("Charles");
    Charles.takeDamage(10);
    Charles.attack("Magne");
    Charles.beRepaired(5);
    return 0;
}
