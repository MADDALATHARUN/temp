 //read and write names in a file

 #include <stdio.h>
 #include <conio.h>
 #include <string.h>
 #include <stdlib.h>
 #define file "my_name.txt"

 FILE* fpnames;
 char any_charcter;
 int size = 20;
 char* names[20];
 int array_size;


 void save_a_name()
 {

    char name[size];
    names[array_size] = (char*)malloc(size * sizeof(char));
    printf("Enter the name: ");
    fflush(stdin);
    fgets(name, size, stdin);
    strcpy(names[array_size], name);
    array_size += 1;
    //fpnames = fopen(file, "a");
    //fprintf(fpnames, "%s", name);
    sort_array();
    printf("Name is successfully saved!\n");
    //fclose(fpnames);
 }

 void sort_array()
 {
    for(int counter = 0; counter < (array_size - 1); counter++)
    {
        for(int counter1 = 0; counter1 < ((array_size - counter) - 1); counter1++)
        {
            char* temp;
            if ((strcmp(names[counter1], names[counter1 + 1]) > 0))
            {
                temp = names[counter1];
                names[counter1] = names[counter1 + 1];
                names[counter1 + 1] = temp;
            }
        }
    }
    override_file();
     /*fpnames = fopen(file, "w");
    for(int counter = 0; counter < array_size; ++counter)
    {
        fprintf(fpnames, "%s", names[counter]);
    }
    fclose(fpnames);
    for(int counter = 0; counter < array_size; ++counter)
    {
        printf("%s\n", names[counter]) ;
    }

    fpnames = fopen(file, "r");
    char buffer[20];
    while ( fgets(buffer, 20, fpnames) )
    {
        printf("%s", buffer);
    }
    fclose(fpnames);*/

 }

 void read_names_into_array()
 {

    char buffer[size];
    int counter = 0;
    fpnames = fopen(file, "r");
    while ( fgets(buffer, size, fpnames) != 0 )
    {
        names[counter] = (char*)malloc(size * sizeof(char));
        fflush(stdin);
        strcpy(names[counter], buffer);
        counter += 1;
    }
    array_size = counter;
    fclose(fpnames);
 }

 void show_names()
 {
    fpnames = fopen(file, "r");
    char buffer[size];
    while ( fgets(buffer, size, fpnames) )
    {
        printf("%s", buffer);
    }
    fclose(fpnames);
 }

 void delete_name(char name[])
 {
    for(int counter = 0; counter < array_size - 1; counter++)
    {
        if ((strcmp(names[counter], name) == 0))
        {
            for(int counter1 = counter; counter1 < (array_size - 1); counter1++)
            {
                char* temp;
                temp = names[counter1];
                names[counter1] = names[counter1 + 1];
                names[counter1 + 1] = temp;
            }
            //free(name[array_size - 1]);
            array_size = array_size - 1;
            override_file();
            break;
        }
    }
    printf("Name is successfully deleted!\n");
    //free(name[array_size - 1]);

 }

 void override_file()
 {
    fpnames = fopen(file, "w");
    for(int counter = 0; counter < array_size; ++counter)
    {
        fprintf(fpnames, "%s", names[counter]);
    }
    fclose(fpnames);
 }

 int read_choice()
 {
    system("cls");
    int your_choice;
    printf("--------------------------------------\n1. save a name \n2. show Names \n3. Delete a name \n4. Exit\n--------------------------------------\nEnter your choice : ");
    scanf("%d", &your_choice);

    return your_choice;

 }

 void main()
 {
    read_names_into_array();
    sort_array();
    //printf("%d",array_size);
    //show_names();
    //delete_name("ram");
    int your_choice = read_choice();
     //printf("%d",array_size);
    while(your_choice < 4)
    {

        if (your_choice == 1)
        {
            save_a_name();
        }
        else if(your_choice == 2)
        {
            show_names();
        }
        else
        {
            char del_name[size];
            printf("Enter name to delete: ");
            fflush(stdin);
            fgets(del_name, size, stdin);
            printf("%s--",del_name);
           // delete_name(del_name);
        }
        fflush(stdin);
        printf("Do you want to continue Y/N : ");
        scanf("%c", &any_charcter);
        if (any_charcter == 'Y')
        {

            your_choice = read_choice();
        }
        else
        {
            exit(0);
        }
    }
 }
