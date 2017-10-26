#include <stdio.h>

int main(int argc, char const *argv[])
{
	char sentence [30];

	printf("hello world\n");
	fgets(sentence,30,stdin);
	printf("This is the sentence: %s\n", sentence);
	return 0;
}