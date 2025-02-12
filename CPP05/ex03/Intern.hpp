/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:51:22 by acaffard          #+#    #+#             */
/*   Updated: 2025/02/12 12:51:22 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public :
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(const Intern &copy);

		AForm	*makeForm(const std::string &form_type, const std::string &form_target);

		class UnknownFormTypeException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Form type is unknown");
			};
		};
};
