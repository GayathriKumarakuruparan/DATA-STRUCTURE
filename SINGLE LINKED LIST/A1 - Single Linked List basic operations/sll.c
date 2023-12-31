/*
Name                    :   GAYATHRI.K
Date                    :   05.12.2023
Description             :   Single linked list basic operations
Sample execution        :   emertxe@ubuntu:~/Desktop/assign1$ make
	     	                cc    -c -o print_list.o print_list.c
			                cc    -c -o sll.o sll.c
            			    cc    -c -o insert_at_first.o insert_at_first.c
            			    cc    -c -o insert_at_last.o insert_at_last.c
            			    cc    -c -o find_node.o find_node.c
            			    cc    -c -o delete_list.o delete_list.c
            			    cc    -c -o delete_at_first.o delete_at_first.c
            			    cc    -c -o delete_at_last.o delete_at_last.c
            			    gcc -o out.exe print_list.o sll.o insert_at_first.o insert_at_last.o find_node.o delete_list.o delete_at_first.o delete_at_last.o
            			    emertxe@ubuntu:~/Desktop/assign1$ ./out.exe
            			    1. Insert last
            	  		    2. Insert first
            			    3. Delete Last
            			    4. Delete first
            			    5. Delete list
            			    6. Find node
            			    7. Print list
            		  	    8. Exit
            			    Enter your choice : 1
            			    Enter the number that you want to insert at last: 45
            			    2
            			    Enter the element you have to insert at the first : 43
            			    1
            			    Enter the number that you want to insert at last: 56
            			    7
            			    43 -> 45 -> 56 -> NULL
            			    3
            			    INFO : Delete last successfull
            			    7
            			    43 -> 45 -> NULL
            			    4
            			    INFO : Delete first successfull
            			    7
            			    45 -> NULL
            			    1
            			    Enter the number that you want to insert at last: 67
            			    1
            			    Enter the number that you want to insert at last: 89
            			    7
            			    45 -> 67 -> 89 -> NULL
            			    6
            			    Enter the key to find : 67
                			    67 found in the list at the position 2
            			    6
            			    Enter the key to find : 45
            			    45 found in the list at the position 1
            			    6
            			    Enter the key to find : 89
            			    89 found in the list at the position 3
            			    6
            			    Enter the key to find : 55
            			    INFO : Failure
            			    List is empty or Key not found
            			    8
              			    emertxe@ubuntu:~/Desktop/assign1$ 

*/
#include "sll.h"

int main()
{
	
	int option, data, key;


	Slist *head = NULL; //initialize the header to NULL

	printf("1. Insert last\n2. Insert first\n3. Delete Last\n4. Delete first\n5. Delete list\n6. Find node\n7. Print list\n8. Exit\nEnter your choice : ");

	while (1)
	{

		/*ask user options*/

		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				printf("Enter the number that you want to insert at last: ");
				scanf("%d", &data);
			
                
				/*insert_at_last function call*/
				if (insert_at_last(&head, data) == FAILURE) //pass by reference
				{
					printf("INFO : Insertion Failure\n");
				}
				break;
			case 2:
				/*To insert the element at first */
				printf("Enter the element you have to insert at the first : ");
				scanf("%d", &data);
				
				if (insert_at_first(&head, data) == -1)
				{
					printf("INFO : Insertion Failure\n");
				}
				break;

			case 3:
				/* Delete a last link*/
				if (sl_delete_last(&head) == -1)
				{
					printf("INFO : Delete last Failure\nList is empty\n");
				}
				else
				{
				    printf("INFO : Delete last successfull\n");
				}
			
				break;
			case 5:
				/* Delete list */
				if (sl_delete_list(&head) == -1)
				{
					printf("INFO : Delete list Failure\nList is empty\n");
				}
				else
				{
					printf("INFO : Delete list Successfull\n");
				}
	
				break;
			case 4:
				/*To delete first node */
				if (sl_delete_first(&head))
				{
					printf("INFO : Delete first Failure\n List is empty\n");
				}
				else
				{
				    printf("INFO : Delete first successfull\n");
				}
				break;
			case 6:
				printf("Enter the key to find : ");
				scanf("%d", &key);
				int count;
				if ((count = find_node(head, key)) == FAILURE)
				{
					printf("INFO : Failure\nList is empty or Key not found\n");
				}
				else
				{
					printf("%d found in the list at the position %d\n", key, count);
				}
		
				break;
			case 7:
				/* print list function call*/
				print_list(head);
					break;
	
			case 8:
				return SUCCESS;
			default: printf("Enter proper choice !!\n");
			
					 break;
		}
	    

	}
}

