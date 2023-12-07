#include "sll.h"

int sl_delete_list(Slist **head)
{
    //check whether the head is empty or not
   if(*head==NULL)
    {
        return FAILURE;
    }
    else
    {
        //to delete the all list until the cond false
        while(*head != NULL)
        {
            Slist *temp=*head; //1st get the head address in temp 
            *head=temp->link; //change the head value to next node address
            free(temp);//deallocate the temp node
            
        }
         return SUCCESS;
    }
}