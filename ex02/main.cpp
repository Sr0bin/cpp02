/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:02:30 by rorollin          #+#    #+#             */
/*   Updated: 2026/02/25 15:53:47 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iomanip>
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( 11 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );

	std::cout << "\n-----------------------\n\n";
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "\n-----------------------\n\n";
	std::cout << "a+b is " << a+b << std::endl;
	std::cout << "a-b is " << a-b << std::endl;
	std::cout << "a*b is " << a*b << std::endl;
	std::cout << "a/b is " << a/b << std::endl;
	std::cout << "\n-----------------------\n\n";
	std::cout << std::setprecision(10) << "a is " << a << std::endl;
	std::cout << std::setprecision(10) << "++a is " << ++a << std::endl;
	std::cout << std::setprecision(10) << "a is " << a << std::endl;
	std::cout << std::setprecision(10) << "a++ is " << a++ << std::endl;
	std::cout << std::setprecision(10) << "a is " << a << std::endl;
	std::cout << "\n-----------------------\n\n";
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "b == d is " << (b == d) << std::endl;
	std::cout << "d != c is " << (c != d) << std::endl;
	std::cout << "\n-----------------------\n\n";
	std::cout << "min(a, b) is " << Fixed::min(a, b) << std::endl;
	std::cout << "max(c, d) is " << Fixed::max(c, d) << std::endl;
	std::cout << "\n-----------------------\n\n";
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "\n-----------------------\n\n";


	return (0);
}
