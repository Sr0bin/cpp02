/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:02:12 by rorollin          #+#    #+#             */
/*   Updated: 2026/02/24 18:52:49 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <limits>

const int Fixed::_bpf = 8;

bool	Fixed::operator==(const Fixed &fix) const
{
	if (this->getRawBits() == fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &fix) const
{
	if ((this->getRawBits()) > (fix.getRawBits()))
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &fix) const
{
	return (!(*this==fix));
}

bool	Fixed::operator>=(const Fixed &fix) const
{
	return (*this > fix || *this == fix);
}

bool	Fixed::operator<(const Fixed &fix) const
{
	return (*this != fix && !(*this > fix));
}

bool	Fixed::operator<=(const Fixed &fix) const
{
	return (*this == fix || *this < fix);
}

Fixed	Fixed::operator+(const Fixed &fix) const
{
	long long result;

	result = this->getRawBits() + fix.getRawBits();
	if (result > std::numeric_limits<int>::max())
	{
		Fixed temp;
		temp.setRawBits(std::numeric_limits<int>::max());
		return (temp);
	}
	if (result > std::numeric_limits<int>::min())
	{
		Fixed temp;
		temp.setRawBits(std::numeric_limits<int>::min());
		return (temp);
	}
	Fixed temp;
	temp.setRawBits(static_cast<int>(result));
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &fix) const;
Fixed	Fixed::operator*(const Fixed &fix) const;
Fixed	Fixed::operator/(const Fixed &fix) const;

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
