/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:00:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/11/29 20:09:51 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

#include "include/PmergeMe.hpp"

static double nowMicro()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

static void print(const std::vector<int> &c, const std::string &label)
{
	std::cout << label;
	for (std::size_t i = 0; i < c.size(); ++i)
		std::cout << " " << c[i];
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	try
	{
		std::vector<int> input = PmergeMe::parseArgs(argc, argv);
		std::vector<int> vec(input.begin(), input.end());
		std::deque<int>  deq(input.begin(), input.end());

		print(input, "Before:");

		double startVec = nowMicro();
		PmergeMe::sortVector(vec);
		double endVec = nowMicro();

		double startDeq = nowMicro();
		PmergeMe::sortDeque(deq);
		double endDeq = nowMicro();

		print(vec, "After:");

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << vec.size()
		          << " elements with std::vector : " << (endVec - startVec) << " us" << std::endl;
		std::cout << "Time to process a range of " << deq.size()
		          << " elements with std::deque  : " << (endDeq - startDeq) << " us" << std::endl;
	}
	catch (std::exception const &)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
