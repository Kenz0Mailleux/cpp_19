/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:36:03 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 16:36:05 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void iter(T *array, std::size_t length, F func)
{
	if (!array)
		return;
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T, typename F>
void iter(T const *array, std::size_t length, F func)
{
	if (!array)
		return;
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

#endif
