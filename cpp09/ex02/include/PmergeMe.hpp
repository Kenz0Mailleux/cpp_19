/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:00:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/02/10 15:00:00 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
public:
	static std::vector<int> parseArgs(int argc, char **argv);
	static void             sortVector(std::vector<int> &data);
	static void             sortDeque(std::deque<int> &data);

private:
	PmergeMe();
	PmergeMe(PmergeMe const &);
	PmergeMe &operator=(PmergeMe const &);
	~PmergeMe();
};

#endif
