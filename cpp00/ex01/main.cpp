/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:26:47 by kenzo             #+#    #+#             */
/*   Updated: 2025/01/21 17:35:33 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
            phoneBook.Add();
        else if (command == "SEARCH")
            phoneBook.Search();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Unknown command." << std::endl;
    }

    return 0;
}
