/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:05:12 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/10/04 14:38:30 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern &Intern::operator=(const Intern& other)
{
    (void) other;
    return (*this);
}

AForm*      Intern::makeForm(std::string form, std::string target)
{
    int i = 0;

    std::string formNames[] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
    for (int i = 0; i < 3; ++i)
    {
        if (form == formNames[i])
        {
            switch(i)
            {
                case 0: 
                    std::cout << "Intern creates " << formNames[i] << std::endl;
                    return new PresidentialPardonForm(target);
                case 1:
                    std::cout << "Intern creates " << formNames[i] << std::endl; 
                    return new ShrubberyCreationForm(target);
                case 2:
                    std::cout << "Intern creates " << formNames[i] << std::endl;
                    return new RobotomyRequestForm(target);
            }
        }
        else
        {
            std::cerr << "Intern failed to make Form as it doesn't exist ..." << std::endl;
            return NULL;
        }
    }
    std::cerr << "Intern failed to make Form as it doesn't exist ..." << std::endl;
    return NULL;
}
