#include <iostream>
#include <fstream>
#include <string>

#include "mystack.hpp"

using namespace std;

int main(int argc, char *arv[])
{
	mystack polystack;//create a stack 
	Polynomial accumulator;//create a polinomio
	char prompt;// controller of the switch
	
	
	cout<<"Welcome To PolyCalc!"<<endl;
	do// ask continiuly for a promp until it is equal to q
	{
		cout<< ">>> ";
		cin>> prompt;//ask the user
		switch(prompt)
		{
		
			case 'c'://remove top value
				polystack.pop();
				break;
				
			case 'd'://clear the stack
				while(!polystack.isEmpty())//go through all the values in the stack
				{
					polystack.pop();//remove them
				}
				break;
				
			case 's'://prompt the user for a polynomio and store it at the top
				cout << "Enter Polynomial to Push: ";
				cin >> accumulator;
				polystack.push(accumulator);
				break;
				
			case 'e'://evaluate polynomio
			
				if(polystack.isEmpty())//if stack is empty
					cout<< "ERROR - Theres is no polynomio to evaluate" <<endl;
				else{
					float number;//value of x 
					cout << "Enter a value of x at which to evaluate polynomial: ";
					cin >> number;//prompt for the value
				
					cout << polystack.top().eval(number) << endl;//call eval in polynomial
				}
				break;
				
			case '+'://add two top values
				if(polystack.isEmpty())//if stack is empty
				{
					cout << "ERROR - There is no polinomio" << endl;		
				}
				else//store the top value and pop it
				{
					accumulator = polystack.top();
					polystack.pop();
					if(polystack.isEmpty())//if there is no second value
					{
						polystack.push(accumulator);//leavet the value at the top
						cout << "ERROR - There is only one value in the stack" << endl;		
					}
					else
					{
					accumulator = accumulator + polystack.top();//add oth values
					polystack.pop();//pop the second value
					polystack.push(accumulator);//add the sum
					cout<< "Result: " << polystack.top()<<endl;//return the addtion
					}
				}
				
				
				break;
				
			case '-'://substract two top values
				if(polystack.isEmpty())//if it is empty
				{
					cout << "ERROR - There is no polinomio" << endl;		
				}
				else
				{
					accumulator = polystack.top();//store the polynomial
					polystack.pop();//remove it
					if(polystack.isEmpty())//if there is not second value
					{
						polystack.push(accumulator);//leave the first at the top
						cout << "ERROR - There is only one value in the stack" << endl;		
					}
					else
					{
					accumulator = accumulator - polystack.top();//substract both values
					polystack.pop();//remove the second value from the top
					polystack.push(accumulator);//add it to the top(substraction)
					cout<< "Result: " << polystack.top()<<endl;
					}
				}
				break;
				
			case '*'://multiplication
				if(polystack.isEmpty())//if it is empty
				{
					cout << "ERROR - There is no polinomio" << endl;		
				}
				else
				{
					accumulator = polystack.top();//store the value
					polystack.pop();//pop it
					if(polystack.isEmpty())//if there is not second value
					{
						polystack.push(accumulator);//leave it at the top
						cout << "ERROR - There is only one value in the stack" << endl;		
					}
					else
					{
					accumulator = accumulator * polystack.top();//multiply them
					polystack.pop();//remove the second value
					polystack.push(accumulator);//add the multiplication
					cout<<"Result: " << polystack.top()<<endl;//print result
					}
				}
				break;
				
			case 'p'://print it
				if(polystack.isEmpty())
				{
					cout << "Stack is empty" << endl;		
				}
				else
					cout <<"Top value is: "<< polystack.top() <<endl;
				break;
				
			case 'q'://quit
			cout<<"Thank you for using PolyCalc"<<endl;
				break;
				
			default://other values that is not one of the above
			cout<<"Invalid Character"<<endl;
		}
	}while(prompt != 'q');
	return 0;
}
