/*
Name                    :   GAYATHRI.K
Date                    :   06.12.2023
Description             :   Single linked list basic operations
Sample execution        :   Implement functions given below :
                            1. dll_insert_after(head, tail, gdata, ndata)
                            2. dll_insert_before(head, gdata, ndata)
                            3. dll_delete_element(head, tail, gdata)
                             emertxe@ubuntu:~/ECEP/DS/Assign4$ ./out.exe
                            1. Insert first
                            2. Insert before
                            3. Insert after
                            4. Delete element
                            5. Print list
                            6. Exit
                            Enter your choice : 1
                            Enter the data you have to insert : 2
                            1
                            Enter the data you have to insert : 4
                            5
                            Head -> 2 <-> 4 <- Tail
                            3
                            Enter the gdata : 4
                            Enter the number you have to insert after 4 : 5
                            INFO : Insert after Successfull
                            2
                            Enter the gdata : 2
                            Enter the number you have insert before 2 : 1
                            INFO : Insert before Successfull
                            5
                            Head -> 1 <-> 2 <-> 4 <-> 5 <- Tail
                            4
                            Enter the element you have to delete : 4
                            INFO : Delete element Successfull
                            5
                            Head -> 1 <-> 2 <-> 5 <- Tail
                            6
                            emertxe@ubuntu:~/ECEP/DS/Assign4$
*/
#include "dll.h"

int main()
{
	int option, data, gdata, ret;


	Dlist *head = NULL; /* initialize the header to NULL */
	Dlist *tail = NULL; /* initialize the tail to NULL */

	printf("1. Insert first\n2. Insert before\n3. Insert after\n4. Delete element\n5. Print list\n6. Exit\nEnter your choice : ");
	while(1)
	{

		/*ask user options*/
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				/* To insert the element at last */
				printf("Enter the data you have to insert : ");
				scanf("%d", &data);

				/* If the return value is 0 link sucess else not success */
				if (dl_insert_last(&head, &tail, data) == -1)
				{
					printf("INFO : Insert last Failure\n");
				}
				break;
			case 2:
				/* To insert the element before a number present in the list */
				printf("Enter the gdata : ");
				scanf("%d", &gdata); /* Scaning the number */
				printf("Enter the number you have insert before %d : ", gdata);

				/* Scaning the new number to insert */
				scanf("%d", &data);

				/* If the link is Success it retuns 0 else it returns -1 */
				if ((ret = dl_insert_before(&head, &tail, gdata, data)) == LIST_EMPTY)
				{
					printf( "INFO : List Empty\n" );
				}
				else if (ret == DATA_NOT_FOUND)
				{
					printf( "INFO : Data not found\n" );
				}
				else 
				{
					printf( "INFO : Insert before Successfull\n" );
				}
				break;
			case 3:
				/* To insert the element after the number present in the list */
				printf("Enter the gdata : ");
				scanf("%d", &gdata);/* Scaning the existing number */
				printf("Enter the number you have to insert after %d : ", gdata);

				/* Scaning the new number to insert */
				scanf("%d", &data); 

				/* If the link is Success it will return 0 else it will return -1 */
				if ((ret = dl_insert_after(&head, &tail, gdata, data)) == LIST_EMPTY)
				{
					printf( "INFO : List Empty\n" );
				}
				else if (ret == DATA_NOT_FOUND)
				{
					printf( "INFO : Data not found\n" );
				}
				else 
				{
					printf( "INFO : Insert after Successfull\n" );
				}
				break;
			case 4:
				/* To delete the element present in the list */
				printf("Enter the element you have to delete : ");
				scanf("%d", &data); /* Scaning the number to delete */

				/* If the delete is completed it will return 0 else it will return -1 */
				if ((ret = dl_delete_element(&head, &tail, data)) == LIST_EMPTY)
				{
					printf( "INFO : List Empty\n" );
				}
				else if (ret == DATA_NOT_FOUND)
				{
					printf( "INFO : Data not found\n" );
				}
				else 
				{
					printf( "INFO : Delete element Successfull\n" );
				}
				break;
			case 5:
				/* Calling the function to print the list */
				print_list(head);
				break;
			case 6:
				return SUCCESS;

			default: printf("Enter proper choice !!\n");
					 break;
		}

	}

	return SUCCESS;
}