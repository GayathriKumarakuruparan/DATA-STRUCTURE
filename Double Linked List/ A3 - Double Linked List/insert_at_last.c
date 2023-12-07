#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
     /*create new node*/
    Dlist *new=malloc(sizeof(Dlist));
    
     /* create temp node */
    Dlist *temp=*head;
    
      /* error check */
    if(new==NULL)
    {
        return FAILURE;
    }
     /* Fill the node */
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    
    /* if it is empty */
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    /* if not */
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
         /* Fill the node */
        new->prev=temp;
        temp->next=new;
        *tail=new;
        return SUCCESS;
    }
}