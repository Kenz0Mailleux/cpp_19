/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:49:05 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 17:01:25 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("easyfind: value not found");
	return it;
}

template <typename T>
typename T::const_iterator easyfind(T const &container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("easyfind: value not found");
	return it;
}

#endif
