/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 10:24:48 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/10/03 14:24:35 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int     main() 
{
    try
    {
        Bureaucrat  bureaucrat("Dick", 11);
        ShrubberyCreationForm form1("Shrubbery");
        
        std::cout << bureaucrat << std::endl;
        // std::cout << form << std::endl;

        // bureaucrat.
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}