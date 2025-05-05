/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:45:38 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/18 17:07:36 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {
private:
    Brain* _brain;

public:
    Cat();
    virtual ~Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);

    void makeSound() const override;
    Brain* getBrain() const;
};

#endif
