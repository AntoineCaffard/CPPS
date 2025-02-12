/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:54:03 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/27 12:21:39 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class	Bureaucrat;

class AForm
{
	private :
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
		bool				_is_signed;


	// CANONICAL FORM //
	public :
		AForm(const std::string &name, int sign_grade, int exec_grade);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm &operator=(const AForm &copy);

	// METHODS //
	public :
		void			print(std::ostream &o);
		std::string		getName() const;
		int				getSignGrade() const ;
		int				getExecGrade() const;
		bool			getSignStatus() const;
		void			beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;


	// EXCEPTIONS //
	public :
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Grade is too High");
			};
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Grade is too Low");
			};
		};
		class FormAlreadySignedException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("this Form is already signed");
			};
		};
		class FormNotSignedException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("this Form is not signed");
			};
		};
		class FailOpenException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Failed to open file");
			};
		};	
};

std::ostream& operator<<(std::ostream &o, AForm &AForm);