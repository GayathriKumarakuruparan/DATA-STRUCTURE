/*
Name                    :   GAYATHRI.K
Date                    :   28.12.2023
Description             :   Inverted Search
Sample execution        :   emertxe@ubuntu:~/ECEP/DS/Project$ make
                            cc    -c -o search_database.o search_database.c
                            cc    -c -o create_database.o create_database.c
                            cc    -c -o insert.o insert.c
                            cc    -c -o display_database.o display_database.c
                            cc    -c -o main.o main.c
                            cc    -c -o file_list.o file_list.c
                            cc    -c -o save_database.o save_database.c
                            cc    -c -o update_database.o update_database.c
                            gcc -o out.exe search_database.o create_database.o insert.o display_database.o main.o file_list.o save_database.o update_database.o  
                            emertxe@ubuntu:~/ECEP/DS/Project$ ./out.exe file1.txt 

                            Successfull : Inserting the filename : file1.txt into the file linked list
                            Select your choice among following options:
                            1. Create database
                            2. Display database
                            3. Update database
                            4. Search
                            5. Save database
                            Enter your choice
                            1
                            Successfull: Creation of database for file : file1.txt
                            Do you want to continue ?
                            Enter y/Y to continue (or) n/N to exit : y
                            Select your choice among following options:
                            1. Create database
                            2. Display database
                            3. Update database
                            4. Search
                            5. Save database
                            Enter your choice
                            2

                           [index]   [word]  file_count file/s File:file_name word_count
                            [0]     [are]     1 file/s:  File: file1.txt    1
                            [7]     [hello]     1 file/s:  File: file1.txt    1
                            [7]     [hi]     1 file/s:  File: file1.txt    1
                            [7]     [how]     1 file/s:  File: file1.txt    1
                            [24]     [you]     1 file/s:  File: file1.txt    1

                            Do you want to continue ?
                            Enter y/Y to continue (or) n/N to exit : y
                            Select your choice among following options:
                            1. Create database
                            2. Display database
                            3. Update database
                            4. Search
                            5. Save database
                            Enter your choice
                            3
                            Enter the filename to update database: file2.txt
                            Successfull: Creation of database for file : file2.txt
                            Successful : Database has been updated
                            Do you want to continue ?
                            Enter y/Y to continue (or) n/N to exit : y
                            Select your choice among following options:
                            1. Create database
                            2. Display database
                            3. Update database
                            4. Search
                            5. Save database
                            Enter your choice
                            2

                            [index]   [word]  file_count file/s File:file_name word_count
                             [0]     [are]     2 file/s:  File: file1.txt    1 File: file2.txt    1
                             [5]     [fine]     1 file/s:  File: file2.txt    1
                             [7]     [hello]     2 file/s:  File: file1.txt    1 File: file2.txt    1
                             [7]     [hi]     1 file/s:  File: file1.txt    1
                             [7]     [how]     2 file/s:  File: file1.txt    1 File: file2.txt    1
                             [24]     [you]     2 file/s:  File: file1.txt    1 File: file2.txt    1

                            Do you want to continue ?
                            Enter y/Y to continue (or) n/N to exit : y
                            Select your choice among following options:
                            1. Create database
                            2. Display database
                            3. Update database
                            4. Search
                            5. Save database
                            Enter your choice
                            4
                            Enter the word to be searched: are
                            Word are is found at 2 files 
                            In file : file1.txt 1 times
                            In file : file2.txt 1 times

                            Do you want to continue ?
                            Enter y/Y to continue (or) n/N to exit : y
                            Select your choice among following options:
                            1. Create database
                            2. Display database
                            3. Update database
                            4. Search
                            5. Save database
                            Enter your choice
                            5
                            Enter the filename to save the database: backup.txt
                            Successful : Database has been saved to backup.txt
                            Do you want to continue ?
                            Enter y/Y to continue (or) n/N to exit : n
                            emertxe@ubuntu:~/ECEP/DS/Project$ cat backup.txt
                            #[0]
                            Word is [are]: File count is 2 File/s: File is file1.txt: Word count is 1
                            File is file2.txt: Word count is 1
                            #[5]
                            Word is [fine]: File count is 1 File/s: File is file2.txt: Word count is 1
                            #[7]
                            Word is [hello]: File count is 2 File/s: File is file1.txt: Word count is 1
                            File is file2.txt: Word count is 1
                            Word is [hi]: File count is 1 File/s: File is file1.txt: Word count is 1
                            Word is [how]: File count is 2 File/s: File is file1.txt: Word count is 1
                            File is file2.txt: Word count is 1
                            #[24]
                            Word is [you]: File count is 2 File/s: File is file1.txt: Word count is 1
                            File is file2.txt: Word count is 1
*/

#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");
    Wlist *head[100] = {NULL};
    char ch;
    char word[WORD_SIZE];
    //validate CLA
    if(argc <= 1)
    {
        printf("Enter the valid no. of arguments\n");
        printf("./SList.exe file1.txt file2.txt ......\n");
        return 0;
    }
    /* create file list */
    Flist *f_head = NULL;
       /* validate the files */
       file_validation_n_file_list(&f_head, argv);

       if(f_head == NULL)
       {
            printf("No files are available in the file linked list\n");
            printf("Hence the process terminated\n");
            return 1;
       }
    do
    {
       
       int option;
       /* getting choice from the user */
       printf("Select your choice among following options:\n1. Create database\n2. Display database\n3. Update database\n4. Search\n5. Save database\nEnter your choice\n");
       scanf("%d", &option);
       /* using switch case for the option got from the user */
       switch (option)
       {
            case 1:
                create_database(f_head, head);
                break;

            case 2:
                display_database(head);
                break;

            case 3:
                update_database(head, &f_head);
                break;

            case 4:
                printf("Enter the word to be searched: ");
                scanf("%s", word);
                search(head[tolower(word[0]) % 97], word);
                break;

            case 5:
                save_database(head);
                break;

             default :
                printf("Enter proper choice..\n");
                break;
        }
        printf("Do you want to continue ?\nEnter y/Y to continue (or) n/N to exit : ");
        __fpurge(stdin);
        scanf("%c", &ch);
    } while ((ch == 'y') || (ch == 'Y'));
    /* using do while loop to ask user to continue or not */

    return SUCCESS;

}
