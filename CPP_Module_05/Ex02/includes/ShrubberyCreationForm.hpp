/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 10:58:31 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/10/03 14:17:48 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

/* 
    The assignment operator is declared private because the class has constant 
    member variables, which cannot be reassigned after initialization. The copy 
    constructor is also declared private to prevent copying, making sure the 
    class's constant values don't change.
 */
class ShrubberyCreationForm : public AForm {
    private:
        const std::string   _target;

        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
        ShrubberyCreationForm( const ShrubberyCreationForm& other );

    public:
        ShrubberyCreationForm( const std::string& target );
        ~ShrubberyCreationForm();

        void    execute ( const Bureaucrat& B ) const;
};








#endif