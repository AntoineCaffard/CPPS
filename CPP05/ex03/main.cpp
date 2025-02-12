/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:32:50 by acaffard          #+#    #+#             */
/*   Updated: 2025/02/12 13:44:38 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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
		AForm *wowo;
		AForm *wawa;
		AForm *wiwi;
		try
		{
			Intern Maurice;
			wowo = Maurice.makeForm("robotomy request", "Michel");
			wawa = Maurice.makeForm("presidential pardon", "Robert");
			wiwi = Maurice.makeForm("shrubbery creation", "Jackie");
			// AForm *wewe = Maurice.makeForm("shrubberyfadsfaasasd creation", "Jackie");
			Bureaucrat John("John", 1);
			Bureaucrat Random("Random", 149);
			Random.signForm(*wowo);
			John.signForm(*wowo);
			John.signForm(*wawa);
			John.signForm(*wiwi);
			Random.signForm(*wawa);
			Random.executeForm(*wawa);
			Random.executeForm(*wowo);
			John.executeForm(*wawa);
			John.executeForm(*wowo);
			John.executeForm(*wiwi);
			// delete wewe;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete wowo;
		delete wawa;
		delete wiwi;
	}
}
