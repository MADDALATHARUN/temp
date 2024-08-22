#include <stdio.h >
void main()
{
    int count,counter;
    int row_size=10;
    int * matrix;
    int counte;
    printf("How many rows do you want to enter:");
    scanf("%d",&count);
    matrix=(int*)malloc(count*row_size*sizeof(int));
    printf("Enter the elements:\n");
    for(counter=0 ; counter<count ; counter++)
    {
        for(counte=0 ; counte<row_size ; counte++)
        {

            scanf("%d",matrix+counter+counte);
        }
    }
    printf("matrix : \n");
    for(counter=0 ; counter<count ; counter++)
    {
        for(counte=0 ; counte<row_size ; counte++)
        {

            printf("%d ",*(matrix+counter+counte));
        }
        printf("\n");
    }

}
