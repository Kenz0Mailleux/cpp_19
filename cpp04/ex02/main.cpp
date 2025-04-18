/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:26:47 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/18 17:01:22 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"	
int main()
{
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();

    delete j;
    delete i;
    
    std::cout << "\n\nWRONG ANIMAL TEST\n";
    
    const WrongAnimal* a = new WrongAnimal();
    const WrongAnimal* b = new WrongCat();
    std::cout << b->getType() << std::endl;
    b->makeSound();
    a->makeSound();

    delete a;
    delete b;

    return 0;
}