/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:00:26 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/05 17:00:32 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Serializer.hpp"

int main() {
    Data d;
    d.id = 42; d.name = "Kenzo"; d.score = 19.75;

    uintptr_t raw = Serializer::serialize(&d);
    Data *back = Serializer::deserialize(raw);

    std::cout << "Original ptr: " << &d << "\n";
    std::cout << "Deserialized: " << back << "\n";

    if (back == &d) {
        std::cout << "OK: pointers match\n";
        std::cout << "Data: { id=" << back->id << ", name=" << back->name
                  << ", score=" << back->score << " }\n";
    } else {
        std::cout << "ERROR: pointers differ\n";
    }
    return 0;
}
