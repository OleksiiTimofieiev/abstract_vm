#include "eOperand.hpp"


int main(void)
{

	eOperand <int> c("12345");

	std::cout << "Precision -> " << c.getPrecision() << std::endl;
	std::cout << "Type -> " << c.getType() << std::endl;
	std::cout << "String representation -> " << c.toString() << std::endl;
}
