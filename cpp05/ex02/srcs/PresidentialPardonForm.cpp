# include "../include/PresidentialPardonForm.hpp"
# include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
        std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    }
    return *this;
}

void PresidentialPardonForm::doAction() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
