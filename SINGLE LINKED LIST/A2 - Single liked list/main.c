/*
Name                    :   GAYATHRI.K
Date                    :   05.12.2023
Description             :   Single linked list basic operations
Sample execution        :   Implement the functions given below.
                                
                                insert_after(head, gdata, ndata)
                                insert_before(head, gdata, ndata)
                                delete_element(head, gdata)
                                insert_Nth(head, ndata, n)
                                
                                1. insert_after :
                                Input : 
                                head → pointer to first node.
                                gdata → given data (should be present in the list).
                                ndata → data to be inserted in the list after gdata.
                                Cases : 
                                List Empty
                                List Non-Empty
                                Given data present
                                Given data not present
                                Case-1
                                
                                List Empty
                                
                                Input
                                
                                Head = NULL
                                
                                Output
                                
                                return LIST_EMPTY
                                
                                Case-2
                                Sub-case:1
                                
                                List Non-Empty
                                Given data present
                                
                                Case-2
                                Sub-case:2
                                
                                List Non-Empty
                                Given data not present
                                
                                
                                
                                Example
                                
                                If given_data = 40, new_data = 45
                                
                                Example
                                
                                If given_data = 60, new_data = 45
                                
                                
                                
                                Input
                                
                                10 → 20 → 30 → 40 → 50
                                
                                Input
                                
                                10 → 20 → 30 → 40 → 50
                                
                                
                                
                                Output
                                
                                10 → 20 → 30 → 40 → 45 → 50
                                
                                Output
                                
                                Return DATA_NOT_FOUND
                                
                                
                                
                                Prototype
                                
                                int sl_insert_after(Slist *head, data_t g_data, data_t n_data);
                                
                                head
                                
                                : Pointer to the first node
                                
                                g_data
                                
                                : Given data
                                
                                n_data
                                
                                : New data to be inserted into the list
                                
                                return value
                                
                                : status (LIST_EMPTY, SUCCESS, DATA_NOT_FOUND)
                                
                                
                                2. insert_before
                                Input : 
                                head → pointer to first node.
                                gdata → given data (should be present in the list).
                                ndata → data to be inserted in the list before gdata.
                                Cases : 
                                List Empty
                                List Non-Empty
                                Given data present
                                Given data not present
                                Case-1
                                
                                List Empty
                                
                                Input
                                
                                Head = NULL
                                
                                Output
                                
                                return LIST_EMPTY
                                
                                Case-2
                                Sub-case:1
                                
                                List Non-Empty
                                Given data present
                                
                                Case-2
                                Sub-case:2
                                
                                List Non-Empty
                                Given data not present
                                
                                
                                
                                Example
                                
                                If given_data = 40, new_data = 45
                                
                                Example
                                
                                If given_data = 60, new_data = 45
                                
                                
                                
                                Input
                                
                                10 → 20 → 30 → 40 → 50
                                
                                Input
                                
                                10 → 20 → 30 → 40 → 50
                                
                                
                                
                                Output
                                
                                10 → 20 → 30 → 45 → 40 → 50
                                
                                Output
                                
                                Return DATA_NOT_FOUND
                                
                                
                                
                                Prototype
                                
                                int sl_insert_before(Slist *head, data_t g_data, data_t n_data);
                                
                                head
                                
                                : Pointer to the first node
                                
                                g_data
                                
                                : Given data
                                
                                n_data
                                
                                : New data to be inserted into the list
                                
                                return value
                                
                                : status (LIST_EMPTY, SUCCESS, DATA_NOT_FOUND)
                                
                                
                                
                                3. delete_element :
                                
                                Description
                                
                                Write a function to delete the given data in the single linked list.
                                
                                Cases
                                
                                List Empty
                                List Non-Empty
                                Given data present
                                Given data not present
                                Case-1
                                
                                List Empty
                                
                                Input
                                
                                Head = NULL
                                
                                Output
                                
                                return LIST_EMPTY
                                
                                Case-2
                                Sub-case:1
                                
                                List Non-Empty
                                Given data present
                                
                                Case-2
                                Sub-case:2
                                
                                List Non-Empty
                                Given data not present
                                
                                
                                
                                Example
                                
                                If given_data = 40
                                
                                Example
                                
                                If given_data = 60
                                
                                
                                
                                Input
                                
                                10 → 20 → 30 → 40 → 50
                                
                                Input
                                
                                10 → 20 → 30 → 40 → 50
                                
                                
                                
                                Output
                                
                                10 → 20 → 30 → 50
                                
                                Output
                                
                                Return DATA_NOT_FOUND
                                
                                
                                
                                Prototype
                                
                                int sl_delete_element(Slist **head, data_t g_data);
                                
                                head
                                
                                : Pointer to the first node
                                
                                g_data
                                
                                : Given data
                                
                                return value
                                
                                : status (LIST_EMPTY, SUCCESS, DATA_NOT_FOUND)
                                
                                
                                
                                4. insert_Nth :
                                
                                Description
                                
                                Write a function to insert the given data exactly at the ‘n’ position in the single linked list.
                                
                                Cases
                                
                                List Empty
                                List Non-Empty
                                
                                Given ‘n’th position present
                                Given ‘n’th position not present
                                Case-1
                                
                                List Empty
                                
                                Input
                                
                                Head = NULL
                                
                                Output
                                
                                return LIST_EMPTY
                                
                                Case-2
                                Sub-case:1
                                
                                List Non-Empty
                                Given data present
                                
                                Case-2
                                Sub-case:2
                                
                                List Non-Empty
                                Given data not present
                                
                                
                                
                                Example
                                
                                If n = 3, n_data = 23
                                
                                Example
                                
                                If n = 10, n_data = 23
                                
                                
                                
                                Input
                                
                                10 → 20 → 30 → 40 → 50
                                
                                Input
                                
                                10 → 20 → 30 → 40 → 50
                                
                                
                                
                                Output
                                
                                10 → 20 → 23 → 30 →40 → 50
                                
                                Output
                                
                                Return POSITION_NOT_FOUND
                                
                                
                                
                                Prototype
                                
                                int sl_insert_Nth(Slist **head, data_t ndata, int n);
                                
                                head
                                
                                : Pointer to the first node
                                
                                n
                                
                                : Position number
                                
                                ndata
                                
                                : New data, to be inserted into the list
                                
                                return value
                                
                                : status (LIST_EMPTY, SUCCESS, POSITION_NOT_FOUND)


*/
#include "sll.h"

