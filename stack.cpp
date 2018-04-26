#include "stack.h"

void stack::push(char item) throw(bound_err)
{
	//if there is no more room for another item
	if (top_index >= STACK_SIZE - 1) {
		throw bound_err("Push overflows stack");
	}
	else {
		top_index++;
		data[top_index] = item;
	}
}

char stack::pop() throw(bound_err)
{
	//if there is nothing in the stack
	if (isEmpty()) {
		throw bound_err("Pop underflows stack");
	}
	else {

		int squish = data[top_index];
		top_index--;
		return squish;
	}

}

bool stack::isEmpty() const
{
	if (top_index < 0) {
		return true;
	}
	else {
		return false;
	}
	//return top_index < 0;
}

bool stack::isFull() const
{
	return top_index > STACK_SIZE;
}
