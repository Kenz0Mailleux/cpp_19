/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:28:04 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/10 15:26:01 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

int main() {
    Zombie* Zumbie = newZombie("Zumbie"); //heap
    Zumbie->announce();
    delete Zumbie;

    randomChump("SalsaZumbie"); //stack

    return 0;
}
