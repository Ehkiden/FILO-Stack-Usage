/*
* stack class
*
* Member functions
*  push-- put an item on the top of the stack
*  pop -- remove an item from the top of the stack
*  isEmpty -- return true if the stack is empty; otherwise false
*  isFull -- return true if the stack is full; otherwiese false
*/
#ifndef STACK_H
#define STACK_H

#include "bound_err.h"

const int STACK_SIZE = 5;  //Maximum size of a stack
class stack
{
public:
	stack() :top_index(-1) {};
	//Copy constructor--use the system default;
	//Assignment operator--use the system default;

	//Push an itme on the top of the stack
	void push(char item) throw(bound_err);

	//Pop an item from the top of the stack
	char pop() throw(bound_err);

	//Check if the stack is empty
	bool isEmpty() const;

	//Check if the stack is full (reach the maximum size of the stack)
	//The maximum size of the stack is defined by the constant STACK_SIZE
	bool isFull() const;

private:
	int top_index;              //the index number of the current top item
	char data[STACK_SIZE];      //The items themselves
};

#endif   //STACK_H
