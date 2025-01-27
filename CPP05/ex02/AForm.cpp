/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:03:20 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/27 12:02:24 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _is_signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{}

AForm::AForm(const AForm &copy) : _name(copy._name), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade), _is_signed(copy._is_signed)
{}

AForm &AForm::operator=(const AForm &copy)
{
	const_cast<std::string&>(_name) = copy._name;
	_is_signed = copy._is_signed;
	const_cast<int&>(_sign_grade) = copy._sign_grade;
	const_cast<int&>(_exec_grade) = copy._exec_grade;
	return *this;
}

std::string	AForm::getName() const
{
	return _name;
}

int	AForm::getSignGrade() const
{
	return _sign_grade;
}

int	AForm::getExecGrade() const
{
	return _exec_grade;
}

bool	AForm::getSignStatus() const
{
	return _is_signed;
}

void	AForm::print(std::ostream &o)
{
	o << "AForm " << _name << " : sign_grade = " << _sign_grade << ", exec_grade = " << _exec_grade;
	if (_is_signed)
		o << " signed" << std::endl;
	else
		o << " unsigned" << std::endl;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_is_signed)
		throw FormAlreadySignedException();
	if (this->_sign_grade < bureaucrat.getGrade())
		throw GradeTooLowException();
	_is_signed = true;
}

std::ostream &operator<<(std::ostream &o, AForm &aform)
{
	aform.print(o);
	return o;
}