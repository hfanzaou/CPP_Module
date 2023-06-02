/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <hfanzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:43:02 by hfanzaou          #+#    #+#             */
/*   Updated: 2023/03/25 01:02:44 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <stdlib.h>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact Contacts[8];
	int		index;
public:
	int		add_contact(int ind);
	int		print_all();
	void	search(int ind);
	void	init_ind();
	int		get_ind();
};

#endif