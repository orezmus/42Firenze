#include "Cure.hpp"

Cure::Cure() {
    type_ = "cure";

}

Cure::Cure(const Cure &copy) : AMateria(copy) {

}

Cure& Cure::operator=(const Cure &copy) {
    if (this != &copy)
    {
        AMateria::operator=(copy);
    }
    return (*this);
}

Cure::~Cure() {

}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << &target << "'s wound *" << std::endl;
    
}