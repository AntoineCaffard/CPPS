/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:34:26 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/10 08:54:51 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringModifier.hpp"

int	parse(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error : Bad Argument Number" << std::endl;
		return 0;
	}
	if (((std::string) av[1]).empty() || ((std::string) av[2]).empty())
	{
		std::cerr << "Error : Empty Argument" << std::endl;
		return 0;
	}
	return 1;
}

int	mySed(int ac, char **av)
{
	if (!parse(ac, av))
		return (1);
	std::string		line;
	std::string		file_content = "";
	std::ifstream	opened_file(av[1]);
	if (!opened_file)
	{
		std::cerr << "Error : Failed to open given file" << std::endl;
		return 1;
	}
	while (std::getline(opened_file, line))
		file_content.append(line + "\n");
	opened_file.close();
	std::ofstream new_file;
	new_file.open((((std::string)av[1])+ ".replace").c_str());
	if (!new_file)
	{
		std::cerr << "Error : Failed to open "<< (((std::string)av[1])+ ".replace") << std::endl;
		return 1;
	}
	StringModifier	test(file_content, av[2], av[3]);
	test.modify();
	new_file << test.getModifiedString();
	new_file.close();
	return 0;
}

int	main(int ac, char **av)
{
	return (mySed(ac, av));
}
