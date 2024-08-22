#include <stdio.h>

int main()
{

    int **name,v=5,l=12;
    name=(char**)malloc(v*sizeof(int*));

    char* city;
    city = malloc(20);
    int K=*(&name+1)-name;
    printf("size: %d\nlength:%d , %d \n", sizeof(*name),K,v>>l);
    //printf("size: %d\nlength: %d\n", sizeof(city), strlen(city));
}

