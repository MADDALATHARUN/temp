// curd operations using single linked list

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define SINGLE_LLIST_FILE "single_llist_file.dat"
#define FIELD_SIZE 20

typedef struct item
{
	char item_id[FIELD_SIZE];
	char description[FIELD_SIZE];
	int price;
}s_item;

typedef struct node
{
    s_item p_item;
    struct node *next;
}s_node;

s_node *head, *current;
s_item new_item;
char any_charcter;
char compare_to_string[FIELD_SIZE];
s_node *previous;
FILE *fp_item;


void read_node_data()
{
//    new_item = (s_item*) malloc(sizeof(s_item));
    printf("Enter the Item Id: ");
	scanf("%s", new_item.item_id);
    printf("Enter Description: ");
	scanf("%s", new_item.description);
	printf("Enter price: ");
	scanf("%d", &new_item.price);
}

void link_node_to_list()
{
    s_node *new_node, *temp;
    new_node = (s_node*)malloc(sizeof(s_node));
	new_node->p_item = new_item;
    //printf("\nItem Id: %s \nDescription: %s \nPrice: %d \n", new->p_item->item_id, new->p_item->description, new->p_item->price);

    if(head == NULL)
    {
        head = new_node;
    }

    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    //printf("\nItem Id: %s \nDescription: %s \nPrice: %d \n", head->p_item.item_id, head->p_item.description, head->p_item.price);

    new_node->next = NULL;
}

void create_new_node()
{
    read_node_data();
    link_node_to_list();
    printf("Created Successfully!\n");
}

void display_all_nodes()
{
    current = head;
    while(current != NULL)
    {
        printf("\nItem Id: %s \nDescription: %s \nPrice: %d \n", current->p_item.item_id, current->p_item.description, current->p_item.price);
        current = current->next;
    }
}

int search_record(char operation_name[])
{
    printf("Enter record id to %s: ", operation_name);
    fflush(stdin);
    //fgets(string_to_compare, field_size, stdin);
    //replace_newline_with_null(string_to_compare);
    scanf("%s", compare_to_string);
	current = head;
	previous = head;
    while((current)!= NULL)
    {
        if (strcmp(current->p_item.item_id, compare_to_string)==0)
        {
            return 1;
        }
        previous = current;
        current = current->next;
    }
    printf("Record not found.\n");
    return 0;
}

void update_node()
{
    if(search_record("update") == 1)
    {
        system("cls");
        int choice;
        while(1)
        {
            printf("--------------------------------------\n1. Item Description  \n2. Item Price \n--------------------------------------\nEnter your choice to update : ");
            scanf("%d", &choice);
            printf("Enter the updated data: ");
            if (choice == 1)
            {
                scanf("%s", current->p_item.description);
                break;
            }

            else if(choice == 2)
            {
                scanf("%d", &current->p_item.price);
                break;
            }

            else
            {
                break;
            }
        }
        printf("Updated Successfully!");
    }
}

void delete_node()
{
    if(search_record("delete") == 1)
    {
        if(current == head)
        {
            head = current->next;
        }
        else
        {
            previous->next = previous->next->next;
        }
        free(current);
        //current = &current->next;
    }

}

void load_linked_list()
{
	fp_item = fopen(SINGLE_LLIST_FILE, "r");
	while (fread(&new_item, sizeof(s_item), 1, fp_item))
    {
        link_node_to_list();
        fflush(stdin);
    }
    fclose(fp_item);
}

void save_nodes_to_file()
{
    s_item temp;
    current = head;
    fp_item = fopen(SINGLE_LLIST_FILE, "w");
    while(current!= NULL)
    {
        temp = current->p_item;
        fwrite(&temp, sizeof(s_item), 1, fp_item);
        current = current->next;
    }
   fclose(fp_item);
}

void sort()
{
    current = head;
	previous = head;
	s_item temp;

	while(previous->next != NULL)
    {
        while(current->next != NULL)
        {
            if (strcmp(current->p_item.item_id, current->next->p_item.item_id) > 0)
            {
                temp = current->p_item;
                current->p_item = current->next->p_item;
                current->next->p_item = temp;
            }
            current = current->next;
        }
        previous = previous->next;
        current = head;
    }
}

void show_menu()
 {
    system("cls");
    int choice = 1;
    while(choice < 7)
    {
        printf("--------------------------------------\n1. Save a new Item \n2. Show Items \n3. Update Item \n4. Delete Item \n5. Sort\n6. Exit\n--------------------------------------\nEnter your choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            create_new_node();
            save_nodes_to_file();
            break;
        }

        else if(choice == 2)
        {
            display_all_nodes();
            save_nodes_to_file();
            break;
        }

        else if(choice == 3)
        {
            update_node();
            save_nodes_to_file();
            break;
        }

        else if(choice == 4)
        {
            delete_node();
            save_nodes_to_file();
            break;
        }

        else if(choice == 5)
        {
            sort();
            display_all_nodes();
            head = NULL;
            load_linked_list();
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
    load_linked_list();
    show_menu();
}

