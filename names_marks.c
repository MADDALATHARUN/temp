// read and print names and marks.



#include <stdio.h >
#include <stdlib.h >
#include <string.h>
/*void replace_newline_with_null( char*any_string )
{
    if ( any_string[strlen(any_string) - 1] == '\n' )
    {
        any_string[strlen(any_string) - 1] = NULL;
    }
}*/
void main()
{
    int count, counter, length = 5;

    int* marks;
    printf("How many names do you want to enter: ");
    scanf("%d", &count);
    char** names;
    names = ( char** ) malloc( count * sizeof(char*));
    marks = ( int* ) malloc(count * sizeof(int));
    for (counter = 0 ; counter < count ; counter++)
    {
        names[counter] = ( char* )malloc(length);
        fflush(stdin);
        printf("Enter the name_%d: ", counter + 1);
        fgets(names[counter], length, stdin );
        fflush(stdin);
        printf("Enter the marks of student_%d: ", counter + 1);
        scanf("%d", marks + counter);
    }

    for(counter = 0 ; counter < count ; counter++)
    {
        //replace_newline_with_null(names[counter]);
        names[counter][strlen(names[counter]) - 1] = NULL;


        printf("Name_%d: %s  marks: %d \n", counter + 1, names[counter], *(marks + counter) );
    }
    free(names);
    free(marks);
}
