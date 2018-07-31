#include "eOperand.hpp"


int main(void)
{

	eOperand <char> c("65");
	eOperand <size_t> b("67");

	std::cout << "Precision -> " << c.getPrecision() << std::endl;
	std::cout << "Type -> " << c.getType() << std::endl;
	std::cout << "String representation -> " << c.toString() << std::endl;

	std::cout << "Precision -> " << b.getPrecision() << std::endl;
	std::cout << "Type -> " << b.getType() << std::endl;
	std::cout << "String representation -> " << b.toString() << std::endl;
}
