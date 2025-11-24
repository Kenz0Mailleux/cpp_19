/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:10:47 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 16:59:15 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	return (b <= a ? b : a);
}

template <typename T>
T const &max(T const &a, T const &b)
{
	return (b >= a ? b : a);
}

#endif
