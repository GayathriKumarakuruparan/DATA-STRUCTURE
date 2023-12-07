#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    Slist *previous;
    /* If list is empty */
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    Slist *temp=*head;
    while(temp != NULL)
    {
        if(g_data!=temp->data)
        {
            previous=temp;
            temp=temp->link;
        }
        else
        {
            /* Creating the new node */
            Slist *new=malloc(sizeof(Slist));
            if(new==NULL)
            {
                return FAILURE;
            }
            else
            {
                if(*head == temp)
                {
                    /* Fill the parts of the node */
                    new->data=ndata;
                    new->link=temp;
                    *head=new;
                    return SUCCESS;
                }
                else
                {
                    /* Fill the parts of the node */
                    new->data=ndata;
                    new->link=temp;
                    previous->link=new;
                    return SUCCESS;
                }
            }
        }
    }
    return DATA_NOT_FOUND;
}