// Size increasing for large name.


#include <stdio.h >
void main()
{
    int count, counter, s = 0;
    int size = 10;
    char * name;
    printf("How many names do you want to enter: ");
    scanf("%d", &count);
    name = (char*)malloc(count*size);
    printf("Enter the names: \n");
    for(counter=0 ; counter<count ; counter++)
    {
        scanf("%s", name + s);
        s = s + strlen(name+s) + 1;

    }
    printf("Names are: \n");
    s = 0;
    for(counter=0 ; counter<count ; counter++)
    {
        printf(" %s \n ", name + s);
        s = s + strlen(name+s) + 1;

    }
}
