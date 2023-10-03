/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 08:21:27 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/27 09:16:04 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooHighException();
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooLowException();
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : 
    _name(name) , _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooHighException();
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooLowException();
}

Form::~Form() {
}

Form::Form(const Form& other) :
    _name(other.getName()), _signed(false), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()) {
    *this = other;
}

Form &Form::operator=(const Form& other)
{
    if (this != &other)
    {
        _signed = other.getSigned();   
    }
    return (*this);
}

std::string Form::getName() const 
{
    return (_name);
}

bool        Form::getSigned() const
{
    return (_signed);
}

int         Form::getSignGrade() const
{
    return (_signGrade);
}

int         Form::getExecGrade() const
{
    return (_execGrade);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return "Grade is too high !";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return "Grade is too low !";
}

std::ostream& operator<<(std::ostream &out, const Form &f)
{
    out << f.getName() << ", is Form signed: " << f.getSigned() << " Sign grade: " << f.getSignGrade() << " Execute grade: " << f.getExecGrade() ;
    return out;
}

void    Form::beSigned(Bureaucrat& b) 
{
    if (b.getGrade() > this->getSignGrade())
        throw(Form::GradeTooLowException());
    else
        this->_signed = true;
}

void    Form::signForm(Bureaucrat& b)
{
    if (this->_signed)
        std::cout << b.getName() << " signed " << this->getName() << std::endl ;
    else
        std::cout << b.getName() << " couldn't sign " << this->getName() << "because the Forms grade is too high." << std::endl ;
}