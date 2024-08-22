// Size increasing for large name.


#include <stdio.h >
void main()
{
    int count,counter;
    //char string[]="tharunnbhhe";
    //char str[]="thar";
    printf("How many names do you want to enter:");
    scanf("%d",&count);
    char *name[count];
    for(counter=0 ; counter<count ; counter++)
    {
        name[counter]=(char*)malloc(0);
    }
    printf("Enter the names:\n");
    for(counter=0 ; counter<count ; counter++)
    {
        scanf("%s",name[counter]);
        if
    }
    printf("Names are: \n");
    for(counter=0 ; counter<count ; counter++)
    {
        printf("%s \n",name[counter]);
    }
    //&string
    //printf("%d",sizeof(*&string));

}
