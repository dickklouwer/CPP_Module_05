/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 10:25:00 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/26 11:53:04 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade ) : _name(name), _grade(grade) {
    if (_grade > 150)
        throw GradeTooHighException();
    if (_grade < 1)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {
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

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade: " << b.getGrade() ;
    return out;
}