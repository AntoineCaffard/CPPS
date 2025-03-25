/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:32:50 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/25 12:37:10 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		std::cout << "\033[1;34mTEST : Can't exec because form not signed\033[0m" << std::endl;
		try
		{
			Bureaucrat random("Random", 149);
			PresidentialPardonForm pardon("Leon Kums");
			random.executeForm(pardon);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Can't exec because grade too low\033[0m" << std::endl;
		try
		{
			Bureaucrat donald("Donald", 1);
			Bureaucrat random("Random", 149);
			RobotomyRequestForm xify("Leon Kums");
			donald.signForm(xify);
			random.executeForm(xify);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Pardon no errors\033[0m" << std::endl;
		try
		{
			Bureaucrat doland("Doland", 1);
			
			PresidentialPardonForm pardon("Leon Kums");
			doland.signForm(pardon);
			doland.executeForm(pardon);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Robotomy no errors\033[0m" << std::endl;
		try
		{
			Bureaucrat doland("Doland", 1);
			
			RobotomyRequestForm xify("Leon Kums");
			doland.signForm(xify);
			doland.executeForm(xify);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Shrubbery no errors\033[0m" << std::endl;
		try
		{
			Bureaucrat doland("Doland", 1);
			
			ShrubberyCreationForm declassify("Leon_Kums");
			doland.signForm(declassify);
			doland.executeForm(declassify);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}