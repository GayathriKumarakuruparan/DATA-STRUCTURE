#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
        /* Creating the new node */
    Slist *new = malloc(sizeof(Slist));

    /* Check whether new node created or not */
    if (new == NULL)
    {
        return FAILURE;
    }
    if(*head == NULL)
    {
	    if(n == 1)     //adding element only if given node is 1
        {
            /* Fill the parts of the node */
            new->data = data;
            new->link = *head;
            *head = new;
            return SUCCESS;
        }
    	else
    	{
    	    return LIST_EMPTY;
    	}
    }
    if(n == 1)     
        {
            /* Fill the parts of the node */
            new->data = data;
            new->link = *head;
            *head = new;
            return SUCCESS;

        }
    /* temp to traverse and count to check node number */
    Slist *temp = *head;
    int count = 1;

    while(temp != NULL)
    {
    	if(n == count + 1)
    	{
    	    /* Fill the parts of the node */
    	    new->data = data;
    	    new->link = temp->link;
    	    temp->link = new;
    	    return SUCCESS;
    	}
    	else
    	{
    	    temp = temp->link;
    	    count++;
    	}
    }
    return POSITION_NOT_FOUND;
}