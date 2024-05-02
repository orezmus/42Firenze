#include "Ice.hpp"

Ice::Ice () : AMateria("ice") {
}

Ice::Ice(std::string const &type) : AMateria(type) {
}

Ice::Ice(const Ice &copy) : AMateria(copy) {
	type_ = copy.type_;
}

Ice& Ice::operator=(const Ice &copy) {
	if (this != &copy)
	{
		AMateria::operator=(copy);
		type_ = copy.getType();
	}
	return (*this);
}

Ice::~Ice() {
}

AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

}
