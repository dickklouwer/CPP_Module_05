/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:05:07 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/10/10 09:42:50 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    private:

    public:
        Intern(void);
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

        AForm*       makeForm(const std::string name, const std::string target);
};

#endif