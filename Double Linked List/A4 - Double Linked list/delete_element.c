#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{	
    Dlist *temp=*head;
    Dlist *previous;//to get previous node
    Dlist *Next;//to get next node 
    if(*head==NULL)
    {
        return LIST_EMPTY;
    }
    //traverse through all node
    while(temp!=NULL)
    {
        if(temp->data!=data)
        {
            previous=temp;
            temp=temp->next;
        }
        else
        {
            //if only one node is present
            if(*head==*tail)
            {
                *head=NULL;
                *tail=NULL;
                free(temp);
                return SUCCESS;
            }
            
            else
            {
                //if last node
                if(temp->next==NULL)
                {
                    previous->next=NULL;
                    *tail=previous;
                    free(temp);
                    return SUCCESS;
                }
                //if 1st node
                else if(temp->prev==NULL)
                {
                    Next=temp->next;
                    Next->prev=NULL;
                    *head=Next;
                    free(temp);
                    return SUCCESS;
                }
                //if other node
                else
                {
                    Next=temp->next;
                    previous->next=temp->next;
                    Next->prev=previous;
                    free(temp);
                    return SUCCESS;
                }
               
            }
        }
    }
    //if the data not found
    return DATA_NOT_FOUND;
}