/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 10:24:48 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/10/10 09:44:14 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int     main() 
{
    try
    {
        Bureaucrat  bureaucrat("Dick", 30);
        ShrubberyCreationForm scFrom("Shrubbery");
        RobotomyRequestForm rrForm("Robotomy");
        PresidentialPardonForm ppForm("PresidentialPardon");

        std::cout << bureaucrat << std::endl;
        std::cout << scFrom << std::endl;

        scFrom.beSigned(bureaucrat);
        bureaucrat.executeForm(scFrom);

        std::cout << "\n-------- Robotomy Form" << std::endl;
        std::cout << rrForm << std::endl;

        rrForm.beSigned(bureaucrat);
        bureaucrat.executeForm(rrForm);

        std::cout << "\n-------- Presidential Pardon Form" << std::endl;
        std::cout << ppForm << std::endl;

        ppForm.beSigned(bureaucrat);
        bureaucrat.executeForm(ppForm);
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}