/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:02:02 by rorollin          #+#    #+#             */
/*   Updated: 2026/02/23 17:14:05 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int	_value;
	static const int _bpf = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);

	~Fixed();
	Fixed &operator=(const Fixed &fix);

	int	getRawBits() const;
	void	setRawBits(int const raw);
};

#endif

