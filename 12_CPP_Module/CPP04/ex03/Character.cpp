#include "Character.hpp"

Character::Character() {
    for (int i = 0; i < 4; i++)
        slot_[i] = NULL; 
}

Character::Character(const std::string name) : name_(name) {
    for (int i = 0; i < 4; i++)
        slot_[i] = NULL; 
}

Character::Character(const Character &copy) : name_(copy.getName()) {
    for (int i = 0; i < 4; i++)
    {
        slot_[i] = NULL;
        if (copy.slot_[i])
            slot_[i] = copy.slot_[i]->clone();
    }
}

Character& Character::operator=(const Character &copy){
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (slot_[i]) 
            {
                delete slot_[i];
                slot_[i] = NULL;
            }
            if (copy.slot_[i])
                slot_[i] = copy.slot_[i]->clone();
        }
    }
    return (*this);
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
    {
        if (slot_[i]) 
        {
            delete slot_[i];
            slot_[i] = NULL;
        }
    }
}
    
const std::string& Character::getName() const {
    return name_;
}

void Character::equip(AMateria *m) {
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!slot_[i])
        {
            slot_[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx > 3 || idx < 0)
        return ;
    delete slot_[idx];
    slot_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx > 3 || idx < 0 || !slot_[idx])
        return ;
    slot_[idx]->use(target);
}
