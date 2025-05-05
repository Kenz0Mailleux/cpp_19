/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:41:43 by kmailleu          #+#    #+#             */
/*   Updated: 2025/04/11 16:58:51 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{

private:
    int _rawBits;

public:
    Fixed();
    Fixed(Fixed& other);
    Fixed& operator=(Fixed& other);
    ~Fixed();

    int getRawBits(void);
    void setRawBits(int rawBits);
};


#endif