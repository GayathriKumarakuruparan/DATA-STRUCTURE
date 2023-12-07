#include "sll.h"
/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) 
{ 
  /* check the node is empty or not */
 if(head==NULL)
    {
        return LIST_EMPTY;
    }
    
    //if pos is 0 is invalid
    if(pos==0)
    {
        return FAILURE;
    }
    
    /* two pointers to get the output in one traverse */
    Slist *temp1=head;
    Slist *temp2=head;
    while(temp1!=NULL)
    {
        
        temp1=temp1->link;
        if(pos!=0)
        {
            pos--;    
        }
        else
        {
           temp2=temp2->link;
        }
      
    }
    
    //if the pos is not found
    if(pos != 0)
    {
       return FAILURE;  //POSITION NOT FOUND
    }
    else
    {
        *data=temp2->data;
        return *data;
    }
} 