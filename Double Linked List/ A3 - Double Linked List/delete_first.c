#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
     /* create temp node */
    Dlist *temp=*head;
    
      /* if it is empty */
    if(*head==NULL)
    {
        return LIST_EMPTY;
    }
    else
    {
        /* if it has only one node */
        if(*head==*tail)
        {
            *head=NULL;
            *tail=NULL;
            free(temp);
            return SUCCESS;
        }
        else
        {
            *head=temp->next;
            free(temp);          //deallocate the node
            return SUCCESS;
        }
    }
}