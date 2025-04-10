/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:07:02 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/07 14:14:36 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sed.hpp"

Sed::Sed(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {}

std::string Sed::replaceString(const std::string& line) {
    std::string result;
    size_t pos = 0;
    size_t prev = 0;

    while ((pos = line.find(_s1, prev)) != std::string::npos) {
        result += line.substr(prev, pos - prev);
        result += _s2;
        prev = pos + _s1.length();
    }
    result += line.substr(prev);
    return result;
}

bool Sed::process() {
    std::ifstream infile(_filename);
    std::ofstream outfile(_filename + ".replace");
    std::string line;
    if (!infile.is_open()) {
        std::cout << "Error: Could not open input file\n";
        return false;
    }
    if (!outfile.is_open()) {
        std::cout << "Error: Could not open output file\n";
        return false;
    }

    while (std::getline(infile, line)) {
        outfile << replaceString(line) << "\n";
    }

    infile.close();
    outfile.close();
    return true;
}
