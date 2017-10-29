#include <stdio.h>

int main(int argc, char const *argv[])
{
	int number = 0;
	int area = 0;

	printf("Please print in the length of a side?\n");
	scanf("%d", &number);

	area = number*number;

	printf("The are of the square is: %d\n", area );
	return 0;
}