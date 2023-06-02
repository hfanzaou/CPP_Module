#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(7000);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	MutantStack<int> m(mstack);
	MutantStack<int>::iterator it2 = m.begin();
	MutantStack<int>::iterator ite2 = m.end();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << "-------" << std::endl;
	std::cout << m.top() << std::endl;
	m.pop();
	std::cout << m.top() << std::endl;

	std::cout << "stack with list" << std::endl;
	MutantStack<int, std::list<int> > sttack;
	sttack.push(5);
	sttack.push(17);
	std::cout << sttack.top() << std::endl;
	sttack.pop();
	std::cout << sttack.size() << std::endl;
	sttack.push(3);
	sttack.push(5);
	sttack.push(737);
	sttack.push(7000);
	sttack.push(0);
	MutantStack<int, std::list<int> >::iterator it1 = sttack.begin();
	MutantStack<int, std::list<int> >::iterator ite1 = sttack.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	return 0;
}