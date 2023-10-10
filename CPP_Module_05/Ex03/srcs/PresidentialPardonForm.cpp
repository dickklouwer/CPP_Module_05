/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:57:52 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/10/04 13:04:33 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

/*
    Declaring the constructor for the PresidentialPardon form which is derived from
    the abstract class AForm. The member initialization list initializes the base
    class (AForm) and the _target member variable after the colon (":").
 */
PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) :
    AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

/* 
    Destructor.
 */
PresidentialPardonForm::~PresidentialPardonForm() {
}

/* 
    The copy constructor derived from the base class. 
    "AForm(other)" calls the copy constructor from the base class. 
    "_target(other._target)" copies the the _target of the derived class. 
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
    AForm(other), _target(other._target) {
}

/* 
    Preventing assigment as the member variables are constants.
 */
PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
    return *this;
}

void    PresidentialPardonForm::execute( const Bureaucrat& executor ) const
{
    if (this->getSigned() == false)
        throw AForm::FormNotSigned();
    else if (this->getExecGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}