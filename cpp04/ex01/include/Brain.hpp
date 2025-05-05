/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:56:39 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/18 17:07:33 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
    std::string _ideas[100];

public:
    Brain();
    ~Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);

    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};

#endif

