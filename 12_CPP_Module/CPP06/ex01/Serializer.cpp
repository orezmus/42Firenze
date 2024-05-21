#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer &copy) {
    static_cast<void>(copy);
}

Serializer& Serializer::operator=(const Serializer &copy) {
    if (this != &copy)
        static_cast<void>(copy);
    return (*this);
}

Serializer::~Serializer() {

}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