int main()
{

	int option, ndata, gdata, ret, n;


	Slist *head = NULL; //initialize the header to NULL

	printf("1.Insert at first\n2.Insert after\n3.Insert before\n4.Insert Nth\n5.Delete element\n6.Print list\n7. Exit\nEnter any option : ");
	while(1)
	{

		/*ask user options*/

		scanf("%d", &option);

		switch (option)
		{
			case 1:
				printf("Enter the number you have to insert : ");
				scanf("%d", &ndata);
				if (insert_at_first(&head, ndata) == FAILURE)
				{
					printf("INFO : Insert first failure\n");
				}

				break;
			case 2:
				printf("Enter the value of gdata : ");
				scanf("%d", &gdata);
				printf("Enter the ndata that you want to insert after %d : ", gdata);
				scanf("%d", &ndata);
				/*insert_at_last function call*/
				if ((ret = sl_insert_after(&head, gdata, ndata)) == DATA_NOT_FOUND) //pass by reference
				{
					printf("INFO : %d is not found at the list\n", gdata);
				}
				else if (ret == LIST_EMPTY)
				{
					printf("INFO : List is empty\n");
				}

				break;
			case 3:
				printf("Enter the value of gdata : ");
				scanf("%d", &gdata);
				printf("Enter the ndata that you want to insert before %d : ", gdata);
				scanf("%d", &ndata);
				/*insert_at_last function call*/
				if ((ret = sl_insert_before(&head, gdata, ndata)) == DATA_NOT_FOUND) //pass by reference
				{
					printf("INFO %d is not found at the list\n", gdata);
				}
				else if (ret == LIST_EMPTY)
				{
					printf("INFO : List is empty\n");
				}


				break;
			case 4:
				printf("Enter the node number : ");
				scanf("%d", &n);
				printf("Enter the number that you want to insert %dth position : ", n);
				scanf("%d", &ndata);
				/*insert_at_last function call*/
				if ((ret = sl_insert_nth(&head, ndata, n)) == POSITION_NOT_FOUND)//pass by reference
				{
					printf("INFO : %d Position not found\n", n);
				}
				else if (ret == LIST_EMPTY)
				{
					printf("INFO : List is empty\n");
				}
				else
				{
					printf("%d is successfully inserted at the position %d\n", ndata, n);
				}
				break;
			case 5:
				// To delete the element
				printf("Enter the element you need to delete : ");
				scanf("%d", &ndata);
				if ((ret = sl_delete_element(&head, ndata)) == DATA_NOT_FOUND)
				{
					printf("INFO : Element is not found\n");
				}
				else if (ret == FAILURE)
				{
					printf("INFO : List is empty\n");
				}
				else
				{
					printf("Element Successfully deleted\n");
				}
				break;
			case 6:
				print_list(head);
				break;
			case 7:
				return SUCCESS;

			default: printf("Enter proper choice !!\n");
					 break;
		}
	}

	return SUCCESS;
}