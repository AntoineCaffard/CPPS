/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:47:14 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/27 14:21:02 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string	_target;
		void	Robotomize() const;
	public :
		RobotomyRequestForm(const std::string &name);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	
	public :
		void	execute(Bureaucrat const &executor) const;
};