// Read and print 5 marks using a character array

#include <stdio.h>

void main()
{
    char array[5];
    for(int counter = 0; counter < 5; counter++)
    {
        printf("Enter the marks of the student %d of 5: ", counter + 1);
        scanf("%d", &array[counter]);
    }
    for(int counter = 0; counter < 5; counter++)
    {
        printf("student %d marks: %d \n",counter+1, array[counter]);
    }
}
