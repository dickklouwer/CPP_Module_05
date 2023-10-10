/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:58:17 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/10/04 12:58:49 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

/* 
    The assignment operator is declared private because the class has constant 
    member variables, which cannot be reassigned after initialization. The copy 
    constructor is also declared private to prevent copying, making sure the 
    class's constant values don't change.
 */
class PresidentialPardonForm : public AForm {
    private:
        const std::string   _target;

        PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
        PresidentialPardonForm( const PresidentialPardonForm& other );

    public:
        PresidentialPardonForm( const std::string& target );
        ~PresidentialPardonForm();

        void    execute ( const Bureaucrat& executor ) const;
};

#endif
