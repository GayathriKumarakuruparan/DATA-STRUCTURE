#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{
   /* checking list is empty */
    if(*head == NULL)
    {
	return FAILURE;
    }

    /* creating temp pointer to hold node for freeing */
    Dlist *temp = *head;
    Dlist *previous;
    if(temp->next == NULL)
    {
        *head = NULL;
	    *tail = NULL;
	    free(temp);
	    return SUCCESS;
    }
    /* traversing till NULL */
    else
    {
    while(temp->next != NULL)
    {
        previous=temp;
     	temp = temp->next;
    }   
    *tail = temp->prev;
    previous->next=NULL;
    temp->prev=NULL;
    free(temp);
    return SUCCESS;
    }

}
