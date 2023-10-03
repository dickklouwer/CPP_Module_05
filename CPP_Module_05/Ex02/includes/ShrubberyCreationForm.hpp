/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 10:58:31 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/28 11:45:20 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

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
        ShrubberyCreationForm( std::string& target );
        ~ShrubberyCreationForm(); 
};








#endif