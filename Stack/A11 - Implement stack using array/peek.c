#include "stack.h"

/* Function for display the top of the element in Stack */
int Peek(Stack_t *s)
{
    /* checking if list is empty */
    if(s->top == -1)
    {
	    return FAILURE;
    }
    else
    {		//returning the top most element of stack
	    return s->stack[s->top];
    }	
	
}