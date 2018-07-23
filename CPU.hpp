#ifndef CPU_HPP
#define CPU_HPP

#include <iostream>
#include <list>

class	CPU
{
	public:
		// object construction section;
		CPU		( void );
		~CPU	( void );

		// read section;
		bool	detect_input_stream( const int quantity_of_arguments ) const;
		void	read_from_the_standart_input( void );
		void	read( const int quantity_of_arguments );

		// finalisation;
		void	detect_leaks( void );
};

#endif
