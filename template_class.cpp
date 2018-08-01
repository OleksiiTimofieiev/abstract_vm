#include "eOperand.hpp"
#include "IOperand.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include "Factory.hpp"


int main(void)
{

	eOperand <char> a("65");
	eOperand <char> b("67");

	// std::cout << "Precision -> " << a.getPrecision() << std::endl;
	// std::cout << "Type -> " << a.getType() << std::endl;
	// std::cout << "String representation -> " << a.toString() << std::endl;

	// std::cout << "Precision -> " << b.getPrecision() << std::endl;
	// std::cout << "Type -> " << b.getType() << std::endl;
	// std::cout << "String representation -> " << b.toString() << std::endl;

	// const IOperand  *c = a + b;

	// std::cout << "Precision -> " << c->getPrecision() << std::endl;
	// std::cout << "Type -> " << c->getType() << std::endl;
	// std::cout << "String representation -> " << c->toString() << std::endl;

	// add some vector stuff;

	std::vector<IOperand const*> vars;

	Factory omega;

	vars.push_back(omega.createOperand(Float, "123654.67"));

	std::cout << vars[0]->toString() << std::endl;

	system("leaks -q a.out");

	return (0);
}
