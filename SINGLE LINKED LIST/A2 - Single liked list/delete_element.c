#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    Slist *temp=*head;
    Slist *previous;
    Slist *new=malloc(sizeof(Slist));
    /* If list is empty */
    while(*head!=NULL)
    {
    if(temp->data==data)
    {
        if(*head==temp)
        {
            *head=temp->link;
            free(temp);
            return SUCCESS;
        }
        else
        {
            //Slist *previous=temp;
            previous->link=temp->link;
            free(temp);
            return SUCCESS;
        }

    }
    else
    {
        previous=temp;
        temp=temp->link;
    }
    }
    return FAILURE;
}