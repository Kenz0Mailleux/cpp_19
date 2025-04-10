/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:07:24 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/10 16:11:13 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Replace.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Usage: ./sed_is_for_losers <filename> <s1> <s2>\n";
        return 1;
    }

    Replace Replace(argv[1], argv[2], argv[3]);
    if (!Replace.process())
        return 1;

    return 0;
}
