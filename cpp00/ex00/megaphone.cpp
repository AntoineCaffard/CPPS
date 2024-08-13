#include <iostream>
#include <string>

void printUppercase(int ac, char **av)
{
	std::string to_print;
	to_print = av[1];
	for (int i = 2; i <= ac - 1; i++)
		to_print.append(av[i]);
	for (int i = 0; i < to_print.length(); i++)
	{
		if (to_print[i] >= 'a' && to_print[i] <= 'z')
			to_print[i] -= 'a' - 'A';
	}
	std::cout << to_print << std::endl;
}

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		printUppercase(ac, av);
	return (0);
}
