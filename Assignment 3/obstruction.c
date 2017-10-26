#include <ncurses.h> /* ncurses header to be able to use ncurses library */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void setupGrid(void); /* This function setsup the grid surronding the 6x6 board */
void playGame(void);  /*This function is where the game is played */
void checkWin(char character, int playerNumber); /*This function checks if the 6x6 board is populated if there are more attempts to come */


/*
Main: Describes the game and uses functions to run it
Pre: Pass nothing
Post: Return 0
*/

int main(void)
{
    initscr();
    cbreak();
    noecho();
    mvprintw(5,10,"This is the game Obstruction\n"); /*game instructions and game description */
    mvprintw(6,10,"j=left, k=down, l=right,i=up\n");
    mvprintw(7,10,"x=select, q=quit\n");
    refresh();
    setupGrid();
    playGame();
    endwin(); /* close window */
    return(0);
}

/*
SetupGrid: Uses loops to display the outline of the grid
Pre: Pass nothing
Post: Return nothing
*/

void setupGrid (void)
{
    int x;
    int y;
    attron(A_BOLD);		/*make attribute bold for the border*/
        for (x=0;x<7;x++)
        {
	    mvaddch(0,x,'*');	/*print border across*/
	    mvaddch(7,x,'*');
        }
	for (y=0;y<8;y++)
        {
	    mvaddch(y,0,'*');	/*print side border*/
	    mvaddch(y,7,'*');
        }
    attroff(A_BOLD);

return;
}

/*
playGame: Plays the game Obstruction with 2 players. Displays and checks for any obstruction
Pre: Pass nothing
Post: Return nothing
*/

void playGame (void)
{
    int character;			/*variable to keep track of user input */
    int yCoordinate = 1;		/*variables to keep track of cursor position */
    int xCoordinate = 1;		/*both x and y coordinates */
    int playerNumber = 1;		/*variable to keep track of who's turn it is */
    char a,b,c,d,e,f,g,h,i;		/*assigned variables to check for obstruction */
    char playerOne[30];		/*player's names */
    char playerTwo[30];

    echo();
    mvprintw(3,10,"enter player 1 name:");
    scanw("%s", playerOne);
    refresh();
    mvprintw(3,10,"                                        ");
    refresh();
    mvprintw(3,10,"enter player 2 name:");
    scanw("%s", playerTwo);
    refresh();
    mvprintw(3,10,"                                        ");
    refresh();
    noecho();
    mvprintw(3,10,"%s's turn",playerOne);
    move(1,1); /* Move back to beginning */
    refresh();
    character = getch();/* Await user input */
    refresh();
    while (character != 'q')/*if q is pressed, quit the program*/
    {
        mvprintw(10,10,"                  ");
        refresh();
            if (character == 'i')  		/*i character means UP*/
            {
                yCoordinate--;
                    if (yCoordinate <1)
                    {
                        mvprintw(10,10,"cannot go there");
                        refresh();
                        yCoordinate++;
                        move(yCoordinate,xCoordinate);
                        refresh();
                        character = getch();
                        mvprintw(10,10,"               ");
                    }
                    else
                    {
                        move(yCoordinate,xCoordinate);	/*move cursor to new position*/
                        refresh();			/*display period*/
                        character = getch();		/*wait for next character*/
                    }
            }
            else if (character == 'j')	/*j character means LEFT*/
            {
                xCoordinate--;			/*move x position left*/
                    if (xCoordinate <1)
                    {
                        mvprintw(10,10,"cannot go there");
                        refresh();
                        xCoordinate++;
                        move(yCoordinate,xCoordinate);
                        refresh();
                        character = getch();
                        mvprintw(10,10,"               ");
                    }
                    else
                    {
                        move(yCoordinate,xCoordinate);	/*move cursor to new position*/
                        refresh();			/*display period*/
                        character = getch();		/*wait for next character*/
                    }
            }
            else if (character == 'k')	/*k character means DOWN*/
            {
                yCoordinate++;			/*move y position down*/
                    if (yCoordinate >6)
                    {
                        mvprintw(10,10,"cannot go there");
                        refresh();
                        yCoordinate--;
                        move(yCoordinate,xCoordinate);
                        refresh();
                        character = getch();
                        mvprintw(10,10,"               ");
                    }
                    else
                    {
                        move(yCoordinate,xCoordinate);	/*move cursor to new position*/
                        refresh();			/*display period*/
                        character = getch();		/*wait for next character*/
                    }
            }
            else if (character == 'l')	/*k character means RIGHT*/
            {
                xCoordinate++;			/*move x position right*/
                    if (xCoordinate >6)
                    {
                        mvprintw(10,10,"cannot go there");
                        refresh();
                        xCoordinate--;
                        move(yCoordinate,xCoordinate);
                        refresh();
                        character = getch();
                        mvprintw(10,10,"               ");
                    }
                    else
                    {
                        move(yCoordinate,xCoordinate);	/*move cursor to new position*/
                        refresh();			/*display period*/
                        character = getch();		/*wait for next character*/
                    }
            }
            else if (character =='x')
            {
                a = mvinch(yCoordinate-1,xCoordinate-1);	/*check for obstruction*/
                b = mvinch(yCoordinate-1,xCoordinate);
                c = mvinch(yCoordinate-1,xCoordinate+1);
                d = mvinch(yCoordinate+1,xCoordinate-1);
                e = mvinch(yCoordinate+1,xCoordinate);
                f = mvinch(yCoordinate+1,xCoordinate+1);
                g = mvinch(yCoordinate,xCoordinate-1);
                h = mvinch(yCoordinate,xCoordinate+1);
                i = mvinch(yCoordinate,xCoordinate);
                    if ((a == '1') || (b == '1') || (c == '1') || (d == '1') || (e == '1') || (f == '1') || (g == '1') || (h == '1') || (i == '1')
                     || (a == '2') || (b == '2') || (c == '2') || (d == '2') || (e == '2') || (f == '2') || (g == '2') || (h == '2') || (i == '2'))
                    {
                        mvprintw(10,10,"cannot go here");
                        refresh();
                        move(yCoordinate,xCoordinate);
                        refresh();
                        character = getch();
                        mvprintw(10,10,"              ");
                    }
                    else
                    {
                        mvprintw(yCoordinate,xCoordinate,"%d",playerNumber);
                        mvaddch(yCoordinate-1,xCoordinate-1,'0');
                        mvaddch(yCoordinate-1,xCoordinate,'0');
                        mvaddch(yCoordinate-1,xCoordinate+1,'0');
                        mvaddch(yCoordinate+1,xCoordinate-1,'0');
                        mvaddch(yCoordinate+1,xCoordinate,'0');
                        mvaddch(yCoordinate+1,xCoordinate+1,'0');
                        mvaddch(yCoordinate,xCoordinate-1,'0');
                        mvaddch(yCoordinate,xCoordinate+1,'0');
                        checkWin(character, playerNumber);
                        setupGrid();
                        move(yCoordinate,xCoordinate);
                        refresh();
                        character = getch();
                            if (playerNumber==1)
                            {
                                mvprintw(3,10,"                                        ");
                                refresh();
                                playerNumber++;
                                mvprintw(3,10,"%s's turn",playerTwo);
                            }
                            else
                            {
                                mvprintw(3,10,"                                        ");
                                refresh();
                                playerNumber--;
                                mvprintw(3,10,"%s's turn",playerOne);
                            }
                    }
            }
        else				/*any other character is pressed*/
        {
            move(yCoordinate,xCoordinate);
            character = getch();		/*do nothing and await another character*/
            refresh();
        }
    }
return;
}

/*
checkWin: Checks on each allowed attempt if the game is won. Declare the winner, and keep track of the score
Pre: Pass character variable, and playerNumber variable
Post: Return nothing
*/

void checkWin(char character, int playerNumber)
{
    int y; /*variable declaration for for loops*/
    int x;
    static int playCounter = 0; /*these variables are declared as static so they stay in memory rather than lost when the function closes*/
    static int playerOnewin = 0;
    static int playerTwowin = 0;

    for (y = 1;y < 7;y++)
    {
        for (x = 1;x < 7;x++)
        {
            int check = mvinch(y,x);
                if ((check == '0')||(check == '1')||( check == '2'))	/*if all the cells are filled, then the game is over*/
                {
                    refresh();
                }
                else
                {
                    return;
                }
        }
        x = 1;
    }
    for (y = 1;y < 7;y++)
    {
        for (x = 1;x < 7;x++)
        {
            mvaddch(y,x,' ');
        }
        x = 1;
    }
    if (playerNumber == 1)
    {
        playerOnewin++;
        playCounter++;
    }
    else
    {
        playerTwowin++;
        playCounter++;
    }

    mvprintw(1,10,"Games played: %d", playCounter);
    mvprintw(2,10,"Player 1 wins: %d", playerOnewin);
    mvprintw(2,30,"Player 2 wins: %d", playerTwowin); /*display the games played, wins for each player*/
    attron(A_STANDOUT | A_UNDERLINE);	/*make nice and pretty for the winner */
    mvprintw(10,10,"Player %d wins!!!!", playerNumber);
    attroff(A_STANDOUT | A_UNDERLINE);
    setupGrid();
    refresh();
    return;
}


