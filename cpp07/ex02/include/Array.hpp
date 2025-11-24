/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:37:12 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/24 16:37:15 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <iostream>

template <typename T>
class Array
{
public:
	Array() : _array(NULL), _size(0) {}

	Array(unsigned int n) : _array(NULL), _size(n)
	{
		if (n > 0)
			_array = new T[n]();
	}

	Array(Array const &other) : _array(NULL), _size(0)
	{
		*this = other;
	}

	~Array()
	{
		delete[] _array;
	}

	Array &operator=(Array const &other)
	{
		if (this != &other)
		{
			delete[] _array;
			_size = other._size;

			if (_size > 0)
			{
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					_array[i] = other._array[i];
			}
			else
				_array = NULL;
		}
		return *this;
	}

	T &operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::out_of_range("Index out of range");
		return _array[index];
	}

	T const &operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::out_of_range("Index out of range");
		return _array[index];
	}

	unsigned int size() const
	{
		return _size;
	}

private:
	T *_array;
	unsigned int _size;
};

#endif
