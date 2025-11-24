/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:54:26 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 16:56:40 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/MutantStack.hpp"
#include <list>

int main(void)
{
	std::cout << "=== MutantStack test ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "size after pop: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		// [...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack); // conversion vers std::stack
	}

	std::cout << "\n=== Comparison with std::list ===" << std::endl;
	{
		std::list<int> lst;

		lst.push_back(5);
		lst.push_back(17);

		std::cout << "back: " << lst.back() << std::endl;

		lst.pop_back();

		std::cout << "size after pop_back: " << lst.size() << std::endl;

		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		// [...]
		lst.push_back(0);

		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}
