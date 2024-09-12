#include "FordJohnson.hpp"

int main(int ac, char **av)
{
	if (ac < 3)
		return (std::cout << "need more numbers\n", 1);
	int i = 1;
	while (i < ac)
	{
		if (strcmp(av[i], "0"))
		{
			if (atoi(av[i]) <= 0)
				return (std::cout << "found a 'nan' or negative number, aborting...\n", 1);
		}
		i++;
	}
	FordJohnson fj(ac, av);
}
