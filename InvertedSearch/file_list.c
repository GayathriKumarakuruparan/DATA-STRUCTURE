#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1, empty;
    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if(empty == FILE_NOT_AVAILABLE)
        {
            printf("File : %s is not available\n", argv[i]);
            printf("Hence we are not adding into the file list\n");
            i++;
            continue;
        }
        else if(empty == FILE_EMPTY)
        {
            printf("File : %s is not having any contents in it\n", argv[i]);
            printf("Hence we are not adding into the files list\n");
            i++;
            continue;
        }
        else
        {
            /* if filename is available and it has contents then list is created */
            int ret_val = to_create_list_of_files(f_head, argv[i]);
            if(ret_val == SUCCESS)
            {
                printf("Successfull : Inserting the filename : %s into the file linked list\n", argv[i]);

            }
            else if(ret_val == REPEATATION)
            {
                printf("This file name %s is repeated, Hence we are not adding into the file list \n", argv[i]);
            }
            else
            {
                printf("FAILURE\n");
            }
        }
        i++;
    }
}
/* func is called to check for file availability and for its contents */
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        if(errno == ENOENT)
        {
            return FILE_NOT_AVAILABLE;
        }
    }
    fseek(fptr, 0, SEEK_END);
    /* checking file has contents or not */
    if(ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
}

int to_create_list_of_files(Flist **f_head, char *name)
{
    /* creating new node */
    Flist *new = malloc(sizeof(Flist));
    /* error checking */
    if(new == NULL)
    {
        return FAILURE;
    }

    strcpy(new->file_name, name);
    new->link = NULL;
    /* if list empty adding at first */
    if(*f_head == NULL)
    {
        *f_head = new;
        return SUCCESS;
    }
    Flist *temp = *f_head;
      /* checking for duplicate names */
    while(temp->link)
    {
        if((strcmp(temp->file_name, name)) == 0)
        {
            free(new);
            return REPEATATION;         //returning repeatation if duplicate is found
        }
        temp = temp->link;
    }
        /* checking duplicates in last node */
    if((strcmp(temp->file_name, name)) == 0)
    {
        free(new);
        return REPEATATION;
    }
    temp->link = new;
    return SUCCESS;
}