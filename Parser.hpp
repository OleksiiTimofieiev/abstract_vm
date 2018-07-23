#ifndef Parser_HPP
#define Parser_HPP

#include <iostream>
#include <fstream>
#include <list>

class	Parser
{
	private:
		std::list<std::string>	_filtered_input;
	public:
		// object construction section;
		Parser						( void );
		~Parser						( void );
		Parser &operator =			( Parser const &rhs );
		Parser						( Parser const &src );

		// read section;
		bool						detect_input_stream( const int quantity_of_arguments ) const;
		void						read_from_the_standart_input( void );
		void 						read_from_the_ifstream(char * argument);
		void 						read(const int quantity_of_arguments, char * argument);

		// infrastructure;
		void						print_list( void );
		void						detect_leaks( void );
};

#endif
