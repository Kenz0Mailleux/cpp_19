/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:00:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/02/10 15:00:00 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN()
{
}

RPN::RPN(RPN const &other)
{
	(void)other;
}

RPN &RPN::operator=(RPN const &other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{
}

static bool isOperator(const std::string &token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

static long applyOp(const std::string &op, long lhs, long rhs)
{
	if (op == "+")
		return lhs + rhs;
	if (op == "-")
		return lhs - rhs;
	if (op == "*")
		return lhs * rhs;
	if (op == "/")
	{
		if (rhs == 0)
			throw std::runtime_error("division by zero");
		return lhs / rhs;
	}
	throw std::runtime_error("unknown operator");
}

long RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::stack<long>    stk;
	std::string         token;

	while (iss >> token)
	{
		if (isOperator(token))
		{
			if (stk.size() < 2)
				throw std::runtime_error("invalid expression");
			long rhs = stk.top(); stk.pop();
			long lhs = stk.top(); stk.pop();
			stk.push(applyOp(token, lhs, rhs));
		}
		else if (token.size() == 1 && std::isdigit(token[0]))
		{
			stk.push(token[0] - '0');
		}
		else
		{
			throw std::runtime_error("invalid token");
		}
	}
	if (stk.size() != 1)
		throw std::runtime_error("invalid expression");
	return stk.top();
}
