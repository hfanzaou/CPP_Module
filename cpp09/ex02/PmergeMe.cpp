#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _time(gettimenow())
{
	//std::cout << "Default Constructor called" << std::endl;
}

PmergeMe::PmergeMe(const std::vector<int>& con1) 
	: _time(gettimenow()) ,  _con1(con1), _size(con1.size())
{
	//std::cout << "Constructor called" << std::endl;
}

PmergeMe::PmergeMe(const std::deque<int>& con2) 
	: _time(gettimenow()) , _con2(con2), _size(con2.size())
{
	//std::cout << "Constructor called" << std::endl;
}
PmergeMe::PmergeMe(const PmergeMe& obj) 
{
	//std::cout << "Copy Constructor called" << std::endl;
	*this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	//std::cout << "Copy assignement constructor called" << std::endl;
	if (this != &obj)
	{
		this->_con1 = obj._con1;
		this->_con2 = obj._con2;
		this->_size = obj._size;
		this->_time = obj._time;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	//std::cout << "Destructor called" << std::endl;
}

//VECTOR FUNCTIONS
void	merge_vec(std::vector<int>& con, size_t start, size_t new_end, size_t end)
{
	std::vector<int> left_part(con.cbegin() + start, con.cbegin() + new_end + 1);
	std::vector<int> right_part((con.cbegin() + new_end + 1), con.cbegin() + end + 1);
	std::vector<int>::iterator left = left_part.begin();
	std::vector<int>::iterator right = right_part.begin();
	std::vector<int>::iterator it = con.begin() + start;

	while (left != left_part.end() && right != right_part.end())
	{
		if (*left <= *right)
		{
			*it = *left;
			left++;
		}
		else
		{
			*it = *right;
			right++;
		}
		it++;
	}
	while (left != left_part.end())
	{
		*it = *left;
		left++;
		it++;
	}
	while (right != right_part.end())
	{
		*it = *right;
		right++;
		it++;
	}
}


void insert_vec(std::vector<int>& con)
{
    int n = con.size();
    for (int i = 1; i < n; i++) 
	{
        int key = con[i];
        int j = i - 1;
        while (j >= 0 && con[j] > key) 
		{
            con[j + 1] = con[j];
            j--;
        }
        con[j + 1] = key;
    }
}

void	sort_vec(std::vector<int>& con, size_t start, size_t end)
{
	size_t k = 30;
	size_t new_end;
	if (end - start + 1 > k)
	{
		new_end = (start + end) / 2;
		sort_vec(con, start, new_end);
		sort_vec(con, new_end + 1, end);
		merge_vec(con, start, new_end, end);
	}
	else
		insert_vec(con);
}

void	PmergeMe::vec_sort()
{
	sort_vec(this->_con1, 0, this->_con1.size() - 1);
	this->_time = gettimenow() - this->_time;
}


//DEQUE FUNCTIONS

void	merge_deque(std::deque<int>& con, size_t start, size_t new_end, size_t end)
{
	std::deque<int> left_part(con.cbegin() + start, con.cbegin() + new_end + 1);
	std::deque<int> right_part((con.cbegin() + new_end + 1), con.cbegin() + end + 1);
	std::deque<int>::iterator left = left_part.begin();
	std::deque<int>::iterator right = right_part.begin();
	std::deque<int>::iterator it = con.begin() + start;

	while (left != left_part.end() && right != right_part.end())
	{
		if (*left <= *right)
		{
			*it = *left;
			left++;
		}
		else
		{
			*it = *right;
			right++;
		}
		it++;
	}
	while (left != left_part.end())
	{
		*it = *left;
		left++;
		it++;
	}
	while (right != right_part.end())
	{
		*it = *right;
		right++;
		it++;
	}
}


void insert_deque(std::deque<int>& con) 
{
	int temp;
    int j;
    for (size_t i = 1; i < con.size(); i++) 
	{
        temp = con[i];
        j = i - 1;
        while (j >= 0 && con[j] > temp) {
            con[j + 1] = con[j];
            j--;
        }
        con[j + 1] = temp;
    }
}

void	sort_deque(std::deque<int>& con, size_t start, size_t end)
{
	size_t k = 30;
	size_t new_end;
	if (end - start + 1 > k)
	{
		new_end = (start + end) / 2;
		sort_deque(con, start, new_end);
		sort_deque(con, new_end + 1, end);
		merge_deque(con, start, new_end, end);
	}
	else
		insert_deque(con);
}

void	PmergeMe::deque_sort()
{
	sort_deque(this->_con2, 0, this->_con2.size() - 1);
	this->_time = gettimenow() - this->_time;
}


//utils

size_t 	PmergeMe::get_time() const
{
	return(this->_time);
}

size_t PmergeMe::get_size() const
{
	return (this->_size);
}

size_t	PmergeMe::gettimenow() const
{
	timeval t;
	gettimeofday(&t, NULL);
	size_t ret;

	ret = (static_cast<size_t>(t.tv_sec) * 1000000 + static_cast<size_t>(t.tv_usec));
	return (ret);
}

void	PmergeMe::print_vec() const
{
	std::vector<int>::const_iterator it;

	for (it = this->_con1.begin(); it != this->_con1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::print_deque() const
{
	std::deque<int>::const_iterator it;

	for (it = this->_con2.cbegin(); it != this->_con2.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

}