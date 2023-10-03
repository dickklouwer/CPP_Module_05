/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 08:12:42 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/27 09:16:35 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#ifndef FORM_HPP
#define FORM_HPP

class Form 
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form(void);
		Form(const std::string name, const int signGrade, const int execGrade);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		std::string		getName() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		
		void			beSigned(Bureaucrat& b);
		void			signForm(Bureaucrat& b);

	class GradeTooHighException : public std::exception 
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &o, const Form &f);

#endif