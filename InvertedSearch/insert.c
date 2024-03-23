#include "inverted_search.h"

extern char *fname;

int insert_at_last(Wlist **head, data_t *data)
{
    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    /* updating links */
    new->file_count = 1;
    strcpy(new->word, data);
    new->Tlink = NULL;
    new->link = NULL;

    /* calling function to update link table */
    update_link_table(&new);
    /* check Wlist is empty or not */
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    Wlist *temp = *head;
    /* traverse through list */
    while(temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

int update_link_table(Wlist **head)
{
    /* create node */
    Ltable *new = malloc(sizeof(Ltable));
    /* error checking */
    if(new == NULL)
    {
        return FAILURE;
    }
    /* updating links */
    new->word_count = 1;
    strcpy(new->file_name, fname);
    new->table_link = NULL;
    (*head)->Tlink = new;
    
    return SUCCESS;
    
}