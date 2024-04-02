#include <stdio.h>

int
main ()
{
  int arr[5] = { 25, 43, 75, 8, 10 };
  int current_min, current_item;
  for (int i = 0; i < 5; i++)
	{
	  current_min = i;
	  for (current_item = i + 1; current_item < 5; current_item++)
		{
		  if (arr[current_item] < arr[current_min])
			{
			  current_min = current_item;
			}
		}
	  if (current_min != i)
		{
		  int temp = arr[current_min];
		  arr[current_min] = arr[i];
		  arr[i] = temp;
		}

	}
  for (int i = 0; i < 5; i++)
	{
	  printf ("%d ", arr[i]);
	}
}
