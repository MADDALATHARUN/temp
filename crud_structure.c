// CRUD opreations on  Item structure.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define file "Item.txt"
#define size 20

FILE* fpItem;
char compare_id [size];

typedef struct Item
{
	char itemId[size];
	char description[size];
	char price;
}sItem;

void read_item(sItem* pItem)
{
	printf("Enter Description: ");
	scanf("%s", pItem->description);
	printf("Enter price: ");
	scanf("%d", &pItem->price);
}

void saveItem(sItem* pItem)
{
	fpItem = fopen(file, "a");
	fwrite(pItem, sizeof(sItem), 1, fpItem);
	fclose(fpItem);
}

void new_Item(sItem* pItem)
{
    printf("Enter the ItemId: ");
	scanf("%s", pItem->itemId);
	read_item(pItem);
    saveItem(pItem);
}

void show_items()
{
    sItem* temp = (sItem*) malloc(sizeof(sItem));
	fpItem = fopen(file, "r");
	while (fread(temp, sizeof(sItem), 1, fpItem))
    {
        printf("\nItemId: %s \nDescription: %s \nPrice: %d \n", temp->itemId, temp->description, temp->price);
    }
    fclose(fpItem);
}

void compare_input(char operation_name[])
{
    fflush(stdin);
    printf("Enter Item ID to %s: ",operation_name);
    fflush(stdin);
    fgets(compare_id, size, stdin);
    compare_id[strcspn(compare_id, "\n")] = '\0';
}

void update_item()
{
    compare_input("update");
    sItem* temp = (sItem*) malloc(sizeof(sItem));
	fpItem = fopen(file, "r+");
	while (fread(temp, sizeof(sItem), 1, fpItem))
    {
        if (strcmp(temp -> itemId,compare_id) == 0)
        {
            fseek(fpItem, -(sizeof(sItem)) ,SEEK_CUR);
            read_item(temp);
            fwrite(temp, sizeof(sItem), 1, fpItem);
            break;
        }
    }
    fclose(fpItem);
}

void delete_item()
{
    compare_input("Delete");
    sItem* temp = (sItem*) malloc(sizeof(sItem));
	fpItem = fopen(file, "r");
	FILE* fptempItem;
	fptempItem = fopen("temp.txt", "a");

	while (fread(temp, sizeof(sItem), 1, fpItem))
    {
        if (strcmp(temp -> itemId,compare_id) == 0)
        {
            continue;
        }
        fwrite(temp, sizeof(sItem), 1, fptempItem);
    }
    fclose(fpItem);
    fclose(fptempItem);
    remove(file);
    rename("temp.txt", file);
}


int read_choice()
 {
    int counter = 1;
    system("cls");
    int your_choice;
    char menu_string[size];
    FILE* fpmenu;
	fpmenu = fopen("menu.txt", "r");
    //printf("--------------------------------------\n1. Save a new Item \n2. Show Items \n3. Update Item \n4. Delete Item \n5. Exit\n--------------------------------------\nEnter your choice : ");
    while (fgets(menu_string, size, fpmenu))
    {
        printf("%d. %s", counter, menu_string);
        counter++;
    }
    fclose(fpmenu);
    printf("Enter your choice: ");
    scanf("%d", &your_choice);
    return your_choice;
 }

void main()
{
    char any_charcter;
    sItem* Item = (sItem*) malloc(sizeof(sItem));
    //new_Item(Item);
    //show_items();
    //char update_arg[100];
    //update_item(&update_arg);
    int your_choice = read_choice();
    while(your_choice < 5)
    {

        if (your_choice == 1)
        {
            new_Item(Item);
        }
        else if(your_choice == 2)
        {
            show_items();
        }
        else if(your_choice == 3)
        {
            update_item();
        }
        else
        {
            delete_item();
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
