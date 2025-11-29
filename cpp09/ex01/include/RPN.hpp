/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:00:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/02/10 15:00:00 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN
{
public:
	static long evaluate(const std::string &expression);

private:
	RPN();
	RPN(RPN const &);
	RPN &operator=(RPN const &);
	~RPN();
};

#endif
