#include "Weapon.hpp"

Weapon::Weapon() {

}

Weapon::Weapon(std::string type) : type_(type) {

}

Weapon::~Weapon() {

}

const   std::string &Weapon::getType() {
    return type_;
}

void    Weapon::setType(std::string type) {
    this->type_ = type;
}
