#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <sys/time.h>

class PmergeMe {
	private:
		size_t _time;
   		std::vector<int> _con1;
		std::deque<int> _con2;
		size_t _size;
	public:
		PmergeMe();
    	PmergeMe(const std::vector<int>& con1);
		PmergeMe(const std::deque<int>& con2);
    	PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		~PmergeMe();
		size_t 	get_time() const;
		size_t gettimenow() const;
		size_t	get_size() const;
		void	print_vec() const;
		void	print_deque() const;
		void	vec_sort();
		void	deque_sort();
};

#endif
