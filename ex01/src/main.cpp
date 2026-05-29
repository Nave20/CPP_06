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
#include "../inc/Serializer.hpp"

int main()
{
	Data test;

	test.id = 28;
	test.name = "test";

	Data* original = &test;

	uintptr_t raw = Serializer::serialize(original);

	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original : " << original << std::endl;
	std::cout << "Restored : " << restored << std::endl;

	if (original == restored)
		std::cout << "Pointers are equal" << std::endl;

	std::cout << restored->name << std::endl;
}