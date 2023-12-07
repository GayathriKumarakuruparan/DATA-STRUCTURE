#include "sll.h"

int insert_at_first(Slist **head, data_t data)
{
    //create a node
	Slist *new=malloc(sizeof(Slist));
	
	//error check
    if(new==NULL)
    {
        return FAILURE;
    }
    
    //check whether the head is empty or not
    if(*head==NULL)
    {
        *head=new;
        new->data=data;
        new->link=NULL;
        return SUCCESS;
    }
    
    //insert at first
    else
    {
        new->link=*head;
        new->data=data;
        *head=new;
         return SUCCESS; 
    }
}