#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
     /* if it is empty */
    if(*head==NULL)
    {
        return LIST_EMPTY;
    }
    else
    {
        while(*head!=NULL)
        {
             /* create temp node */
             Dlist *temp=*head;
            *head=temp->next;
            free(temp);           //deallocate the node one by one
        }
        return SUCCESS;
    }
}