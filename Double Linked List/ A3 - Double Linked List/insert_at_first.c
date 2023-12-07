#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    /* create temp node */
    Dlist *temp=*head;
    
    /*create new node*/
    Dlist *new=malloc(sizeof(Dlist));
    
    /* error check */
    if(new==NULL)
    {
        return FAILURE;
    }
    
    /* Fill the node */
    new->data=data;
    new->next=temp;
    new->prev=NULL;
    *head=new;
    return SUCCESS;
}