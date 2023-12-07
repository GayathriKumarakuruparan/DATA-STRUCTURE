#include "sll.h"

int sl_delete_first(Slist **head)
{
    //check whether the head is empty or not
    if(*head==NULL)
    {
        return LIST_EMPTY;
    }
    else
    {
    //delete at first
    Slist *temp=*head;
    *head=temp->link;
    free(temp);
    return SUCCESS;
    }
}