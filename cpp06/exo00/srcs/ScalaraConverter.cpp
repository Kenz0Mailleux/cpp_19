/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalaraConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:05:00 by kmailleu          #+#    #+#             */
/*   Updated: 2025/11/05 16:52:03 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ScalarConverter.hpp"
# include <iostream>
# include <cstdlib>
# include <climits>
# include <cerrno>
# include <cctype>
# include <cmath>
# include <limits>

static bool isPseudoFloat(const std::string &s) {
    return (s == "nanf" || s == "+inff" || s == "-inff");
}
static bool isPseudoDouble(const std::string &s) {
    return (s == "nan" || s == "+inf" || s == "-inf");
}
static bool isCharLiteral(const std::string &s) {
    return (s.size() == 1 && std::isprint(static_cast<unsigned char>(s[0])) && !std::isdigit(s[0]));
}
static bool endsWithF(const std::string &s) {
    return (s.size() > 1 && s[s.size()-1] == 'f');
}

static bool parseLong(const std::string &s, long &out) {
    char *end = 0;
    errno = 0;
    out = std::strtol(s.c_str(), &end, 10);
    if (errno != 0 || !end || *end != '\0') return false;
    return true;
}
static bool parseDouble(const std::string &s, double &out) {
    char *end = 0;
    errno = 0;
    out = std::strtod(s.c_str(), &end);
    if (errno != 0 || !end || *end != '\0') return false;
    return true;
}

static void printFromChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    float f = static_cast<float>(c);
    std::cout.setf(std::ios::fixed); std::cout.precision(1);
    std::cout << "float: " << f << "f" << std::endl;
    double d = static_cast<double>(c);
    std::cout << "double: " << d << std::endl;
}

static void printCommon(double d, bool validInt, bool validChar) {
    if (!validChar) std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(d))))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (!validInt) std::cout << "int: impossible" << std::endl;
    else std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout.setf(std::ios::fixed); std::cout.precision(1);
    float f = static_cast<float>(d);
    if (std::isnan(f)) std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f)) std::cout << "float: " << (f>0?"+inff":"-inff") << std::endl;
    else std::cout << "float: " << f << "f" << std::endl;

    if (std::isnan(d)) std::cout << "double: nan" << std::endl;
    else if (std::isinf(d)) std::cout << "double: " << (d>0?"+inf":"-inf") << std::endl;
    else std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &s) {
    if (isCharLiteral(s)) {
        printFromChar(s[0]);
        return;
    }

    if (isPseudoFloat(s)) {
        double d = (s=="nanf")? std::numeric_limits<double>::quiet_NaN()
                   : (s=="+inff")? std::numeric_limits<double>::infinity()
                   : -std::numeric_limits<double>::infinity();
        printCommon(d, false, false);
        return;
    }
    if (isPseudoDouble(s)) {
        double d = (s=="nan")? std::numeric_limits<double>::quiet_NaN()
                   : (s=="+inf")? std::numeric_limits<double>::infinity()
                   : -std::numeric_limits<double>::infinity();
        printCommon(d, false, false);
        return;
    }

    if (endsWithF(s)) {
        std::string core = s.substr(0, s.size()-1);
        double d;
        if (!parseDouble(core, d)) {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
        bool validInt = (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX) && !std::isnan(d) && !std::isinf(d));
        bool validChar = validInt && (d >= 0.0 && d <= 255.0);
        printCommon(d, validInt, validChar);
        return;
    }
    long li;
    if (parseLong(s, li)) {
        double d = static_cast<double>(li);
        bool validChar = (li >= 0 && li <= 255);
        printCommon(d,
                    (li >= INT_MIN && li <= INT_MAX),
                    validChar);
        return;
    }

    double d;
    if (parseDouble(s, d)) {
        bool validInt = (!std::isnan(d) && !std::isinf(d) && d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX));
        bool validChar = validInt && (d >= 0.0 && d <= 255.0);
        printCommon(d, validInt, validChar);
        return;
    }
    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}
