#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name){
    if (N <= 0)
    {
        std::cout << "Number is invalid" << std::endl;
        return (NULL);
    }
    Zombie *zombies = new(std::nothrow) Zombie[N];
    if (!zombies)
        return (NULL);
    for (int i = 0; i < N; i++)
        zombies[i].setName(name);
    return zombies;
}