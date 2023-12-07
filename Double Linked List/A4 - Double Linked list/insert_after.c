#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    Dlist *temp=*head;
    Dlist *Next;
    //empty or not
    if(*head==NULL)
    {
        return LIST_EMPTY;
    }
    else
    {
        	//Allocating the memory for new node
        Dlist *new=malloc(sizeof(Dlist));
        
        // If the node is not created the returning failure
        if(new==NULL)
        {
            return FAILURE;
        }
        new->data=ndata;
        new->prev=NULL;
        new->next=NULL;
        //traverse through all node
        while(temp!=NULL)
        {
            if(temp->data!=gdata)
            {
                temp=temp->next;
            }
            else
            {
                Next=temp->next;
                //if not last node
                if(temp!=*tail)
                {
                    new->prev=temp;
                    new->next=Next;
                    temp->next=new;
                    Next->prev=new;
                    return SUCCESS;
                }
                //if last node
                else
                {
                    temp->next=new;
                    new->prev=temp;
                    new->next=NULL;
                    *tail=new;
                    return SUCCESS;
                }
            }
        }
        return DATA_NOT_FOUND;
    }
}