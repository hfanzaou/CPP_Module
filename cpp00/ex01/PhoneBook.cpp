/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <hfanzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:42:22 by hfanzaou          #+#    #+#             */
/*   Updated: 2023/03/25 01:05:32 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
int	PhoneBook::add_contact(int ind)
{
	if(this->Contacts[ind].set_contact())
		return (1);
	if (this->index != 8)
		this->index++;
	return (0);	
}

void	print_line()
{
	int i;

	i = 0;
	while (i < 45)
	{
		std::cout << "-";
		i++;
	}
	std::cout << std::endl;
}

void	print_head()
{
	print_line();
	std::cout << "|" << std::setw(10);
	std::cout << "Index";
	std::cout << "|" << std::setw(10);
	std::cout << "First name";
	std::cout << "|" << std::setw(10);
	std::cout << "Last name";
	std::cout << "|" << std::setw(10);
	std::cout << "Nickname";
	std::cout << "|" << std::endl;
}

int	PhoneBook::print_all()
{
	int i;
	int j;
	std::string val;
	j = 0;
	i = 0;
	print_head();
	print_line();
	if (this->index == 0)
	{
		std::cout << std::setw(25) << "Empty" << std::endl;
		print_line();
		return 1;
	}
	while (i < this->index)
	{
		j = 0;
		while (j < 5)
		{
			std::cout << "|";
			if (j == 0)
				std::cout << std::setw(10) << i + 1;
			else if (j < 4)
			{
				val = this->Contacts[i].getval(j - 1);
				if (val.size() >= 10)
				{
					val.replace(9, 1, ".");
					val.erase(10);
				}
				std::cout << std::setw(10) << val;
			}
			j++;
		}
		std::cout << std::endl;
		i++;
	}
	print_line();
	return (0);
}

void	PhoneBook::search(int ind)
{
	this->Contacts[ind - 1].print_contact();
}

void	PhoneBook::init_ind()
{
	this->index = 0;
}

int	PhoneBook::get_ind()
{
	return (this->index);
}