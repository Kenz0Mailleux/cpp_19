/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inter.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:40:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/11/05 16:17:12 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Intern.hpp"

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

/*
** makeForm:
**  crée dynamiquement une instance du bon type de formulaire
**  en fonction du nom passé en paramètre.
**  évite les if/else en chaîne grâce à des tableaux de pointeurs sur fonctions.
*/

AForm* Intern::makeForm(const std::string formName, const std::string target) const
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
	
    AForm* (*creators[3])(const std::string&) = {
        [](const std::string &t) -> AForm* { return new ShrubberyCreationForm(t); },
        [](const std::string &t) -> AForm* { return new RobotomyRequestForm(t); },
        [](const std::string &t) -> AForm* { return new PresidentialPardonForm(t); }
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern couldn’t find form: \"" << formName << "\"" << std::endl;
    throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Form name not recognized by Intern\n");
}
