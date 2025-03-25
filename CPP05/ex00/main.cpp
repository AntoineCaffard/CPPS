/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:32:50 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/25 12:11:27 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\033[1;34mTEST : Grade too high\033[0m" << std::endl;
		try
		{
			Bureaucrat John("John", 10);
			Bureaucrat Donald("Donald", -100);
			std::cout << John << Donald << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Grade too low\033[0m" << std::endl;
		try
		{
			Bureaucrat John("John", 10);
			Bureaucrat Random("Random", 250);
			std::cout << John << Random << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Grade too high by increasing\033[0m" << std::endl;
		try
		{
			Bureaucrat John("John", 10);
			Bureaucrat Donald("Donald", 1);
			Donald.IncreaseGrade();
			std::cout << John << Donald << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Grade too low by decreasing\033[0m" << std::endl;
		try
		{
			Bureaucrat John("John", 10);
			Bureaucrat Random("Random", 250);
			Random.DecreaseGrade();
			std::cout << John << Random << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : No errors\033[0m" << std::endl;
		try
		{
			Bureaucrat John("John", 10);
			Bureaucrat Random("Random", 149);
			Random.DecreaseGrade();
			John.IncreaseGrade();
			std::cout << John << Random;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}