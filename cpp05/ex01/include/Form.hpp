/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:26:32 by kmailleu          #+#    #+#             */
/*   Updated: 2025/05/07 18:41:51 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const unsigned int _signedGrade;
    const unsigned int _executeGrade;

public:
    Form();
    Form(const std::string name, unsigned int signedGrade, unsigned int executeGrade);
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);

    
    std::string getName() const;
    unsigned int getGrade() const;
    bool getIsSigned() const;
    unsigned int getSignedGrade() const;
    unsigned int getExecuteGrade() const;
    void beSigned(Bureaucrat &bureaucrat);


    class Exception : public std::exception
    {
        public :
            const char* what() const throw();
    };

    class GradeTooHighException : public Form::Exception
    {
        public :
            const char* what() const throw();
    };
    
    class GradeTooLowException : public Form::Exception
    {
        public :
            const char* what() const throw();
    };  
};

std::ostream& operator<<(std::ostream& out, const Form& other);

# endif