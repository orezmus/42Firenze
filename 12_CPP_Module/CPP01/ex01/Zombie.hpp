#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string name_;

    public:
        Zombie();
        Zombie(std::string name);
        void    announce(void);
        void    setName(std::string name);
        ~Zombie();

};

Zombie *zombieHorde(int N, std::string name);

#endif
