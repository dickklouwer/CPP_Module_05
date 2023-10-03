/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 08:12:42 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/28 10:57:08 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#ifndef AFORM_HPP
#define AFORM_HPP

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

std::ostream& operator<<(std::ostream &o, const AForm &f);

#endif