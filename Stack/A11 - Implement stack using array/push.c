#include "stack.h"

/* Fuction for inserting the element */
int Push(Stack_t *s, int element)
{
    	/* checking if space available in stack */
    if(s->top == (s->capacity - 1))
    {
	    return FAILURE;
    }
    else
    {
    	s->top++;			//incrementing top and adding element
    	s->stack[s->top] = element;
	    return SUCCESS;
    }
}