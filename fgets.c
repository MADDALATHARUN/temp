//print each character in array using fgets

#include<stdio.h>

int main()
{
    int size = 10, counter;
    char names[size];
    fflush(stdin);
    printf("Enter your name: ");
    fgets(names,size,stdin);
    names[strlen(names)-1]=NULL;
    for(counter = 0; counter < size; counter++)
    {

        printf("%c - %d \n", names[counter], names[counter]);

    }

    fflush(stdin);

}
