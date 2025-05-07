/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:18:53 by kmailleu          #+#    #+#             */
/*   Updated: 2025/05/07 18:41:25 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

# include <iostream>
# include <string>
# include "Form.hpp"

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

    std::string getName() const;
    unsigned int getGrade() const;
    unsigned int setGrade(unsigned int newGrade);
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &formName);

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