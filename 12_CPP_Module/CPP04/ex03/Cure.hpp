#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Cure : public AMateria {
private:
    std::string type_;
public:
    Cure();
    Cure(const Cure &copy);
    Cure &operator=(const Cure &copy);
    ~Cure();

    Cure *clone() const;
    void use(ICharacter &target);
};

#endif