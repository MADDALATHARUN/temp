// read and print different class marks.



#include <stdio.h >
#include <stdlib.h >

void main()
{
    int count, row_counter, counter, length = 5;
    printf("How many names do you want to enter: ");
    scanf("%d", &count);
    int* marks;
    //char **names;
    //names = ( char** )malloc( count * sizeof(char*));
    marks = ( int* )malloc(count * sizeof(int));
    for (row_counter = 0 ; row_counter < count ; row_counter++)
    {
        fflush(stdin);
        marks[row_counter] = ( int* ) malloc(length * sizeof(int));
        for (counter = 0 ; counter < length ; counter++)
        {
        /*fflush(stdin);
        printf("Enter the name_%d: ", counter + 1);
        fgets(names[counter], length, stdin );
        fflush(stdin);*/
            printf("Enter the marks of student_%d : ", counter + 1);
            scanf("%d", &marks[row_counter+counter]);
            fflush(stdin);
        }
    }


    for(counter = 0 ; counter < count ; counter++)
    {
       // names[counter][strlen(names[counter]) - 1] = NULL;
        printf("Name_%d:  marks: %d \n", counter + 1, *(marks + counter) );
    }
  //  free( names );
    free( marks );
}
