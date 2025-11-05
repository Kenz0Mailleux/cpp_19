/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:00:16 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/05 17:00:18 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

# include <stdint.h>
# include "Data.hpp"

class Serializer {
private:
    Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data*     deserialize(uintptr_t raw);
};

#endif
