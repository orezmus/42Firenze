#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string name_;
    AMateria *slot_[4];
public:
    Character();
    Character(const std::string name_);
    Character(const Character &copy);
    Character &operator=(const Character &copy);
    ~Character();
    
    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif