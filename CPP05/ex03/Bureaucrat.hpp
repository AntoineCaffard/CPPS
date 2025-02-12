/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:22:08 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/27 13:37:37 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class AForm;

class Bureaucrat
{
	private :
		const std::string	_name;
		int					_grade;
		
	public :
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		virtual ~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &copy);
	public :
		std::string	getName() const;
		int			getGrade() const;
		void		IncreaseGrade();
		void		DecreaseGrade();
		void		signForm(AForm &form);
		void		executeForm(AForm const &form);
		
	public :
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Error : Grade is too High");
			};
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Error : Grade is too Low");
			};
		};	
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);