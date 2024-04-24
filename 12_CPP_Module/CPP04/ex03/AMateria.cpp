#include "AMateria.hpp"

AMateria::AMateria() {
}

AMateria::AMateria(std::string const &type) : type_(type) {
}

AMateria::AMateria(const AMateria &copy) {
    type_ = copy.type_;
}
AMateria& AMateria::operator=(const AMateria &copy) {
    type_ = copy.type_;
    return (*this);
}

AMateria::~AMateria() {
}

const std::string &AMateria::getType() const {
    return type_;
}

void AMateria::use(ICharacter &target){
    std::cout << "AMateria " << target.getName() << std::endl;
}
