/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 10:25:00 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/27 08:50:25 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade ) : _name(name), _grade(grade) 
{
    if (_grade > 150)
        throw GradeTooHighException();
    if (_grade < 1)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade())
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
    if ( this != &other )
        _grade = other.getGrade();
    return ( *this );
}

std::string     Bureaucrat::getName() const
{
    return _name;
}

int             Bureaucrat::getGrade() const
{
    return _grade;
}

void            Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooLowException();
    _grade--;
}

void            Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooHighException();
    _grade++;
}

void            Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute( *this );
        std::cout << *this << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << *this << " failed to sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade: " << b.getGrade() ;
    return out;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "Grade is too high !";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "Grade is too low !";
}