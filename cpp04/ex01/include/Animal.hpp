/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:44:33 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/18 17:25:08 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {
protected:
    std::string _type;

public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);

    virtual void makeSound() const;
    virtual std::string getType() const;
    virtual Brain* getBrain() const;
};

#endif
