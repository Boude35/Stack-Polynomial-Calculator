#ifndef _my_stack_hpp
#define _my_stack_hpp

#include<list>
#include "Polynomial.hpp"

class mystack: private std::list<Polynomial>
{
public:
	void push(const Polynomial &val);//insert value
	void pop();//remove top value
	const Polynomial& top() const;//return the value at the top of the stack
	
	bool isEmpty() const;//check if the stack is empty
};

#endif
