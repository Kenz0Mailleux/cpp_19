/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:18:32 by kmailleu          #+#    #+#             */
/*   Updated: 2025/11/05 15:52:00 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Bureaucrat.hpp"
# include "../include/AForm.hpp"

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
        _grade = static_cast<int>(grade);
        std::cout << "Bureaucrat constructor called" << std::endl;
    }
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
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
    return static_cast<unsigned int>(this->_grade);
}

unsigned int Bureaucrat::setGrade(unsigned int newGrade){
    this->_grade = static_cast<int>(newGrade);
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

void Bureaucrat::signForm(AForm &formName){
    if ( formName.getIsSigned() == true)
    {
        std::cout << this->getName() << " signed " << formName.getName() << std::endl;
    }
    else
    {
        std::cout << this->getName() << " couldn’t sign < " << formName.getName() << " because " << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->getName() << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
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
