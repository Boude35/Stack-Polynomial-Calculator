#include "mystack.hpp"

#include <iostream>

void
mystack::push(const Polynomial& somethingtoPush)
{
	list<Polynomial>::push_front(somethingtoPush);//add a value to the stack using STL list
}

void
mystack::pop()
{
	if(!isEmpty())
		list<Polynomial>::pop_front();//remove if the stack is not empty
	else
		cout << "EMPTY STACK - CANNOT POP!" << endl;//return this if the stack is empty
}

const Polynomial&
mystack::top() const
{
	return list<Polynomial>::front();//return the value at the top
}

bool
mystack::isEmpty() const
{
	return list<Polynomial>::empty();//check if the stack is empty
}
