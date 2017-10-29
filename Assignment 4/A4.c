/*********************************
CIS Assignment 4
Simon Ko
0906762
November 12, 2014
This program is asks a sentence from
a user. It determines if it is a pangram,
which means it uses all letters in the 
alphabet. The program tells the user if it is a pangram.
It also tells the user which letters are missing if it is not a pangram.
The program also tells you if it is a tautogram, which means that
every letter at the beginning of each word is the same.
*********************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check4pangram(char *sentence); //Function prototypes declared before main
int missingLetters(char *sentence);
int isTautogram(char *sentence);

int main (void)
{

char sentence[100]; //Declare an array of 100 for the user's sentence
int x = 0; 

printf("Enter a sentence: ");
fgets (sentence, 100, stdin); //This inputs the char values into the array
printf("The sentence is: %s", sentence);

	for (x=0;x<100;x++)
	{
	sentence[x] = tolower(sentence[x]); //This lowers the case of any letter in the string for the sentence array
	}

check4pangram(sentence); //Function call
missingLetters(sentence);//Function call
isTautogram(sentence); //Function call


}

/*---------------------------------------------------------*/
//pangram checking function
//checks if the string contains all the letters in the alphabet
int check4pangram(char *sentence)
 {
    char character = 'a'; /* initialize character*/


	for (character='a';character<='z';character++) //the for loop goes through each letter in the alphabet to see if they are all contained in the users string
	{

	if ( strchr( sentence, character ) != NULL ) //if the loop does not reach the end, the if function exits and returns to the next letter in the alphabet
	{
	}
	else
	{
	printf("is not pangram"); //however, if the letter is not in the sentence then the sentence cannot be a pangram
	return 0;//return to main if it is not a pangram
	}


}
printf("is pangram!");
return 0; //return to main if it is a pangram
}

/*--------------------------------------------------*/
//missing letters function
//displays all the letters in the alphabet that are not in the pangram
int missingLetters(char *sentence)
{
    char character1 = 'a'; /* initialize character1 */

	printf("\nThe following letter(s) are missing:");

    for (character1='a';character1<='z';character1++)
    {

	    if ( strchr( sentence, character1 ) != NULL ) //if the loop does not reach the null character at the end of the sentence then continue
    	{
	    }
    	else
	    { 
    	printf( "%c, ", character1);//if the character is not found, it is displayed
	    }
    }

return 0;//return control to main
}

/*------------------------------------------------*/
//tautogram checking function
//checks if the first letter in the sentence is the same as all others after a white space

 
int isTautogram(char *sentence)
{ 
    char *tokenPtr; // create a char pointer
	tokenPtr = strtok( sentence, " " ); //a token is created everytime there is a white space
	
        while ( tokenPtr != NULL )//as long as the token has not pointed to NULL, then there are still more words
	    { 
		    if (sentence[0] == tokenPtr[0])//if the first letter is the same as the first letter in the next token
		    {
		    tokenPtr = strtok( NULL, " " ); //get the next token and
		    }
		    else
		    {
		    printf("\nIs not a tautogram\n");//if the first character is not the same then it cannot be a tautogram
		    return 0;//control is returned to main
    		}
	    }
printf("\nIs tautogram\n");//if the loop is complete it must be a tautogram 
return 0;//control is returned to main
}