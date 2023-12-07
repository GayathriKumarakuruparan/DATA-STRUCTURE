#include "sll.h"

int sl_delete_last(Slist **head)
{
    //check whether the head is empty or not
    if(*head==NULL)
    {
        return LIST_EMPTY;
    }
    
    /*to check it has 1 node or more
    if only one node*/
    Slist *temp=*head;
   if (temp->link==NULL)
   {
       free(temp);
       *head=NULL;
       return SUCCESS;
   }
   
   //more than one node
   else
    {
    Slist *previous;//the set the link null for last node after deletion
    while(temp->link!=NULL)
    {
        previous=temp;
        temp=temp->link;
    }
    previous->link=NULL;
    free(temp);
    return SUCCESS;
    }
}