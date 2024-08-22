// Test case program for Prime number

#include <stdio.h>
#include <stdbool.h>
#include "prime_number.c"

void main()
{
	char *numbers[]= { "0", "-234hudjbj", "16", "2", "3", "13", "CJ"};
	bool expected_result[ ] = {0, 0, 1, 0, 0 ,1, 1};
	int failed_counter = 0;
	int serial_count = 0 ;
	int size_of_array = sizeof(numbers)/sizeof(numbers[failed_counter]);
	printf("%d",size_of_array);
	for ( int numbers_counter = 0; numbers_counter < size_of_array; numbers_counter += 1 )
	{
		if (check_prime(numbers[numbers_counter]) != expected_result[numbers_counter])
		{
			failed_counter += 1;
            serial_count++;
			printf("\n%d. %s Test case FAILED.",serial_count, numbers[numbers_counter]);

		}
	}
	if( failed_counter == 0 )
	printf("\nAll Test cases are PASSED\n");
}
