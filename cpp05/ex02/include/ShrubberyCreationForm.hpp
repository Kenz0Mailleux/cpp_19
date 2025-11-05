#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

protected:
    void doAction() const;

public:
    ShrubberyCreationForm(const std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
};

#endif
