/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:28:16 by kenzo             #+#    #+#             */
/*   Updated: 2024/08/26 23:50:25 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef H_CONTACT_H
# define H_CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Contact{

public :
	Contact();
	~Contact();
	void SetContact();
	void GetContact();

private :
	std::string	FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
};


#endif