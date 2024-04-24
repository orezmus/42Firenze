#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){

}

MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource() {

}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy){
    if (this != &copy)
        IMateriaSource::operator=(copy);
    return (*this);
}

MateriaSource::~MateriaSource(){

}

    