/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:02:02 by rorollin          #+#    #+#             */
/*   Updated: 2026/02/25 15:53:20 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>
class Fixed
{
private:
	int	_value;
	static const int _bpf;
	static	int setClampRawBits(long long result);
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int val);
	Fixed(const float val);

	~Fixed();
	Fixed	&operator=(const Fixed &fix);
	bool	operator==(const Fixed &fix) const;
	bool	operator>(const Fixed &fix) const;
	bool	operator!=(const Fixed &fix) const;
	bool	operator>=(const Fixed &fix) const;
	bool	operator<=(const Fixed &fix) const;
	bool	operator<(const Fixed &fix) const;
	Fixed	operator+(const Fixed &fix) const;
	Fixed	operator-(const Fixed &fix) const;
	Fixed	operator*(const Fixed &fix) const;
	Fixed	operator/(const Fixed &fix) const;
	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);
	static Fixed	&min(Fixed &f1, Fixed &f2);
	static const Fixed	&min(const Fixed &f1, const Fixed &f2);
	static Fixed	&max(Fixed &f1, Fixed &f2);
	static const Fixed	&max(const Fixed &f1,const Fixed &f2);

	

	

	int	getRawBits() const;
	void	setRawBits(int const raw);
	float toFloat(void) const;
	int	toInt(void) const;

};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);
#endif

