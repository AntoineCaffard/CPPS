/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:37:31 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/27 16:24:22 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->_target = copy._target;
	return *this;
}

void ShrubberyCreationForm::Draw(std::ostream &o) const
{
	o << "     *     " << std::endl;
	o << "    ***    " << std::endl;
	o << "   *****   " << std::endl;
	o << "  *******  " << std::endl;
	o << " ********* " << std::endl;
	o << "***********" << std::endl;
	o << "    ***    " << std::endl << std::endl;
	
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignStatus())
		throw FormNotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	std::ofstream out;
	out.open((_target + ((std::string)"_shrubbery")).c_str());
	if (!out)
		throw FailOpenException();
	for (int i = 0; i < 10; ++i)
		this->Draw(out);
	out.close();
}