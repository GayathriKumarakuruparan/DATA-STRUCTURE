#include "inverted_search.h"

void display_database(Wlist *head[])
{
    /* printing contents in the database */
    printf("\n[index]   [word]  file_count file/s File:file_name word_count\n");
    for(int i = 0; i < 27; i++)
    {
        if(head[i])
        {
            print_word_count(head[i]);          //calling function to print the word count
        }
    }
}

int print_word_count(Wlist *head)
{
    while(head)
    {
        printf(" [%d]     [%s]     %d file/s: ", tolower(head->word[0]) % 97, head->word, head->file_count);
        
        Ltable *T_head = head->Tlink;

        while(T_head)
        {
            printf(" File: %s    %d", T_head->file_name, T_head->word_count);
            T_head = T_head->table_link;
        }
        printf("\n");
        head = head->link;
    }
    return SUCCESS;
}