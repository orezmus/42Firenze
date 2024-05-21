#include "Serializer.hpp"

int		main(void)
{
	// Create a Data object
    Data originalData;
    originalData.id = 42;
    originalData.name = "Test Name";
    originalData.value = 3.14;

	std::cout << "Original Data Address: " << &originalData << std::endl;
	std::cout << "Original Data ID: " << originalData.id << std::endl;
    std::cout << "Original Data Name: " << originalData.name << std::endl;
    std::cout << "Original Data Value: " << originalData.value << std::endl;
    std::cout << std::endl;

    // Serialize the Data object pointer
    uintptr_t serializedData = Serializer::serialize(&originalData);
    std::cout << "Serialized Data Address: " << serializedData << std::endl;
    std::cout << std::endl;

    // Deserialize the serialized data
    Data* deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized Data Address = " << deserializedData << std::endl;
    std::cout << "Deserialized Data ID: " << deserializedData->id << std::endl;
    std::cout << "Deserialized Data Name: " << deserializedData->name << std::endl;
    std::cout << "Deserialized Data Value: " << deserializedData->value << std::endl;
    std::cout << std::endl;
    
    // Check if the original pointer and deserialized pointer are the same
    if (deserializedData == &originalData)
        std::cout << "Success: The deserialized pointer matches the original pointer." << std::endl;
    else
        std::cout << "Error: The deserialized pointer does not match the original pointer." << std::endl;

    return (0);
}