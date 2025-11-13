/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:56:59 by kmailleu          #+#    #+#             */
/*   Updated: 2025/11/13 15:48:40 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Bureaucrat.hpp"
# include "../include/Form.hpp"

Bureaucrat::Bureaucrat() : _name("Lagea"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade > 150) {
        throw (Bureaucrat::GradeTooLowException());
    }
    else if (grade < 1) {
        throw (Bureaucrat::GradeTooHighException());
    }
    else {
        _grade = grade;
        std::cout << "Bureaucrat constructor called" << std::endl;
    }
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->_grade = other._grade;
        std::cout << "Bureaucrat assignment operator called" << std::endl;
    }
    return *this;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1) {
        throw (Bureaucrat::GradeTooHighException());
    }
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150) {
        throw (Bureaucrat::GradeTooLowException());
    }
    this->_grade++;
}

void Bureaucrat::signForm(Form &formName) {
    try {
        formName.beSigned(*this);
        std::cout << this->getName()
                  << " signed " << formName.getName()
                  << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->getName()
                  << " couldn’t sign " << formName.getName()
                  << " because " << e.what()
                  << std::endl;
    }
}

const char* Bureaucrat::Exception::what() const throw() {
    return ("Bureaucrat Exception");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade cant be under 1!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade cant be over 150!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other) {
    out << "Bureaucrat " << other.getName()
        << " has a grade of " << other.getGrade() << ".";
    return out;
}
