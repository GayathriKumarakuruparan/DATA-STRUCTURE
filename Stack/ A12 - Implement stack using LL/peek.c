#include "stack.h"

int Peek(Stack_t **top)
{
    /* creating temp to point data in top */
    Stack_t *temp = *top;
   
    /* checking list is empty */
    if(temp == NULL)
    {
	    return FAILURE;
    }
    else
	/*returning top most element of stack */
    {
	    return temp->data;
    }
}