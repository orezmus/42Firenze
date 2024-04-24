#include "Ice.hpp"

Ice::Ice () {
    type_ = "ice";
}

Ice::Ice(const Ice &copy) : AMateria() {
    type_ = copy.type_;
}

Ice& Ice::operator=(const Ice &copy) {
    if (this != &copy)
        AMateria::operator=(copy);
    return (*this);
}

Ice::~Ice() {

}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << &target << " *" << std::endl;

}