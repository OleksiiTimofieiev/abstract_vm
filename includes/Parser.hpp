/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:58:29 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/05 21:58:30 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Parser_HPP
#define Parser_HPP

#include <iostream>
#include <fstream>
#include <list>

class	Parser
{
	friend	class Lexer;

	private:
		std::list<std::string>		_filtered_input;
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
};

#endif
