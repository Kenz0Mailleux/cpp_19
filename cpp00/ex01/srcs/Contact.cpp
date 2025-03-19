/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:26:44 by kenzo             #+#    #+#             */
/*   Updated: 2025/02/14 16:04:28 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string TruncateOrPad(const std::string& str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return std::string(width - str.length(), ' ') + str;
}


void Contact::SetContact() {
    std::cout << "Enter the First Name: ";
    while (!(std::getline(std::cin, FirstName)) || FirstName.empty()) {
        std::cout << "Empty line is forbidden. Enter the First Name: ";
    }
    std::cout << "Enter the Last Name: ";
    while (!(std::getline(std::cin, LastName)) || LastName.empty()) {
        std::cout << "Empty line is forbidden. Enter the Last Name: ";
    }
    std::cout << "Enter the Nickname: ";
    while (!(std::getline(std::cin, NickName)) || NickName.empty()) {
        std::cout << "Empty line is forbidden. Enter the Nickname: ";
    }
    std::cout << "Enter the Phone Number: ";
    while (!(std::getline(std::cin, PhoneNumber)) || PhoneNumber.empty()) {
        std::cout << "Empty line is forbidden. Enter the Phone Number: ";
    }
    std::cout << "Enter the Darkest Secret: ";
    while (!(std::getline(std::cin, DarkestSecret)) || DarkestSecret.empty()) {
        std::cout << "Empty line is forbidden. Enter the Darkest Secret: ";
    }
    std::cout << "The contact has been successfully added." << std::endl;
}

void Contact::DisplaySummary(int index) const {
    std::cout << TruncateOrPad(std::to_string(index), 10) << "|"
              << TruncateOrPad(FirstName, 10) << "|"
              << TruncateOrPad(LastName, 10) << "|"
              << TruncateOrPad(NickName, 10) << std::endl;
}


void Contact::DisplayDetails() const {
    std::cout << "First Name: " << FirstName << std::endl;
    std::cout << "Last Name: " << LastName << std::endl;
    std::cout << "Nickname: " << NickName << std::endl;
    std::cout << "Phone Number: " << PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << DarkestSecret << std::endl;
}
