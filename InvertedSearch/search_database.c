#include "inverted_search.h"

void search(Wlist *head, char *word)
{
    /* declaring a variable and initializing it with 1 */
    int flag = 1;
    /*if head is null printing list empty */
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        /* traversing through the list */
        while(head)
        {
            if(!(strcmp(head->word, word)))
            {
                /* if word is found then setting flag to 0 */
                flag = 0;
                printf("Word %s is found at %d files \n", word, head->file_count);
                Ltable *T_head = head->Tlink;
                while (T_head)
                {
                    printf("In file : %s %d times\n", T_head->file_name, T_head->word_count);
                    T_head = T_head->table_link;
                }
                printf("\n");
            }
            head = head->link;
        }
    }
    /* if flag value is unmodified then printing word not found */
    if(flag == 1)
    {
        printf("%s is not found in the list\n", word);
    }

}