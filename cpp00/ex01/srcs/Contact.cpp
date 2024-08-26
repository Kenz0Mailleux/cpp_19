/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:26:44 by kenzo             #+#    #+#             */
/*   Updated: 2024/08/26 23:50:10 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	
}

Contact::~Contact(){

}

void Contact::SetContact(){
	std::cout << "Initialisation of the Contact !" << std::endl;
	std::cout << "Enter the First Name";
	while (!(std::getline(std::cin, this->FirstName)) || this->FirstName.length() == 0)
	{
		std::cout << "Empty line is forbidden" << std::endl;
	}
	std::cout << "Enter the Last Name";
	while (!(std::getline(std::cin, this->LastName)) || this->LastName.length() == 0)
	{
		std::cout << "Empty line is forbidden" << std::endl;
	}
	std::cout << "Enter the Nick Name";
	while (!(std::getline(std::cin, this->NickName)) || this->LastName.length() == 0)
	{
		std::cout << "Empty line is forbidden" << std::endl;
	}
	std::cout << "Enter the Phone Number";
	while (!(std::getline(std::cin, this->PhoneNumber)) || this->PhoneNumber.length() == 0)
	{
		std::cout << "Empty line is forbidden" << std::endl;
	}
	std::cout << "Enter the Darkest Secret";
	while (!(std::getline(std::cin, this->DarkestSecret)) || this->DarkestSecret.length() == 0)
	{
		std::cout << "Empty line is forbidden" << std::endl;
	}
	std::cout << "The contact has been succesfully added" << std::endl;
}

void Contact::GetContact(){
	std::cout << "This is the First Name" << FirstName << std::endl;
	std::cout << "This is the Last Name" << LastName << std::endl;
	std::cout << "This is the Nick Name" << NickName << std::endl;
	std::cout << "This is the Phone Number" << PhoneNumber << std::endl;
	std::cout << "This is the Darkest Secret" << DarkestSecret << std::endl;
}
