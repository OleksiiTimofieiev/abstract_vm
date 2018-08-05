/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:58:03 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/05 21:58:04 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <exception>
#include <string>

#define throw_line(arg, line) throw Exception(arg, line);

class Exception : public std::runtime_error
{
	std::string 					_msg;
	std::string 					_result;
	int 							_line;

  public:
	Exception();
	~Exception() 					throw();
	Exception &operator =			( Exception const &rhs );
	Exception						( Exception const &src );
	Exception						( const std::string &arg, int line );
	const char *what() 				const throw();
};

#endif
