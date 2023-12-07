#include "stack.h"

/* Function for Poping the element */
int Pop(Stack_t *s)
{	
	
    /* checking if list empty */
    if(s->top == -1)
    {
	    return FAILURE;
    }
    else
    {		
    	s->top--;	//decrementing top when pop is called
    	return SUCCESS;
    }
}