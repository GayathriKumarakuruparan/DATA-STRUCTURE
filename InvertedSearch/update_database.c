#include "inverted_search.h"

void update_database(Wlist *head[], Flist **f_head)
{
    char file_name[FNAME_SIZE];
    int empty;
    /* prompting user to enter new file name */
    printf("Enter the filename to update database: ");
    scanf("%s", file_name);

    /* validating the file and adding into the file linked */
    empty = isFileEmpty(file_name);
    if(empty == FILE_NOT_AVAILABLE)
    {
        printf("File : %s is not available\n", file_name);
        printf("Hence we are not adding into the file list\n");
    }
    else if(empty == FILE_EMPTY)
    {
        printf("File : %s is not having any contents in it\n", file_name);
        printf("Hence we are not adding into the file list\n");
    }
    else
    {
        /* creating new node */
        Flist *new = malloc(sizeof(Flist));
        /* error checking */
        if(new == NULL)
        {
            printf("Failed to create a new node for %s\n", file_name);
        }
        strcpy(new->file_name, file_name);
        new->link = NULL;

        Flist *temp = *f_head;  //temp to traverse 
        while(temp->link)
        {
            /* if duplicate is found then freing new node */
            if((strcmp(temp->file_name, file_name)) == 0)
            {
                free(new);
                printf("%s is already present in the database\n", file_name);
            }
            temp = temp->link;
        }
        if((strcmp(temp->file_name, file_name)) == 0)
        {
            free(new);
            printf("%s is already present in the database\n", file_name);
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head, file_name);    // Adding filename to the file linked list

           /* Duplicate file name is passed */
           if (ret_val == REPEATATION)
           {
               printf("This file name : %s is repeated, Hence we are not adding to the list\n", file_name);
           }

           else if (ret_val == FAILURE)
           {
               printf("FAILURE\n");
           }

           else
           {
               printf("Successfull : Inserting the file name : %s into the the file linked list\n", file_name);
               Flist *temp = *f_head;

               while (temp)
               {
                   if (!(strcmp(temp->file_name, file_name)))
                   {
                        create_database(temp, head);     // Updating the database with the new file
                   }

                  temp = temp->link;
               }
           
              printf("Successful : Database has been updated\n");
           }
        }
    }
}
