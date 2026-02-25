/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:02:02 by rorollin          #+#    #+#             */
/*   Updated: 2026/02/25 16:03:55 by rorollin         ###   ########.fr       */
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
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int val);
	Fixed(const float val);

	~Fixed();
	Fixed &operator=(const Fixed &fix);
	

	int	getRawBits() const;
	void	setRawBits(int const raw);
	float toFloat(void) const;
	int	toInt(void) const;

};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif
