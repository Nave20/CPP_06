/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   GitHub : @Nave20                                  #+#    #+#             */
/*   28 is the new 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../inc/ScalarConverter.hpp"

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <math.h>

void ScalarConverter::convert(const std::string &literal)
{
	double	value;
	bool	valid = false;
	if (literal.empty())
	{
		std::cout << "Empty argument." << std::endl;
		return;
	}
	std::string tab[] = {"nan", "nanf", "inf", "+inf", "+inff", "inff", "-inf", "-inff"};

	for (size_t j = 0; j < 8; j++)
		if (tab[j] == literal)
		{
			valid = true;
			break;
		}
	for (size_t j = 0; j < literal.length(); j++)
		if (!std::isdigit(literal[j]) && valid == false)
		{
			if ((literal[j] == '.' && !std::isdigit(literal[j + 1]))
				|| (literal[j] == 'f' && literal[j + 1] != 0) || (literal[j] == '-' && j != 0))
			{
				std::cout << literal << " can't be converted" << std::endl;
				return;
			}
		}
	int i = 0;
	for (size_t j = 0; j < literal.length(); j++)
		if (literal[j] == '.')
			i++;
	if (i > 1)
	{
		std::cout << literal << " can't be converted" << std::endl;
		return;
	}
	for (size_t j = 0; j < literal.length(); j++)
		if (!std::isdigit(literal[j]) && valid == false && literal[j] != '.'
			&& literal[j] != 'f' && literal[j] != '-' && literal.length() != 1)
		{
			std::cout << literal << " can't be converted" << std::endl;
			return;
		}

	if (literal.length() == 1 && !std::isdigit(literal[0]))
		value = static_cast<double>(literal[0]);
	else
		value = std::strtod(literal.c_str(), NULL);

	if (value < 0 || value > 127)
		std::cout << "char : impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char : not displayable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;

	if (value > std::numeric_limits<int>::max()
		|| value < std::numeric_limits<int>::min()
		|| isnan(value))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(value) << std::endl;

	std::cout << std::fixed << std::setprecision(1)
			  << "float : "
			  << static_cast<float>(value)
			  << "f"
			  << std::endl;

	std::cout << "double : " << static_cast<double>(value) << std::endl;
}