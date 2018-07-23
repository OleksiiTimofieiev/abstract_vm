#ifndef	CPU_HPP
#define CPU_HPP

#include "Parser.hpp"

class	CPU
{
	private:
		Parser _parser;
	public:
		CPU							( void );
		~CPU						( void );

		void execute_inner_logic( const int quantity_of_arguments, char *argument );
};

















#endif
