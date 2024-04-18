#include "Harl.hpp"

int	main(int ac, char **av)
{
    Harl    harl;

    if (ac != 2)
        std::cout << "Argumente Error" << std::endl;
    else
        harl.complain(av[1]);
    return 0;
}