/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:58:10 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/05 21:58:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
#define	FACTORY_HPP

#include "eOperand.hpp"
#include <vector>
#include <limits>

class	Factory
{
	public:
		Factory( void );
		~Factory( void );
		Factory &operator=(Factory const &rhs);
		Factory(Factory const &src);
		IOperand const *createOperand(eOperandType type, std::string const &value) const;
  	private:
		IOperand const *createInt8(std::string const &value) const;
	  	IOperand const *createInt16(std::string const &value) const;
	  	IOperand const *createInt32(std::string const &value) const;
		IOperand const *createFloat(std::string const &value) const;
		IOperand const *createDouble(std::string const &value) const;

		std::vector<IOperand const *(Factory::*)(std::string const &value) const> _vFunc;
};

#endif
