#include <stdio.h>

int main(int argc, char const *argv[])
{
	int number = 0;
	int number2 = 0;
	int area = 0;

	printf("Is this a square or rectangle? 1 for square, 2 for rectangle\n");

	if (input == 1)
	{
		printf("Please print in the length of a side?\n");
		scanf("%d", &number);
		area = number*number;
		printf("The are of the square is: %d\n", area );
	}
	else if (input == 2)
	{
		printf("Please print in the length of a side?\n");
		scanf("%d", &number);
		printf("Please print in the length of the other side?\n");
		scanf("%d", &number2);
		area = number*number2;
		printf("The are of the square is: %d\n", area );
	}
	else
	{
		printf("incorrect input\n");
	}


	return 0;
}