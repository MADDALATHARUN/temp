// CRUD operations framework.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define DATA_FILE "framework.dat"
#define FIELDS_FILE "fields.config"
#define MENU_FILE "menu.config"
#define field_size 20

FILE* fpData;
FILE* fpFields;
char string_to_compare[field_size];
char any_charcter;
int fields_count;
char status[1];
char last_field[field_size];
char field_name[field_size];
char field_input_value[field_size];
char field_value[field_size];

void get_fields_count()
{
    int counter = 0;
    fpFields = fopen(FIELDS_FILE, "r");
    while (fgets(field_name, field_size, fpFields))
    {
        fflush(stdin);
        counter++;

    }
    strcpy(last_field ,field_name);
    fields_count = counter;
//    while ((any_charcter = fgetc(fpFields)) != EOF)
//    {
//        if (any_charcter == '\n')
//        {
//            counter++;
//        }
//    }
    fclose(fpFields);
//
//    fields_count = counter + 1;
}

void replace_newline_with_null(char* any_string)
{
    any_string[strcspn(any_string, "\n")] = '\0';
}

void create_record()
{
	fpFields = fopen(FIELDS_FILE, "r");
	fpData = fopen(DATA_FILE, "a");
    while (fgets(field_name, field_size, fpFields))
    {
        fflush(stdin);
        replace_newline_with_null(field_name);
        printf("Enter the %s: ", field_name);
        fgets(field_input_value, field_size, stdin);
        replace_newline_with_null(field_input_value);
        fwrite(field_input_value, field_size, 1, fpData);
        fflush(stdin);
    }
    fflush(stdin);
    status[0] = 'A';
    //strcpy(status, 'A');
    //status[strcspn(status, "\n")] = '\0';
    //fprintf(fpData,"%s", "A");
    fwrite(status, 2, 1, fpData);
    fclose(fpFields);
    fclose(fpData);
}

void show_records()
{
	fpData = fopen(DATA_FILE, "r");
	fpFields = fopen(FIELDS_FILE, "r");
    while (fread(field_value, field_size, 1, fpData) != 0)
    {
        if(fgets(field_name, field_size, fpFields) == 0)
        {
            rewind(fpFields);
            strcpy(field_name , "status");
            fseek(fpData, -(field_size-2), SEEK_CUR);
            //fgets(field_name, field_size, fpFields);
        }
//      fgets(field_element, field_size, fpFields);
//      if(strcmp(temp_string, field_element)==0)
//      {
//          rewind(fpFields);
//          fgets(field_element, field_size, fpFields);
//      }
        fflush(stdin);
        //strcpy(temp_string ,field_element);
        replace_newline_with_null(field_name);
        printf("%s: %s\n", field_name, field_value);
    }
    strcpy(field_name , "status");
    fread(field_value, 1, 1, fpData);
    printf("%s: %s\n", field_name, field_value);
    fclose(fpFields);
    fclose(fpData);
}

int search_record(char operation_name[])
{
    printf("Enter record id to %s: ", operation_name);
    fflush(stdin);
    fgets(string_to_compare, field_size, stdin);
    replace_newline_with_null(string_to_compare);
	fpData = fopen(DATA_FILE, "r+");
	while (fread(field_value, field_size, 1, fpData))
    {
        if (strcmp(field_value, string_to_compare) == 0)
        {
            return 1;
        }
        fseek(fpData, field_size * (fields_count - 1) + 2, SEEK_CUR);
    }
    printf("Record not found.\n");
    return 0;
}

void show_record()
{
    if (search_record("Show record") == 1)
    {
        fseek(fpData, -field_size, SEEK_CUR);
        fpFields = fopen(FIELDS_FILE, "r");
        while (fread(field_value, field_size, 1, fpData) != 0)
        {
        if(fgets(field_name, field_size, fpFields) == 0)
        {
            strcpy(field_name , "status");
            printf("%s: %s\n", field_name, field_value);
            break;
        }
        fflush(stdin);
        replace_newline_with_null(field_name);
        printf("%s: %s\n", field_name, field_value);
    }
    fclose(fpFields);
    fclose(fpData);
    }
}

void update_record()
{
    if (search_record("update") == 1)
    {
        fseek(fpData, field_size * (fields_count - 2), SEEK_CUR);//last record update only
        fflush(stdin);
        printf("Enter updated data to %s: ", last_field);
        fgets(field_input_value, field_size, stdin);
        replace_newline_with_null(field_input_value);
        fwrite(field_input_value, field_size, 1, fpData);
        fclose(fpData);
    }
    printf("Updated successfully!\n");
}

void delete_record()
{
    if (search_record("delete") == 1)
    {
        fseek(fpData, field_size * (fields_count - 1), SEEK_CUR);
        fflush(stdin);
        status[0] = 'D';
        fwrite(status, 2, 1, fpData);// Status changing
        fclose(fpData);
        printf("Deleted Successfully!\n");
    }
}

void show_menu()
 {
    system("cls");
    int your_choice = 1;
    char menu_line[field_size];
    FILE* fpMenu;
    while(your_choice < 6)
    {
        fpMenu = fopen(MENU_FILE, "r");
        while (fgets(menu_line, field_size, fpMenu))
        {
            printf("%s", menu_line);
        }
        fclose(fpMenu);
        printf("\n---------------------------------------------------------\nEnter your choice: ");
        scanf("%d", &your_choice);
        if (your_choice == 1)
        {
            create_record();
            break;
        }
        else if(your_choice == 2)
        {
            show_records();
            break;
        }
        else if(your_choice == 3)
        {
            show_record();
            break;
        }
        else if(your_choice == 4)
        {
            update_record();
            break;
        }
        else if(your_choice == 5)
        {
            delete_record();
            break;
        }
        else
        {
             exit(0);

        }
    }
    fflush(stdin);
    printf("Do you want to continue Y/N : ");
    scanf("%c", &any_charcter);
    if (any_charcter == 'Y')
    {
        show_menu();
    }
    else
    {
        exit(0);
    }
 }

void main()
{
    get_fields_count();
    show_menu();
}
