#!/bin/bash

path="cpp09/ex01"
class_name="PmergeMe"
upper="PMERGEME_HPP"
type="size_t"
name="N"
echo "#ifndef $upper
#define $upper
#include <iostream>

class $class_name {
	private:
   		$type _$name;
	public:
		$class_name();
    	$class_name(const $type& $name);
    	$class_name(const $class_name& obj);
		$class_name& operator=(const $class_name& obj);
		~$class_name();
};

#endif" > $class_name.hpp 

echo "#include \"$class_name.hpp\"

$class_name::$class_name() 
{
	std::cout << \"Default Constructor called\" << std::endl;
}

$class_name::$class_name(const $type& $name)
{
	std::cout << \"Constructor called\" << std::endl;
}

$class_name::$class_name(const $class_name& obj) 
{
	std::cout << \"Copy Constructor called\" << std::endl;
	*this = obj;
}

$class_name& $class_name::operator=(const $class_name& obj)
{
	std::cout << \"Copy assignement constructor called\" << std::endl;
	if (this != &obj)
	{
		
	}
	return (*this);
}

$class_name::~$class_name()
{
	std::cout << \"Destructor called\" << std::endl;
}" > $class_name.cpp 

mv $class_name.cpp $path
mv $class_name.hpp $path