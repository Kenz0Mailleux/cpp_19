/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:40:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/11/05 16:16:29 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    ~Intern();
    Intern &operator=(const Intern &other);

    AForm*  makeForm(const std::string formName, const std::string target) const;

    class FormNotFoundException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

#endif
