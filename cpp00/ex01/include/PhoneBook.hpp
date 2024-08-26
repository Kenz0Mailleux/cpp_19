/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:28:14 by kenzo             #+#    #+#             */
/*   Updated: 2024/08/26 23:15:20 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef H_PHONEBOOK_H
# define H_PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook{

public :
		PhoneBook();
		~PhoneBook();

		void Add();
		void Search();
		void Exit();

private :
	Contact	_PhoneBook[8];
	bool	reset;
	
};


#endif