#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
    private:
        std::string name_;

    public:
        Zombie();
        Zombie(std::string name);
        void	announce(void);
        ~Zombie();
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif
