#include "sll.h"
/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{ 
    /* check the node is empty or not */
    if(head==NULL)
    {
        return LIST_EMPTY;
    }
    
    /* two pointers to get the output in one traverse */
    Slist *fast=head;
    Slist *slow=head;
    /* simultaneously check node is odd or even */
    while((fast!=NULL)&&(fast->link!=NULL))
    {
        fast=fast->link->link;
        slow=slow->link;
    }
    *mid=slow->data;
    return *mid;

} 