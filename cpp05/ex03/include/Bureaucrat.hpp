/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:18:53 by kmailleu          #+#    #+#             */
/*   Updated: 2025/11/05 16:00:26 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string name, unsigned int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);

    std::string     getName() const;
    unsigned int    getGrade() const;
    unsigned int    setGrade(unsigned int newGrade);

    void            incrementGrade();
    void            decrementGrade();

    void            signForm(AForm &formName);
    void            executeForm(AForm const &form) const;

    class Exception : public std::exception
    {
        public :
            const char* what() const throw();
    };

    class GradeTooHighException : public Bureaucrat::Exception
    {
        public :
            const char* what() const throw();
    };

    class GradeTooLowException : public Bureaucrat::Exception
    {
        public :
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif
