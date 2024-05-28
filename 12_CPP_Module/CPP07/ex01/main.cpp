#include "iter.hpp"
#include <string>


int main(void)
{
	char carr[5] = { 'a', 'b', 'c', 'd', 'e' };
	int iarr[5] = { 1, 2, 3, 4, 5 };
	float farr[5] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
	std::string sarr[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

	std::cout << "============Char Array===========" << std::endl;
	iter(carr, 5, print);
	std::cout << "============Int Array============" << std::endl;
	iter(iarr, 5, print);
	std::cout << "============Float Array============" << std::endl;
	iter(farr, 5, print);
	std::cout << "============String Array============" << std::endl;
	iter(sarr, 5, print);
}
