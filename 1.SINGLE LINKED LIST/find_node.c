#include "sll.h"

int find_node(Slist *head, data_t data)
{

	int count=1;
	//check whether the head is empty or not
	if(head == NULL)
	{
	    return LIST_EMPTY;
	}
	else
	{
	    //find node
	    Slist *temp=head;
	    while(temp!=NULL)
	    {
    	if(data==temp->data)//to check the given data and placed data are same or not
    	{
    	    return count;
    	}
    	else
    	{
    	   temp=temp->link;
    	   count++;
    	}
    	
	    }
	    return DATA_NOT_FOUND;//if the data is not found
	}
}
