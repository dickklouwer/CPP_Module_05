/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 08:21:27 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/28 10:57:42 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooHighException();
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooLowException();
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : 
    _name(name) , _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooHighException();
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooLowException();
}

AForm::~AForm() {
}

AForm::AForm(const AForm& other) :
    _name(other.getName()), _signed(false), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()) {
    *this = other;
}

AForm &AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _signed = other.getSigned();   
    }
    return (*this);
}

std::string AForm::getName() const 
{
    return (_name);
}

bool        AForm::getSigned() const
{
    return (_signed);
}

int         AForm::getSignGrade() const
{
    return (_signGrade);
}

int         AForm::getExecGrade() const
{
    return (_execGrade);
}

// void        AForm::execute(const Bureaucrat& executor) 
// {
//     (void)executor;
// }

std::ostream& operator<<(std::ostream &out, const AForm &f)
{
    out << f.getName() << ", is Form signed: " << f.getSigned() << " Sign grade: " << f.getSignGrade() << " Execute grade: " << f.getExecGrade() ;
    return out;
}

void    AForm::beSigned(Bureaucrat& b) 
{
    if (b.getGrade() > this->getSignGrade())
        throw(AForm::GradeTooLowException());
    else
        this->_signed = true;
}

void    AForm::signForm(const Bureaucrat& b)
{
    if (this->_signed)
        std::cout << b.getName() << " signed " << this->getName() << std::endl ;
    else
        std::cout << b.getName() << " couldn't sign " << this->getName() << "because the Forms grade is too high." << std::endl ;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return "Grade is too high !";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return "Grade is too low !";
}

const char *AForm::FormNotSigned::what(void) const throw()
{
    return "Form is not signed !";
}