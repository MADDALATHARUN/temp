// Size increasing for large name.



#include <stdio.h >
#include <stdlib.h>
void main()
{
    int count, counter, length = 5;
    printf("How many names do you want to enter: ");
    scanf("%d", &count);
    char **names;

    names = ( char** )malloc( count * length);

    printf("Enter the names: \n");
    for(counter = 0 ; counter < count ; counter++)
    {
        fflush(stdin);
        fgets(names + counter * length, length, stdin);
        //scanf("%s",name+counter*20);
        fflush(stdin);
    }

    for(counter = 0 ; counter < count ; counter++)
    {

        printf("Name %d: %s \n", counter + 1, names + counter * length );
    }
    free( names );
}
