/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:25:44 by kenzo             #+#    #+#             */
/*   Updated: 2025/02/14 16:04:52 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

std::string Truncate(const std::string& str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return std::string(width - str.length(), ' ') + str;
}

void PhoneBook::Add() {
    if (contactCount < 8) {
        contacts[contactCount].SetContact();
        contactCount++;
    } else {
        std::cout << "Contact list is full. Replacing the oldest contact." << std::endl;
        contacts[oldestIndex].SetContact();
        oldestIndex = (oldestIndex + 1) % 8;
    }
}

void PhoneBook::Search() {
    if (contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << Truncate("Index", 10) << "|"
              << Truncate("First Name", 10) << "|"
              << Truncate("Last Name", 10) << "|"
              << Truncate("Nickname", 10) << std::endl;
    std::cout << std::string(44, '-') << std::endl;

    for (int i = 0; i < contactCount; i++) {
        contacts[i].DisplaySummary(i);
    }

    std::cout << "Enter the index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);
    int index;
    try {
        index = std::stoi(input);
        if (index >= 0 && index < contactCount) {
            contacts[index].DisplayDetails();
        } else {
            std::cout << "Invalid index." << std::endl;
        }
    } catch (...) {
        std::cout << "Invalid input." << std::endl;
    }
}
