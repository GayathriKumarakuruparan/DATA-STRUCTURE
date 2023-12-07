#include "stack.h"

int Pop(Stack_t **top)
{
   /* creating temp to point top */
   Stack_t *temp = *top;

   /* checking list is empty */
   if(temp == NULL)
   {
       return FAILURE;
   }
   /*else freeing data in temp and updating top */
   else
   {
       *top = temp->link;
       free(temp);
   }
   return SUCCESS;
}