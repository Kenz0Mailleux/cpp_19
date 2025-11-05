# include "../include/ShrubberyCreationForm.hpp"
# include <fstream>
# include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
        std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    }
    return *this;
}

void ShrubberyCreationForm::doAction() const {
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
        throw std::runtime_error("Failed to open shrubbery file");
    ofs << "      /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n"
           "     /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n"
           "    /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n"
           "        ||      ||\n"
           "        ||      ||\n"
           "        ||______||\n"
           "          |    |\n"
           "          |____|\n";
    ofs.close();
}
