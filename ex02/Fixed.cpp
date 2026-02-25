/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:02:12 by rorollin          #+#    #+#             */
/*   Updated: 2026/02/25 15:49:26 by rorollin         ###   ########.fr       */
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

int	Fixed::setClampRawBits(long long result)
{
	if (result > std::numeric_limits<int>::max())
		return (std::numeric_limits<int>::max());
	if (result < std::numeric_limits<int>::min())
		return (std::numeric_limits<int>::min());
	return (result);
}
Fixed	Fixed::operator+(const Fixed &fix) const
{
	long long result;

	result = this->getRawBits() + fix.getRawBits();
	result = setClampRawBits(result);
	Fixed temp;
	temp.setRawBits(static_cast<int>(result));
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &fix) const
{
	long long result;

	result = this->getRawBits() - fix.getRawBits();
	result = setClampRawBits(result);
	Fixed temp;
	temp.setRawBits(static_cast<int>(result));
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &fix) const
{
	long long result;

	result = (this->getRawBits() * fix.getRawBits()) >> _bpf;
	result = setClampRawBits(result);
	Fixed temp;
	temp.setRawBits(static_cast<int>(result));
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &fix) const
{ long long result;

	result = ((static_cast<long long>(this->getRawBits()) << _bpf) / fix.getRawBits());
	result = setClampRawBits(result);
	Fixed temp;
	temp.setRawBits(static_cast<int>(result));
	return (temp);
}

Fixed	&Fixed::operator++()
{
	++_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	&Fixed::operator--()
{
	--_value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}
const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}
Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}
const Fixed	&Fixed::max(const Fixed &f1,const Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed::Fixed() : _value(0) 
{
	// std::cout << "Default Constructor called\n";
}

Fixed::~Fixed()
{
	// std::cout << "Default Destructor called\n";
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
	// std::cout << "Copy Constructor called\n";
	_value = fixed.getRawBits();
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(getRawBits()) / (1 << _bpf));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> _bpf);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &Fixed)
{
	return (os << Fixed.toFloat());
}
Fixed &Fixed::operator=(const Fixed &fix)
{
	// std::cout << "Copy Assignement operator called\n";
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
