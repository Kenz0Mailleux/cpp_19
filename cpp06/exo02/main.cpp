/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:03:04 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/05 17:03:06 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Base.hpp"

int main() {
    for (int i = 0; i < 5; ++i) {
        Base *p = generate();
        std::cout << "identify(pointer): "; identify(p);
        std::cout << "identify(ref):     "; identify(*p);
        delete p;
        std::cout << "---\n";
    }
    return 0;
}
