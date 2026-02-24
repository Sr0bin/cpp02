/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:02:12 by rorollin          #+#    #+#             */
/*   Updated: 2026/02/24 15:06:56 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {} ;

Fixed::~Fixed()
{

}

Fixed::Fixed(const Fixed &fixed)
{
	_value = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fix)
{
	_value = fix.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}
