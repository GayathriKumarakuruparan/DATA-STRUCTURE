/*
Name                    :   GAYATHRI.K
Date                    :   05.12.2023
Description             :   Single linked list basic operations
Sample execution        :   Implement the functions given below.
                                
                                insert_after(head, gdata, ndata)
                                insert_before(head, gdata, ndata)
                                delete_element(head, gdata)
                                insert_Nth(head, ndata, n)
*/
#ifndef SLL_H
#define SLL_L

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND -2
#define LIST_EMPTY -4
#define POSITION_NOT_FOUND -3
typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *link;
}Slist;
int insert_at_first(Slist **head, data_t data);
int sl_insert_after(Slist **head, data_t , data_t);
int sl_insert_before(Slist **head, data_t , data_t );
int sl_insert_nth(Slist **head, data_t , data_t);
int sl_delete_element(Slist **head, data_t);
void print_list(Slist *head);
#endif