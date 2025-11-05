#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

protected:
    void doAction() const;

public:
    RobotomyRequestForm(const std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
};

#endif
