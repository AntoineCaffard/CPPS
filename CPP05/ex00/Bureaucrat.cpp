/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:29 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/23 12:45:13 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->setName(copy.getName());
	_grade = copy.getGrade();
	return *this;
}

void	Bureaucrat::setName(const std::string &name)
{
	const_cast<std::string&>(_name) = name;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::IncreaseGrade()
{
	if (this->_grade - 1 < 1)
		throw (GradeTooHighException());
	this->_grade -= 1;
}

void	Bureaucrat::DecreaseGrade()
{
	if (this->_grade + 1 > 150)
		throw (GradeTooLowException());
	this->_grade += 1;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade : " << bureaucrat.getGrade() << std::endl;
	return o;
}







