#ifndef __AFORM_HPP__
#define __AFORM_HPP__

# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string  _name;
    bool               _isSigned;
    const unsigned int _signedGrade;
    const unsigned int _executeGrade;

protected:
    virtual void doAction() const = 0;

public:
    AForm();
    AForm(const std::string name, unsigned int signedGrade, unsigned int executeGrade);
    virtual ~AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

    std::string     getName() const;
    bool            getIsSigned() const;
    unsigned int    getSignedGrade() const;
    unsigned int    getExecuteGrade() const;

    void beSigned(Bureaucrat &bureaucrat);
    void execute(Bureaucrat const &executor) const;

    class Exception : public std::exception {
        public: const char* what() const throw();
    };
    class GradeTooHighException : public AForm::Exception {
        public: const char* what() const throw();
    };
    class GradeTooLowException : public AForm::Exception {
        public: const char* what() const throw();
    };
    class NotSignedException : public AForm::Exception {
        public: const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& other);

#endif
