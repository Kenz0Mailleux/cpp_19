/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:06:51 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/10 14:22:29 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <fstream>
#include <iostream>

class Replace {
public:
    Replace(const std::string& filename, const std::string& s1, const std::string& s2);
    bool process();

private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
    std::string replaceString(const std::string& line);
};

#endif
