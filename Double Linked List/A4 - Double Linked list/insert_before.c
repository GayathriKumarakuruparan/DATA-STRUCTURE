#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    	//Allocating the memory for new node
    Dlist *new=malloc(sizeof(Dlist));
    
    Dlist *temp=*head;
    Dlist *previous;
    if(*head==NULL)
    {
       return LIST_EMPTY;
    }
    // If the node is not created the returning failure
    if(new==NULL)
    {
        return FAILURE;
    }
        new->data=ndata;
        new->prev=NULL;
        new->next=NULL;

       //traverse through all the node
        while((temp!=NULL))
        {
            
           if(temp->data!=gdata)
           {
               previous=temp;
               temp=temp->next;;
           }
           else
            {
                //if not 1st node
                if(temp!=*head)
                {
                    new->next=temp;
                    new->prev=previous;
                    temp->prev=new;
                    previous->next=new;
                    return SUCCESS;
                    
                }
                //if 1st node
                else
                {
                    new->prev=NULL;
                    new->next=temp;
                    *head=new;
                    temp->prev=new;
                    return SUCCESS;
                }
            }
            
        
    }
    return DATA_NOT_FOUND;
}