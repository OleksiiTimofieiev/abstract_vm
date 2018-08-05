/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:57:29 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/05 21:57:30 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/CPU.hpp"

int		main2 ( int argc, char ** argv )
{
	CPU _cpu;

	_cpu._execute_inner_logic( argc, argv[1] );

	return (0);
}

int		main( int argc, char ** argv )
{
	main2(argc, argv);
	system("leaks -q avm");
	return (0);
}
