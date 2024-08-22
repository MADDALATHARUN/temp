#include <stdio.h>
void string(int num)
{
    int counter=0;
    char* string_number = (char *)&num;
    printf("%c--%d",string_number[0],string_number[0]);
    printf("%c--%d",string_number[ 1],string_number[1]);
        counter++;


}
void main()
{
    string(16706);
}
