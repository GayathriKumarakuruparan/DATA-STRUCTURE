#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
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
            /* Fill the parts of the node */
            else
            {
                new->data=ndata;
                new->link=temp->link;
                temp->link=new;
                return SUCCESS;
            }
        }
    }
    return DATA_NOT_FOUND;
}