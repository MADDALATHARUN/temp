// Test case program for Printing grade.

#include <stdio.h>
#include "print_grade.c"

void main()
{
    int serial_count = 0 ;
	int percentages[ ] = {90, 100, 85, 65, 50, 0};
	char grades[ ] = {'A', 'O', 'A', 'C', 'D' ,'F'};
	int pass_counter = 0;
	int size_of_array = sizeof(percentages)/sizeof(percentages[pass_counter]);
	for ( int percentage_counter = 0; percentage_counter < size_of_array; percentage_counter += 1 )
	{
 		if (print_grade(percentages[percentage_counter], 15) == grades[percentage_counter])
		{
			pass_counter += 1;
		}
		else
		{
            serial_count++;
			printf("\n%d. %d Test case FAILED.", serial_count, percentages[percentage_counter]);

		}
	}
	if( pass_counter == size_of_array )
	printf("\nAll Test cases are PASSED\n");
}
