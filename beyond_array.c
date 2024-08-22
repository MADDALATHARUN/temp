//read numbers beyond the array

#include <stdio.h>
void main()
{
    int size_of_array;
    int array[size_of_array];

    printf("Enter the size of the array:");
    scanf("%d", &size_of_array);

    for(int counter = 0; counter < 10; counter++)
    {
        printf("Enter the number %d: ",counter + 1);
        scanf("%d", &array[counter]);
    }
    for(int counter = 0; counter < 10; counter++)
    {
        printf("number%d : %d\n",counter + 1, array[counter]);
    }
}


