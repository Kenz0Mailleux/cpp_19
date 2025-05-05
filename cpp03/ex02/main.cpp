/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:50:34 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/14 15:21:03 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"

int main()
{
    std::cout << "ClapTrap test" << std::endl;
    ClapTrap a("Soldat");
    a.attack("Demacia");
    a.takeDamage(3);
    a.beRepaired(2);

    std::cout << "\nScavTrap test" << std::endl;
    ScavTrap b("Lancier");
    b.attack("Noxus");
    b.takeDamage(30);
    b.beRepaired(15);
    b.guardGate();

    std::cout << "\nFragTrap test" << std::endl;
    FragTrap c("Epeiste");
    c.attack("Freljord");
    c.takeDamage(50);
    c.beRepaired(40);
    c.highFivesGuys();

    return 0;
}
