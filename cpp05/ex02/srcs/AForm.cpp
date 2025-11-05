/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                                            */
/* ************************************************************************** */

# include "../include/AForm.hpp"
# include "../include/Bureaucrat.hpp"

static void checkGradeBoundsAForm(unsigned int g) {
    if (g < 1)  throw AForm::GradeTooHighException();
    if (g > 150) throw AForm::GradeTooLowException();
}

AForm::AForm() : _name("LageaForm"), _isSigned(false), _signedGrade(150), _executeGrade(150) {
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const std::string name, unsigned int signedGrade, unsigned int executeGrade) : _name(name), _isSigned(false), _signedGrade(signedGrade), _executeGrade(executeGrade) {
    checkGradeBoundsAForm(signedGrade);
    checkGradeBoundsAForm(executeGrade);
    std::cout << "AForm constructor called" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned),
  _signedGrade(other._signedGrade), _executeGrade(other._executeGrade) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
        std::cout << "AForm assignment operator called" << std::endl;
    }
    return *this;
}

std::string AForm::getName() const {
	return this->_name; }

bool AForm::getIsSigned() const {
	return this->_isSigned; }

unsigned int AForm::getSignedGrade() const {
	return this->_signedGrade; }

unsigned int AForm::getExecuteGrade() const {
	return this->_executeGrade; }

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= this->_signedGrade) {
        if (this->_isSigned == 0) {
            this->_isSigned = 1;
            bureaucrat.signForm(*this);
        } else {
            std::cout << this->_name << " is already signed." << std::endl;
        }
    } else {
        if (this->_isSigned)
            std::cout << this->_name << " is already signed." << std::endl;
        bureaucrat.signForm(*this);
        throw (AForm::GradeTooLowException());
    }
}

void AForm::execute(Bureaucrat const &executor) const {
    if (this->_isSigned == false)
        throw (AForm::NotSignedException());
    if (executor.getGrade() > this->_executeGrade)
        throw (AForm::GradeTooLowException());
    this->doAction();
}

const char* AForm::Exception::what() const throw() { return "Form exception"; }

const char* AForm::GradeTooHighException::what() const throw() { return "Form grade too high"; }

const char* AForm::GradeTooLowException::what() const throw() { return "Form grade too low"; }

const char* AForm::NotSignedException::what() const throw() { return "Form not signed"; }

std::ostream& operator<<(std::ostream& out, const AForm& other) {
    out << "Form name: " << other.getName() << std::endl;
    out << "Form signed: " << other.getIsSigned() << std::endl;
    out << "Form signed grade: " << other.getSignedGrade() << std::endl;
    out << "Form execute grade: " << other.getExecuteGrade() << std::endl;
    return out;
}
