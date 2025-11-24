/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:03:21 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/05 17:05:52 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

static void seedOnce() {
    static bool seeded = false;
    if (!seeded) { std::srand(static_cast<unsigned int>(std::time(0))); seeded = true; }
}

Base * generate(void) {
    seedOnce();
    int r = std::rand() % 3;
    switch (r) {
        case 0: std::cout << "generate: A\n"; return new A();
        case 1: std::cout << "generate: B\n"; return new B();
        default: std::cout << "generate: C\n"; return new C();
    }
}

void identify(Base* p) {
    if (!p) { std::cout << "identify(*): null\n"; return; }
    if (dynamic_cast<A*>(p)) std::cout << "A\n";
    else if (dynamic_cast<B*>(p)) std::cout << "B\n";
    else if (dynamic_cast<C*>(p)) std::cout << "C\n";
    else std::cout << "Unknown\n";
}

void identify(Base& p) {
    try { (void)dynamic_cast<A&>(p); std::cout << "A\n"; return; } catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B\n"; return; } catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C\n"; return; } catch (...) {}
    std::cout << "Unknown\n";
}
