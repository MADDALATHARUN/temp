#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* marks[20];

void sort(int size)
{
    //char temp[20];
    for(int counter = 0; counter < size-1; counter++)
    {
        for(int counter1 = 0; counter1 < ((size-counter)-1); counter1++)
        {
            char *temp;
            if ((strcmp(marks[counter1], marks[counter1 + 1]) > 0))
            {
                temp = marks[counter1];
                marks[counter1] = marks[counter1 + 1];
                marks[counter1 + 1] = temp;
            }
        }
    }
}
void main()
{
    char* mark[20] = {"tharun", "ram", "janu", "jack", "sri teja", "chitti"};
    for(int counter = 0; counter < 6; counter++)
    {
        marks[counter] = mark[counter];
    }
    sort( 6);
    for(int counter = 0; counter < 6; ++counter)
    {
        printf("%s\n", marks[counter]) ;
    }
}
