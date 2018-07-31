#include "eOperand.hpp"


int main(void)
{

	eOperand <double> c("1234578910123123123");

	std::cout << "Precision -> " << c.getPrecision() << std::endl;
	std::cout << "Type -> " << c.getType() << std::endl;
	std::cout << "String representation -> " << c.toString() << std::endl;
}
