/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:54:03 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/27 12:04:55 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class	Bureaucrat;

class Form
{
	private :
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
		bool				_is_signed;
	public :
		Form(const std::string &name, int sign_grade, int exec_grade);
		Form(const Form &copy);
		virtual ~Form();
		Form &operator=(const Form &copy);
	public :
		void		print(std::ostream &o);
		int			getSignGrade() const ;
		int			getExecGrade() const;
		bool		getSignStatus() const;
		void		beSigned(const Bureaucrat &bureaucrat);
		std::string	getName() const;
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
				return ("this form is already signed");
			};
		};	
};

std::ostream& operator<<(std::ostream &o, Form &form);