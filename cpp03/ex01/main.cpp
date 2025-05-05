/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:50:34 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/14 14:55:23 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"

int main()
{
    std::cout << "ClapTrap test" << std::endl;
    ClapTrap a("Jean");
    a.attack("Claude");
    a.takeDamage(3);
    a.beRepaired(2);

    std::cout << "\nScavTrap test" << std::endl;
    ScavTrap b("Lane");
    b.attack("Swap");
    b.takeDamage(30);
    b.beRepaired(15);
    b.guardGate();

    return 0;
}
