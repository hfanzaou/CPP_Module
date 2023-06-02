#include "PhoneBook.hpp"

int main()
{
	PhoneBook Phone;
	std::string cmd;
	int i;
	i = 0;
	Phone.init_ind();
	while (1 && !std::cin.eof())
	{
		std::cout << "PhoneBook>>";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			if(!Phone.add_contact(i))
				i++;
		}
		else if (cmd == "SEARCH")
		{
			if (!Phone.print_all())
			{
				std::cout << "Chose an index : ";
				std::getline(std::cin, cmd);
				if (atoi(cmd.c_str()) <= Phone.get_ind() && atoi(cmd.c_str()) > 0)
					Phone.search(atoi(cmd.c_str()));
				else
					std::cout << "Index out of range" << std::endl;	
			}
		}
		else if (cmd == "EXIT")
			exit(0);	
		if (i == 8)
			i = 0;	
	}
}
