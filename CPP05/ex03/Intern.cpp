/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:51:17 by acaffard          #+#    #+#             */
/*   Updated: 2025/02/12 12:51:17 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern::~Intern()
{}

Intern &Intern::operator=(const Intern &copy)
{
	(void) copy;
	return *this;
}

AForm	*Intern::makeForm(const std::string &form_type, const std::string &form_target)
{
	if (form_type == "presidential pardon")
		return new PresidentialPardonForm(form_target);
	if (form_type == "robotomy request")
		return new RobotomyRequestForm(form_target);
	if (form_type == "shrubbery creation")
		return new ShrubberyCreationForm(form_target);
	throw UnknownFormTypeException();
}
