/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:32:50 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/25 12:38:52 by acaffard         ###   ########.fr       */
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
	{
		AForm *wowo;
		AForm *wawa;
		AForm *wiwi;
		// AForm *wewe;
		try
		{
			Intern Maurice;
			wowo = Maurice.makeForm("robotomy request", "Michel");
			wawa = Maurice.makeForm("presidential pardon", "Robert");
			wiwi = Maurice.makeForm("shrubbery creation", "Jackie");
			// wewe = Maurice.makeForm("shrubberyfadsfaasasd creation", "Jackie");
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
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete wowo;
		delete wawa;
		delete wiwi;
		// delete wewe;
	}
}
