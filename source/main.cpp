/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:57:29 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/06 03:30:44 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/CPU.hpp"

int		main ( int argc, char ** argv ) { CPU()._execute_inner_logic( argc, argv[1] ); return (0); }
