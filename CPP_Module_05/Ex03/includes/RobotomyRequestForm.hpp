/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:02:29 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/10/04 12:53:21 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>

/* 
    The assignment operator is declared private because the class has constant 
    member variables, which cannot be reassigned after initialization. The copy 
    constructor is also declared private to prevent copying, making sure the 
    class's constant values don't change.
 */
class RobotomyRequestForm : public AForm {
    private:
        const std::string   _target;

        RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
        RobotomyRequestForm( const RobotomyRequestForm& other );

    public:
        RobotomyRequestForm( const std::string& target );
        ~RobotomyRequestForm();

        void    execute ( const Bureaucrat& executor ) const;
};

#endif
