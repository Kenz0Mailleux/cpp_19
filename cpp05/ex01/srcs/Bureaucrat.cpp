/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:18:32 by kmailleu          #+#    #+#             */
/*   Updated: 2025/05/07 18:56:59 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Lagea"), _grade(150) {
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name) {
    if (grade > 150){
        throw (Bureaucrat::GradeTooLowException());
    }
    else if (grade < 1){
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

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) {
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

unsigned int Bureaucrat::getGrade() const {
    return this->_grade;
}

unsigned int Bureaucrat::setGrade(unsigned int newGrade){
    this->_grade = newGrade;
    return newGrade;
}

void Bureaucrat::incrementGrade(){
    if ((this->_grade - 1) >= 1){
        this->_grade--;
    }
    else {
        throw (Bureaucrat::GradeTooHighException());
    }
}

void Bureaucrat::decrementGrade(){
    if ((this->_grade + 1) <= 150){
        this->_grade++;
    }
    else{
        throw (Bureaucrat::GradeTooLowException());
    }
}

void Bureaucrat::signForm(Form &formName){
    if ( formName.getIsSigned() == true)
    {
        std::cout << this->getName() << " signed " << formName.getName() << std::endl;
    }
    else
    {
        std::cout << this->getName() << " couldn’t sign < " << formName.getName() << " because " << std::endl;
    }
}

const char* Bureaucrat::Exception::what() const throw()
{
	return ("Bureaucrat Exception\n");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade cant be under 1!\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade cant be over 150!\n");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << "Bureaucrat " << other.getName() << " has a grade of " << other.getGrade() << ".";
	return out;
}