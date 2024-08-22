//compare two strings without using inbuilt functions and == operator.

#include <stdio.h>

void main()
{
      char string1 [50] = "madam";
      char string2 [50] = "m";
      int size=sizeof(string1)- sizeof(string1[0]);
      for (int i= 0;i<5;i++)
      {
        if ( string1[i]- string2[i] !=0 )
        {
         printf(" Both the given strings are not same.");
         exit(0);
        }
      }
      printf(" Both the given strings are same.");
}
