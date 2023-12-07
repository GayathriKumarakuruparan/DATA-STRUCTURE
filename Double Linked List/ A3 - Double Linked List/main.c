/*
Name                    :   GAYATHRI.K
Date                    :   06.12.2023
Description             :   Double linked list basic operations
Sample execution        :   emertxe@ubuntu:~/ECEP/DS/Assign3$ ./out.exe
                            
                            1. Dll Insert last
                            2. Dll Insert first
                            3. Dll delete Last
                            4. Dll delete first
                            5. Dll delete list
                            6. Print list
                            7. Exit
                            Enter your option: 1
                            Enter the number that you want to insert at last: 100
                            2
                            Enter the element you have to insert at the first : 1
                            2
                            Enter the element you have to insert at the first : 67
                            1
                            Enter the number that you want to insert at last: 21
                            1
                            Enter the number that you want to insert at last: 45
                            6
                            Head -> 67 <-> 1 <-> 100 <-> 21 <-> 45 <- Tail
                            3
                            INFO : Delete last Successfull
                            4
                            INFO : Delete first Successfull
                            6
                            Head -> 1 <-> 100 <-> 21 <- Tail
                            5
                            INFO : Delete list Successfull
                            6
                            INFO : List is empty
                            7
                            emertxe@ubuntu:~/ECEP/DS/Assign3$  
*/
#include "dll.h"

int main()
{

	int option, data;


	Dlist *head = NULL; //initialize the header to NULL
	Dlist *tail = NULL; //initialize the tail to NULL

	printf("\n1. Dll Insert last\n2. Dll Insert first\n3. Dll delete Last\n4. Dll delete first\n5. Dll delete list\n6. Print list\n7. Exit\nEnter your option: ");
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
				if (dl_insert_last(&head, &tail, data) == FAILURE) //pass by reference
				{
					printf("INFO : Insertion Failure\n");
				}
				break;
			case 2:
				/*To insert the element at first */
				printf("Enter the element you have to insert at the first : ");
				scanf("%d", &data);
				if (dl_insert_first(&head, &tail, data) == FAILURE)
				{
					printf("INFO : Insertion Failure\n");
				}
				break;

			case 3:
				/* Delete a last link*/
				if (dl_delete_last(&head, &tail) == FAILURE)
				{
					printf("INFO : Delete last Failure, List is empty\n");
				}
				else
				{
					printf("INFO : Delete last Successfull\n");
				}
				break;
			case 4:
				/*To delete first node */
				if (dl_delete_first(&head, &tail) == FAILURE)
				{
					printf("INFO : Delete first Failure, List is empty\n");
				}
				else
				{
					printf("INFO : Delete first Successfull\n");
				}
				break;
			case 5:
				/* Delete list */
				if (dl_delete_list(&head, &tail) == FAILURE)
				{
					printf("INFO : Delete list Failure, List is empty\n");
				}
				else
				{
					printf("INFO : Delete list Successfull\n");
				}
				break;
			case 6:
				/* print list function call*/
				print_list(head);
				break;
			case 7 : 
				return SUCCESS;
			default: printf("Enter proper choice !!\n");
					 break;
		}

	}

	return SUCCESS;
}