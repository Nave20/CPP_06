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

#include "../inc/Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base *generate()
{
	std::srand(std::time(0));
	int rand = std::rand();

	if (rand % 3 == 0)
		return new A;
	else if (rand % 3 == 1)
		return new B;
	else
		return new C;
}

void identify(Base *base)
{
	if (dynamic_cast<A*>(base))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << "C" << std::endl;
}

void identify(Base &base)
{
	try
	{
		A& a =  dynamic_cast<A&>(base);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try
	{
		B& b = dynamic_cast<B&>(base);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try
	{
		C& c = dynamic_cast<C&>(base);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e) {}
}

int main()
{
	Base *test = generate();

	identify(test);
	identify(*test);
	delete test;
}