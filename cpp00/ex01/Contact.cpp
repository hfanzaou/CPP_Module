/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <hfanzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:41:51 by hfanzaou          #+#    #+#             */
/*   Updated: 2023/03/25 01:06:34 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Contact.hpp"
#include <iomanip>

int	Contact::set_contact()
{
	int i;
	i = 0;
	std::string dash[5][1] = {
		{"First name   	: "},
		{"Last name       : "},
		{"Nickname        : "},
		{"Phone number 	: "},
		{"Darkest secret  : "}
	};
	while (i < 5 && !std::cin.eof())
	{
		std::cout << dash[i][0];
		if (i == 0)
			std::getline(std::cin, this->first_name);
		else if (i == 1)
			std::getline(std::cin, this->last_name);
		else if (i == 2)
			std::getline(std::cin, this->nickname);
		else if (i == 3)
			std::getline(std::cin, this->phone_number);
		else if (i == 4)
			std::getline(std::cin, this->darkest_secret);
		i++;
	}
	if (!*this->first_name.c_str() || !*this->phone_number.c_str())
		return (1);
	return (0);
}

void	Contact::print_contact()
{
	std::cout <<
	"First name   	: " << this->first_name << std::endl <<
	"Last name    	: " << this->last_name << std::endl <<
	"Nickname        : " << this->nickname << std::endl <<
	"Phone number 	: " << this->phone_number << std::endl <<
	"Darkest secret  : " << this->darkest_secret << std::endl;
}

std::string	Contact::getval(int i)
{
	if (i == 0)
		return (this->first_name);
	else if (i == 1)
		return (this->last_name);
	else if (i == 2)
		return (this->nickname);	
	return ("\0");			
}
