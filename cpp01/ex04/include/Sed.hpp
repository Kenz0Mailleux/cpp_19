/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:06:51 by kenzo             #+#    #+#             */
/*   Updated: 2025/04/07 14:14:57 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <fstream>
#include <iostream>

class Sed {
public:
    Sed(const std::string& filename, const std::string& s1, const std::string& s2);
    bool process();

private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
    std::string replaceString(const std::string& line);
};

#endif
