#include<stdio.h>
void main(){
int array[5];
int marks;
for(int i=0;i<5;i++){
        printf("enter the marks of student %d",i+1);
        scanf("%d",&marks);
        array[i]=marks;}
for(int i=0;i<5;i++){
        printf("marks of student%d %d\n",i+1, array[i]);}
    }


