/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:32:50 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/27 16:25:32 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	// {
	// 	try
	// 	{
	// 		Bureaucrat John("John", 10);
	// 		// Bureaucrat Donald("Donald", -100);
	// 		// Bureaucrat Random("Random", 250);

	// 		// Bureaucrat Donald("Donald", 1);
	// 		// Donald.IncreaseGrade();

	// 		// Bureaucrat John("John", 10);
	// 		// Bureaucrat Random("Random", 150);
	// 		// Random.DecreaseGrade();

	// 		Bureaucrat Random("Random", 149);
	// 		Random.DecreaseGrade();
	// 		John.IncreaseGrade();

	// 		std::cout << John << Random;
	// 		// std::cout << Donald << std::endl;
	// 		// std::cout << Random << std::endl;
	// 	}
	// 	// catch(const std::exception& e)
	// 	// {
	// 	// 	std::cerr << e.what() << std::endl;
	// 	// }
	// }
	{
		try
		{
			Bureaucrat John("John", 1);
			Bureaucrat Random("Random", 149);
			RobotomyRequestForm wowo("Michel");
			PresidentialPardonForm wawa ("Robert");
			ShrubberyCreationForm wiwi("Jackie");
			Random.signForm(wowo);
			John.signForm(wowo);
			John.signForm(wawa);
			John.signForm(wiwi);
			Random.signForm(wawa);
			Random.executeForm(wawa);
			Random.executeForm(wowo);
			John.executeForm(wawa);
			John.executeForm(wowo);
			John.executeForm(wiwi);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}