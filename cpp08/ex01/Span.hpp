#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
   		size_t _N;
		std::vector<int> _arr;
	public:
		Span();
    	Span(const size_t& N);
    	Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span();
		void	addNumber(int N);
		size_t		shortestSpan() const;
		size_t	longestSpan() const;
		class NoMoreSpace : public std::exception {
			public :
				const char *what() const throw();
		};
};

#endif
