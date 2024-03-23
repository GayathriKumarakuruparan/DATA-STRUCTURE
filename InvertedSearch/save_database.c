#include "inverted_search.h"

void save_database(Wlist *head[])
{
    /* getting name from the user to save the database */
    char file_name[FNAME_SIZE];
    printf("Enter the filename to save the database: ");
    scanf("%s", file_name);

    FILE *fptr = fopen(file_name, "w");
    for(int i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            /* calling write database function to write */
            write_databasefile(head[i], fptr);
        }
    }
    fclose(fptr);
    printf("Successful : Database has been saved to %s\n", file_name);
}

void write_databasefile(Wlist *head, FILE* databasefile)
{
    int index = (tolower(*(head->word))) % 97;
     fprintf(databasefile, "#[%d]\n", index);     // Storing index value in the output file

     while (head != NULL)
     {
        fprintf(databasefile, "Word is [%s]: File count is %d File/s: ", head->word, head->file_count);
        Ltable *Thead = head->Tlink;

        // Traversing through the Ltable
        while (Thead)
        {
            fprintf(databasefile, "File is %s: Word count is %d\n", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }
        
        head = head->link;
    }
}
