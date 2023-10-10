/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:01:56 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/10/04 12:50:50 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

/*
    Declaring the constructor for the RobotomyRequestForm form which is derived from
    the abstract class AForm. The member initialization list initializes the base
    class (AForm) and the _target member variable after the colon (":").
 */
RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) :
    AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

/* 
    Destructor.
 */
RobotomyRequestForm::~RobotomyRequestForm() {
}

/* 
    The copy constructor derived from the base class. 
    "AForm(other)" calls the copy constructor from the base class. 
    "_target(other._target)" copies the the _target of the derived class. 
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other), _target(other._target) {
}

/* 
    Preventing assigment as the member variables are constants.
 */
RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
    return *this;
}

void    RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
    int i;

    if (this->getSigned() == false)
        throw AForm::FormNotSigned();
    else if (this->getExecGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "DrrDrrrDrrrrrr.... ";
        if (i % 2 == 0)
            std::cout << this->_target << " is robotomized" << std::endl;
        else
            std::cout << "Robotomy has failed ... " << std::endl;
    }
}