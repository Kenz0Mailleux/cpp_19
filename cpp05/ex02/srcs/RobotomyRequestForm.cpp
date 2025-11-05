# include "../include/RobotomyRequestForm.hpp"
# include <cstdlib>
# include <ctime>
# include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
        std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    }
    return *this;
}

void RobotomyRequestForm::doAction() const {
    static bool seeded = false;
    if (!seeded) { std::srand(static_cast<unsigned int>(std::time(0))); seeded = true; }
    std::cout << "* BZZzzzz… drrrrrr… *" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}
