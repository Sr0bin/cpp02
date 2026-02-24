/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:02:12 by rorollin          #+#    #+#             */
/*   Updated: 2026/02/24 17:10:26 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <limits>

const int Fixed::_bpf = 8;

Fixed::Fixed() : _value(0) 
{
	std::cout << "Default Constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Default Destructor called\n";
}

Fixed::Fixed(const int val)
{
	setRawBits(val << _bpf);
}

Fixed::Fixed(const float val)
{
	float	rounded;

	rounded = roundf(val * (1 << _bpf));
	setRawBits(static_cast<int>(rounded));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy Constructor called\n";
	_value = fixed.getRawBits();
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(getRawBits()) / (1 << _bpf));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() / (1 << _bpf));
}

std::ostream	&operator<<(std::ostream &os, const Fixed &Fixed)
{
	return (os << Fixed.toFloat());
}
Fixed &Fixed::operator=(const Fixed &fix)
{
	std::cout << "Copy Assignement operator called\n";
	_value = fix.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called\n";
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called\n";
	_value = raw;
}
