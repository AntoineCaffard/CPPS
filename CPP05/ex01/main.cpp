/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:32:50 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/25 12:21:25 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << "\033[1;34mTEST : Form sign grade too high\033[0m" << std::endl;
		try
		{
			Form test ("test", -42, 12);
			std::cout << test;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Form exec grade too high\033[0m" << std::endl;
		try
		{
			Form test ("test", 42, -12);
			std::cout << test;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Form sign grade too low\033[0m" << std::endl;
		try
		{
			Form test ("test", 4002, 12);
			std::cout << test;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Form exec grade too low\033[0m" << std::endl;
		try
		{
			Form test ("test", 42, 1200);
			std::cout << test;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Form already Signed\033[0m" << std::endl;
		try
		{
			Bureaucrat John("John", 10);
			Bureaucrat Random("Random", 149);
			Form test ("test", 12, 12);
			John.signForm(test);
			Random.signForm(test);
			std::cout << test;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[1;34mTEST : Bureaucrat grade to low to sign\033[0m" << std::endl;
		try
		{
			Bureaucrat Random("Random", 149);
			Form test ("test", 12, 12);
			Random.signForm(test);
			std::cout << test;
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
			Bureaucrat Random("Random", 10);
			Form test ("test", 12, 12);
			Random.signForm(test);
			std::cout << test;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}