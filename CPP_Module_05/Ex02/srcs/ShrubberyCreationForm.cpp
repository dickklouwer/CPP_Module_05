/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 11:05:47 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/28 11:45:12 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

/*
    Declaring the constructor for the ShrubberyCreation form which is derived from
    the abstract class AForm. The member initialization list initializes the base
    class (AForm) and the _target member variable after the colon (":").
 */
ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : 
    AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

/* 
    Destructor.
 */
ShrubberyCreationForm::~ShrubberyCreationForm() {
}

/* 
    The copy constructor derived from the base class. 
    "AForm(other)" calls the copy constructor from the base class. 
    "_target(other._target)" copies the the _target of the derived class. 
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other), _target(other._target) {
}

/* 
    Preventing assigment as the member variables are constants.
 */
ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
    return *this;
}