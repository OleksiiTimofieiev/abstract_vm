#ifndef 	CPU_HPP
#define 	CPU_HPP

#include	<iostream>

class	CPU
{
	private:
		std::string	_input;
	public:
		CPU		( void );
		~CPU	( void );
		bool	detect_input_stream( void );
};

#endif
