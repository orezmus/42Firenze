#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Ice : public AMateria {
public:
    Ice();
    Ice(std::string const &type);
    Ice(const Ice &copy);
    Ice &operator=(const Ice &copy);
    ~Ice();
    
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif