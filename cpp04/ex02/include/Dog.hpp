/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:45:11 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/18 17:09:07 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
private:
    Brain* _brain;

public:
    Dog();
    virtual ~Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);

    void makeSound() const override;
    Brain* getBrain() const;
};

#endif
