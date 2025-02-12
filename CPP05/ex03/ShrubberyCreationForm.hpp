/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:37:15 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/27 15:39:13 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string _target;
		void		Draw(std::ostream &o) const;
	public :
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	
	public :
		void	execute(Bureaucrat const &executor) const;
};