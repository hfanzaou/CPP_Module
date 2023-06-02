#include <iostream>
#include <fstream>
#include <string.h>


std::string ft_replace(std::string line, char *s1, char *s2)
{
	std::string	newline;
	size_t		start;
	size_t		end;
	int i;
	i = 0;
	newline = line;
	start = line.find(s1);
	while (start != std::string::npos)
	{
		end = start + strlen(s1);
		std::cout << start << std::endl << end << std::endl << line.size() << std::endl;
		newline.erase(start);
		newline.append(s2);
		newline.append(line.substr(end, line.size() - end));
		line = newline;
		start = line.find(s1);
	}
	return (newline);
}

int	ft_err(std::ifstream &in, std::ofstream &out)
{
	if (!in)
	{
		std::cerr << "Could not open in file" << std::endl;
		return (1);
	}
	if (!out)
	{
		std::cerr << "Could not open out file" << std::endl;
		return (1);	
	}
	return (0);	
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Invalid arguments" << std::endl;
		return (1);
	}
	std::ifstream	in(av[1]);
	std::string		filename = av[1];
	std::string		line;

	filename.append(".replace");
	std::ofstream	out(filename);
	if (ft_err(in, out))
		return (1);
	while (std::getline(in, line))
	{
		out << ft_replace(line, av[2], av[3]) << std::endl;
	}
	out.close();
	in.close();

}