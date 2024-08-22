
//check whether the given number is prime or not?

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool check_prime(char any_string[10])
{
    int number = atoi(any_string);
    int divisor, divisor_limit = sqrt(number);
	if (number == 2 || number == 3 || number == 5 || number == 7)
	{
		return 1;
	}
	else if (number < 2 || number % 2 == 0 || number % 3 == 0)
	{
		return 0;
	}
	else if(number > 10 )
	{
		for ( divisor = 11; divisor <= divisor_limit; divisor += 6)
		{
			if(number % divisor == 0 || number % (divisor+2) == 0)
			{
				return 0;
			}
		}

	}
	return 1;
}
/*void main()
{
	int number;
	printf("Enter a number to check whthere it is prime or not ? : ");
	scanf("%d",&number);
	if (check_prime(number) == 1)
	{
		printf("\n%d is a prime number", number);
	}
	else
	{
		printf("\n%d is not a prime number", number);
	}
}*/
