/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:26:29 by kmailleu          #+#    #+#             */
/*   Updated: 2025/11/13 15:47:48 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Form.hpp"
# include "../include/Bureaucrat.hpp"

Form::Form() : _name("Lagea"), _isSigned(false), _signedGrade(150), _executeGrade(150) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, unsigned int signedGrade, unsigned int executeGrade)
: _name(name), _isSigned(false), _signedGrade(signedGrade), _executeGrade(executeGrade) {
    if (signedGrade > 150 || executeGrade > 150) {
        throw (Form::GradeTooLowException());
    }
    else if (signedGrade < 1 || executeGrade < 1) {
        throw (Form::GradeTooHighException());
    }
    std::cout << "Form constructor called" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &other)
: _name(other._name), _isSigned(other._isSigned),
  _signedGrade(other._signedGrade), _executeGrade(other._executeGrade) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
        std::cout << "Form assignment operator called" << std::endl;
    }
    return *this;
}

std::string Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

unsigned int Form::getSignedGrade() const {
    return this->_signedGrade;
}

unsigned int Form::getExecuteGrade() const {
    return this->_executeGrade;
}

std::ostream& operator<<(std::ostream& out, const Form& other) {
    out << "Form name: " << other.getName() << std::endl;
    out << "Form signed: " << (other.getIsSigned() ? "true" : "false") << std::endl;
    out << "Form signed grade: " << other.getSignedGrade() << std::endl;
    out << "Form execute grade: " << other.getExecuteGrade() << std::endl;
    return out;
}

void Form::beSigned(const Bureaucrat &other) {
    if (other.getGrade() > this->_signedGrade) {
        throw (Form::GradeTooLowException());
    }
    if (this->_isSigned == true) {
        std::cout << this->_name << " is already signed." << std::endl;
        return ;
    }
    this->_isSigned = true;
}

const char* Form::Exception::what() const throw() {
    return "Form exception";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low";
}
