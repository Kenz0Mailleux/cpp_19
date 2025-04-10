/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:07:02 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/10 15:51:52 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Replace.hpp"

Replace::Replace(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {}

std::string Replace::replaceString(const std::string& line)
{
    std::string result;
    size_t found;
    size_t pos = 0;

    while (true) {
        found = line.find(_s1, pos);
        if (found == std::string::npos) {
            result += line.substr(pos);
            break;
        }
        result += line.substr(pos, found - pos);
        result += _s2;
        pos = found + _s1.length();
    }
    return result;
}
    

bool Replace::process()
{
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
