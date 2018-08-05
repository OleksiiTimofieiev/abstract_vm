/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:57:52 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/05 21:57:53 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CPU_HPP
# define CPU_HPP

#include "includes.hpp"

/* ********************* core class ********************* */

class	CPU
{
	private:
		Parser 									_parser;
		Lexer 									_lexer;
		Factory									_factory;			
		std::vector<std::vector<std::string> > 	_command_list;
		std::vector<IOperand const *> 			_stack;
		void _commands_execution_routine		( void );

	public:
		/* ********************* object construction ********************* */

		CPU										( void );
		~CPU									( void );
		CPU &operator =							( CPU const &rhs );
		CPU										( CPU const &src );
		
		/* ********************* funcs ********************* */

		void _push								( std::string Type, std::string value);
		void _pop								( int line );
		void _dump								( int line  );
		void _add								( int line );
		void _sub								( int line );
		void _mul								( int line );
		void _div								( int line );
		void _mod								( int line );
		void _print								( int line );
		void _assert							( std::string Type, std::string value, int line );
		void _more								( std::string Type, std::string value, int line );
		void _lesser							( std::string Type, std::string value, int line );
		void _not_equal							( std::string Type, std::string value, int line );
		void _more_or_equal							( std::string Type, std::string value, int line );
		void _exit								( void );
		void _execute_inner_logic				( const int quantity_of_arguments, char * argument );
};

#endif
