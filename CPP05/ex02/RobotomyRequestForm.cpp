/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:48:19 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/27 14:39:20 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	this->_target = copy._target;
	return *this;
}

void RobotomyRequestForm::Robotomize() const
{
	std::srand(std::time(NULL));
	std::cout << ((std::rand() & 2) ? "Misterious drilling noise" : (this->_target + " has been robotomized")) << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignStatus())
		throw FormNotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	this->Robotomize();
}