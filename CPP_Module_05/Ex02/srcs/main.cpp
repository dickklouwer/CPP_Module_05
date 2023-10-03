/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 10:24:48 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/27 09:18:13 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

int     main() 
{
    try
    {
        Bureaucrat  bureaucrat("Dick", 11);
        Form        form("firstForm", 10, 10);
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        form.beSigned(bureaucrat);
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