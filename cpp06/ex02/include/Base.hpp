/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:03:41 by kenzo             #+#    #+#             */
/*   Updated: 2025/11/05 17:03:42 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP__
#define __BASE_HPP__

class Base {
public:
    virtual ~Base();
};

Base * generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif
