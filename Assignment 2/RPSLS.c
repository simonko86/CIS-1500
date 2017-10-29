
#include <stdio.h>

void mainGame(char player1[30],char player2[30]); //function prototype

int main(int argc, char const *argv[])
{
	char name1[30];
	char name2[30];

	printf("Welcome to the main game\n");
	printf("Enter player 1 name:\n");
	fgets(name1, 30, stdin);
	printf("Enter player 2 name:\n");
	fgets(name2, 30, stdin);
	mainGame(name1,name2);
	return 0;
}

void mainGame(char player1[30],char player2[30])
{
	int score1 = 0;
	int score2 = 0;
	char player1Choice[10];
	char player2Choice[10];
	char userInput[10];

	printf("Do you want to play?\n");
	printf("To quit press 'q'\n");
	fgets(userInput, 10, stdin);

	while (userInput[0] != 'q')
	{
		printf("Rock = R, Paper = P, Lizard = L, Scissor = S, Spock = K\n");
		printf("Player 1 what is your choice?\n");
		fgets(player1Choice, 10, stdin);
		printf("Player 2 what is your choice?\n");
		fgets(player2Choice, 10, stdin);

		if ((player1Choice[0] == player2Choice[0]))
		{
			/* no score */
		}
		else if ((player1Choice[0] == 'S' && player2Choice[0] == 'P') || (player1Choice[0] == 'P' && player2Choice[0] == 'R') ||
			(player1Choice[0] == 'R' && player2Choice[0] == 'L') || (player1Choice[0] == 'L' && player2Choice[0] == 'K') ||
			(player1Choice[0] == 'K' && player2Choice[0] == 'S') || (player1Choice[0] == 'S' && player2Choice[0] == 'L') ||
			(player1Choice[0] == 'L' && player2Choice[0] == 'P') || (player1Choice[0] == 'P' && player2Choice[0] == 'K') ||
			(player1Choice[0] == 'K' && player2Choice[0] == 'R') || (player1Choice[0] == 'R' && player2Choice[0] == 'S'))
		{
			score1++;
			//increment player1 score
		}
		else if ((player1Choice[0] == 'P' && player2Choice[0] == 'S') || (player1Choice[0] == 'R' && player2Choice[0] == 'P') ||
			(player1Choice[0] == 'L' && player2Choice[0] == 'R') || (player1Choice[0] == 'K' && player2Choice[0] == 'L') ||
			(player1Choice[0] == 'S' && player2Choice[0] == 'K') || (player1Choice[0] == 'L' && player2Choice[0] == 'S') ||
			(player1Choice[0] == 'P' && player2Choice[0] == 'L') || (player1Choice[0] == 'K' && player2Choice[0] == 'P') ||
			(player1Choice[0] == 'R' && player2Choice[0] == 'K') || (player1Choice[0] == 'S' && player2Choice[0] == 'R'))
		{
			score2++;
			//increment player2 score
		}
		else
		{

		}

		printf("Player 1, %s score: %d\nPlayer 2, %s score: %d\n",player1, score1, player2, score2 );
		printf("Do you want to play again?\n");
		printf("To quit press 'q'\n");
	}
}