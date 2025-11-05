#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

protected:
    void doAction() const;

public:
    PresidentialPardonForm(const std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
};

#endif
