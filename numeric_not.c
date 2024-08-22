#include <stdio.h>
#include <stdlib.h>
#define NULL 1
void print(int integer)
{
    if(integer != 1)
    {
        print(integer-1);
    }
    printf("%d\n",integer);
}
void main()
{
    char number[10]="132";
    char name[15];
    int num;
    scanf("%d",num);

    //itoa(num,name,10);
    //sprintf(name,"%d",num);
    //
    printf("%d",NULL );
    print(num);
}
