/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:58:25 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/05 21:58:26 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include "Parser.hpp"
#include "Exception.hpp"

class Lexer
{
	public:
		Lexer				( void );
		~Lexer				( void );

		bool				regex_checks( std::string str, std::vector<std::vector<std::string> > &_command_list );
		void				lexical_analysis( Parser &parser, std::vector<std::vector<std::string> > &_command_list );
};

#endif
