#include "stack.h"

int Push(Stack_t **top, data_t data)
{
    /*create a node*/
    Stack_t *new=malloc(sizeof(Stack_t));
    if(new==NULL)
    {
        return FAILURE;
    }
    /* Fill the node */
    new->data=data;
    new->link=*top;
    *top=new;
}