/*
Name                    :   GAYATHRI.K
Date                    :   06.12.2023
Description             :   Implementation of stack using array
Sample execution        :   1. Push
                            2. Pop
                            3. Display Stack
                            4. Peek(Element at Top)
                            5. Exit
                            Enter your choice : 1
                            Enter the element to be pushed in stack : 23
                            1
                            Enter the element to be pushed in stack : 45
                            1
                            Enter the element to be pushed in stack : 42
                            2
                            INFO : Pop operation is successfull
                            3
                            Top -> 45 23
                            4
                            INFO : Peek element is 45
                            2
                            INFO : Pop operation is successfull
                            3
                            Top -> 23
                            2
                            INFO : Pop operation is successfull
                            3
                            INFO : Stack is empty
                            4
                            INFO : Stack is empty
                            1
                            Enter the element to be pushed in stack : 2
                            1
                            Enter the element to be pushed in stack : 2
                            1
                            Enter the element to be pushed in stack : 23
                            1
                            Enter the element to be pushed in stack : 45
                            1
                            Enter the element to be pushed in stack : 67
                            1
                            Enter the element to be pushed in stack : 34
                            INFO : Stack Full
                            3
                            Top -> 67 45 23 2 2
                            4
                            INFO : Peek element is 67
                            5
                            emertxe@ubuntu:~/ECEP/DS/Assign11$
*/
#include "stack.h"

int main()
{
	int option, data, peek;

	/* Initiallising the top as NULL */
	Stack_t *top = NULL;

	printf("1. Push\n2. Pop\n3. Display Stack\n4. Peek(Element at Top)\n5. Exit\nEnter choice: ");

	while (1)
	{

		/*ask user options*/
		scanf("%d", &option);

		switch (option)
		{
			case 1:

				/* To Push the element */
				printf("Enter the element you have to insert at the first : ");
				scanf("%d", &data);
				if ((Push(&top, data)) == FAILURE)
				{
					printf("INFO : Push operation Failure\n");
				}
				break;
			case 2:

				/* To Pop the top of the value in the stack */
				if ((Pop(&top)) == FAILURE)
				{
					printf("INFO : Stack is empty\n");
				}
				else
				{
				    printf("INFO : Pop operation is successfull\n");
				}
				break;
			case 3:
				/* Printing or Dispaying the elements */
				Peep(top);
				break;
			case 4:
				/* To find the Peek element in the stack */
				if ((peek = Peek(&top)) == FAILURE)
				{
					printf("INFO : Stack is empty\n");
				}
				else
				{
					printf("INFO : Peek element is %d\n", peek);
				}
				break;
			case 5:
				return SUCCESS;

			default:
				printf("Enter proper choice !!\n");
				break;
		}

	}

	return SUCCESS;
}