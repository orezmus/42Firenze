#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(std::string const &type) : AMateria(type) {
}

Cure::Cure(const Cure &copy) : AMateria(copy) {
    type_ = copy.getType();
}

Cure& Cure::operator=(const Cure &copy) {
    if (this != &copy)
    {
        AMateria::operator=(copy);
        type_ = copy.getType();
    }
    return (*this);
}

Cure::~Cure() {
}

AMateria *Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << &target << "'s wound *" << std::endl;
}