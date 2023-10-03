/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 10:24:45 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/27 08:49:13 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat(const std::string &name, int grade );
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=( const Bureaucrat& other);
        ~Bureaucrat();
        
        std::string     getName() const;
        int             getGrade() const;
        
        void            incrementGrade();
        void            decrementGrade();

    class GradeTooHighException : public std::exception {
        public: 
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public: 
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat &b);

#endif