#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice &copy);
    Ice &operator=(const Ice &copy);
    ~Ice();
    
    Ice *clone() const;
    void use(ICharacter &target);
};

#endif