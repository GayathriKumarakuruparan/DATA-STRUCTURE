#include "inverted_search.h"

char *fname;

void create_database(Flist *f_head, Wlist *head[])
{
    /* traversing through file linked list */
    while(f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        printf("Successfull: Creation of database for file : %s\n", f_head->file_name);
        f_head = f_head->link;
    }
}

Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    /* open file */
    FILE *fptr = fopen(filename, "r");
    char word[WORD_SIZE];
    int flag = 1;
    fname = filename;
    
    while((fscanf(fptr, "%s", word)) != EOF)
    {
        /* index */
        int index = tolower(word[0]) % 97;

        /* other than alphabets */
        if( !(index >= 0 && index <= 25))
        {
            index = 26;
        }
        if(head[index] != NULL)
        {
            Wlist *temp = head[index];
            /* compare words at each node with new words */
            while(temp)
            {
                if(!strcmp(temp->word, word))
                {
                    update_word_count(&temp, filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }
        if((flag == 1) || (head[index] == NULL))
        {
            /* function is called when words are unique */
            insert_at_last(&head[index], word);
        }  
    }
    return SUCCESS;
}

int update_word_count(Wlist ** head, char * file_name)
{
    
    Ltable *temp = (*head)->Tlink;
    /* traversing through the list and incrementing word count if same word is found */
    while(temp->table_link)
    {
        if((strcmp(temp->file_name, file_name)) == 0)
        {
            (temp->word_count)++;
            return SUCCESS;
        }
        temp = temp->table_link;
    }
    
    /* checking and incrementing count for the last node of list */
    if((strcmp(temp->file_name, file_name)) == 0)
    {
        (temp->word_count)++;
        return SUCCESS;
    }
     
     /* creating node for Ltable */
    Ltable *new = malloc(sizeof(Ltable));
    /* error checking */
    if(new == NULL)
    {
        return FAILURE;
    }
    /* updating links of table node */
    new->word_count = 1;
    strcpy(new->file_name, file_name);
    new->table_link = NULL;

    temp->table_link = new;
    ((*head)->file_count)++;
    return SUCCESS;       
}