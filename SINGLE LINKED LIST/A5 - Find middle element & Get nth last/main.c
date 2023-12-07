/*
Name                    :   GAYATHRI.K
Date                    :   07.12.2023
Description             :   Find mid element and get nth last of single linked list 
Sample execution        :   emertxe@ubuntu:~/ECEP/DS/Assign5$ ./out.exe
                            1. Insert at last
                            2. Find Mid
                            3. Find Nth last
                            4. Print list
                            5. Exit
                            Enter the Option : 1
                            Enter the number that you want to insert at last: 10
                            1
                            Enter the number that you want to insert at last: 20
                            1
                            Enter the number that you want to insert at last: 30
                            1
                            Enter the number that you want to insert at last: 40
                            3
                            Enter the Number to find the last : 1
                            1th last is 40
                            3
                            Enter the Number to find the last : 4
                            4th last is 10
                            1
                            Enter the number that you want to insert at last: 50
                            3
                            Enter the Number to find the last : 6
                            INFO : Position not found
                            1
                            Enter the number that you want to insert at last: 60
                            3
                            Enter the Number to find the last : 9
                            INFO : Position not found
                            3
                            Enter the Number to find the last : 0
                            INFO : Position not found
                            5
                            emertxe@ubuntu:~/ECEP/DS/Assign5$ ./out.exe
                            1. Insert at last
                            2. Find Mid
                            3. Find Nth last
                            4. Print list
                            5. Exit
                            Enter the Option : 2
                            INFO : List is empty
                            1
                            Enter the number that you want to insert at last: 10
                            2
                            Middle element is 10
                            1
                            Enter the number that you want to insert at last: 20
                            2
                            Middle element is 20
                            1
                            Enter the number that you want to insert at last: 30
                            1
                            Enter the number that you want to insert at last: 40
                            2
                            Middle element is 30
                            1
                            Enter the number that you want to insert at last: 50
                            1
                            Enter the number that you want to insert at last: 60
                            4
                            10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL
                            2
                            Middle element is 40
                            5
                            emertxe@ubuntu:~/ECEP/DS/Assign5$
*/   
#include "sll.h"

int main()
{
	char check_char;
	int option, data, pos;
    int key;

	Slist *head = NULL; //initialize the header to NULL


	printf("1. Insert at last\n2. Find Mid\n3. Find Nth last\n4. Print list \n5. Exit\nEnter the Option : ");
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
					printf("INFO : Insert last failed\n");
				}
				break;

			case 2:{
					   int mid;
					   if ((find_mid(head, &mid)) == LIST_EMPTY)
					   {
						   printf("INFO : List is empty\n");
					   }
					   else 
					   {
						   printf("Middle element is %d\n", mid);
					   }
				   }
				   break;
			case 3:
				   printf("Enter the Number to find the last : ");
				   scanf("%d", &pos);
				   if ((key = find_nth_last(head, pos, &data)) == FAILURE)
				   {
					   printf("INFO : Position not found\n");
				   }
				   else if (key == LIST_EMPTY)
				   {
				        printf("INFO : List is empty");
				   }
				   else 
				   {
					   printf("%dth last is %d\n", pos, data);
				   }
				   break;
			case 4:
				   /* print list function call*/
				   print_list(head);
				   break;
			case 5:
				   return SUCCESS;
			default:
				   printf("Invalid Option\n");
		}


	}

	return SUCCESS;
}