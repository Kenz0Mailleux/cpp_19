/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:26:47 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/18 17:22:44 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"	

int main() {
    const Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; ++i) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    std::cout << "\n\nDEEP COPY TEST\n";
    Cat original;
    original.getBrain()->setIdea(0, "Manger des croquettes");
    Cat copy = original;
    copy.getBrain()->setIdea(0, "Manger une souris");
    std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea:     " << copy.getBrain()->getIdea(0) << std::endl;
    if (original.getBrain()->getIdea(0) != copy.getBrain()->getIdea(0))
        std::cout << "Deep copy success for Cat\n";
    else
        std::cout << "Deep copy failed for Cat\n";
    return 0;
}

