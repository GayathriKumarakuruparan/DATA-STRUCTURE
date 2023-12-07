#include "sll.h"

int insert_at_last(Slist **head, data_t data)
{
    //create the node
    Slist *new=malloc(sizeof(Slist));
    
    //error check
    if(new==NULL)
    {
        return FAILURE;
    }
        new->data=data;
        new->link=NULL;
    
    //check the head is empty or not
    if(*head==NULL)
    {
        *head=new;
        return SUCCESS;
    }
    
     //insert at last
    Slist *temp=*head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
     temp->link=new;
     return SUCCESS; 

}