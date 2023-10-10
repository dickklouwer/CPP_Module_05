/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 08:12:42 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/10/10 09:42:00 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		AForm(void);
		AForm(const std::string name, const int signGrade, const int execGrade);
		~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		std::string		getName() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		
		void			beSigned(Bureaucrat& b);
		void			signForm(const Bureaucrat& b);

		virtual void			execute(const Bureaucrat& executor) const = 0;

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

	class FormNotSigned : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &o, const AForm &f);

#endif