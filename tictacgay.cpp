#include <iostream>

using namespace std;

char board [7][7] //because of how the my checkWin() works, I have to make the board bigger. The outer ring is not accessible by the player.
{
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

const char PLAYER1 = 'X' ;
const char PLAYER2 = 'O' ;

void displayBoard() ;//display board function
int checkWin (int checkY,int checkX) ;
void resetGame () ;

int main()
{
displayBoard(); //display board before the game start
char answer ;
int x=0;
int y=0;
for(int i = 25 ; i > 0  ; i-=1)
{
        if (i%2 != 0)//Player 1 move-----------------------------
            {
                cout<< "Player 1 enter row: "   << endl ;
                cin >> y ;
                cout<< "Player 1 enter column: " << endl ;
                cin >> x ;

                if (y >= 1 && y <= 5 && x >= 1 && x <= 5 && board[y][x] == ' ' )
                {
                    board [y][x] = PLAYER1 ;
                    checkWin(y,x);
                } else
                {
                    cout << "invalid coordinate" <<endl ;
                    i++;
                }//end if-------------------------------------------

            } else if (i%2 == 0) // Player 2 move-----------------------------
            {
                cout<< "Player 2 enter row: "   << endl ;
                cin >> y ;
                cout<< "Player 2 enter column: " << endl ;
                cin >> x ;

                if (y >= 1 && y <= 5 && x >= 1 && x <= 5 && board[y][x] == ' ' )
                {
                    board [y][x] = PLAYER2 ;
                    checkWin(y,x);

                } else
                {
                    cout << "invalid coordinate" <<endl ;
                    i++;

                }//end if----------------------------------------------------
            }

            displayBoard();


        // decide if a player have won or draw
        if (checkWin(y,x) == 4 && y>=1 && y<=5 && x>=1 && x<=5 )
        {
            if (board[y][x]== PLAYER1)
            {
                cout << "Player 1 won."<< endl ;
            } else if(board[y][x] == PLAYER2)
            {
                cout<< "Player 2 won." <<endl;
            }// end if
            i=-1;

        } else if(i == 1 )
        {
            cout<< "DRAW" << endl ;
        }
}

    cout << "Do you want to play again? [Y/N]" << endl ; // ask player to play again
    cin >> answer ;
    answer = toupper(answer) ;
    if (answer == 'Y')
    {
        resetGame();
    } else if (answer == 'N')
    {
        cout << "Thank you for playing" << endl ;
    } else
    {
        cout <<"Invalid answer" << endl;
    }//end if

return 0;
}

void displayBoard() // display function
{
    cout<<"PLAYER 1 [X]     PLAYER 2 [O] "<< endl ;
    cout << endl ;

    cout << "               1 | 2 | 3 | 4 | 5 " << endl ;
    cout << "             -------------------" <<endl ;
    cout <<"            1| "<< board[1][1] <<" | "<< board[1][2]<< " | " <<board[1][3]<<" | " <<board[1][4]<< " | " <<board[1][5] << endl ;
    cout << "             |---|---|---|---|---" << endl ;
    cout <<"            2| "<< board[2][1] <<" | "<< board[2][2]<< " | " <<board[2][3]<<" | " <<board[2][4]<< " | " <<board[2][5] << endl ;
    cout << "             |---|---|---|---|---" << endl ;
    cout <<"            3| "<< board[3][1] <<" | "<< board[3][2]<< " | " <<board[3][3]<<" | " <<board[3][4]<< " | " <<board[3][5] << endl ;
    cout << "             |---|---|---|---|---" << endl ;
    cout <<"            4| "<< board[4][1] <<" | "<< board[4][2]<< " | " <<board[4][3]<<" | " <<board[4][4]<< " | " <<board[4][5] << endl ;
    cout << "             |---|---|---|---|---" << endl ;
    cout <<"            5| "<< board[5][1] <<" | "<< board[5][2]<< " | " <<board[5][3]<<" | " <<board[5][4]<< " | " <<board[5][5] << endl <<endl;
} // end displayBoard function
int checkWin (int checkY, int checkX) //checkWin function
{

    int winStreak=0 , counterRow=0, counterColumn=0;


    //check Vertical
     if(winStreak<4)
     {
         counterRow = checkY;
         winStreak = 0 ; //reset winStreak
         while (board[checkY][checkX] == board[counterRow][checkX] && winStreak<4 ) // check upwards
         {

             winStreak ++;
             counterRow ++;
             if(board[checkY][checkX] != board[counterRow][checkX]) // check downwards
             {
                 counterRow = checkY;
                 winStreak--; //because player placement has returned to its original spot winStreak have to decrease by 1 unit
                 while (board[checkY][checkX] == board[counterRow][checkX] && winStreak<4 )
                 {
                     winStreak ++;
                     counterRow --;
                 }//end while
             }//end if
         }//end while
     } //end of check Vertical */


    //check horizontal
    if(winStreak<4)
    {
        counterColumn = checkX;
        winStreak = 0 ; //reset winStreak
        while (board[checkY][checkX] == board[checkY][counterColumn] && winStreak<4 ) // check to the right
        {

            winStreak ++;
            counterColumn ++;
            if(board[checkY][checkX] != board[checkY][counterColumn]) // check to the left
            {
                counterColumn = checkX;
                winStreak--; //because player placement has returned to its original spot winStreak have to decrease by 1 unit
                while (board[checkY][checkX] == board[checkY][counterColumn] && winStreak<4 )
                {
                    winStreak ++;
                    counterColumn --;
                }//end while
            }//end if
        }//end while
    } // end of check horizontal */



    //check diagonal 1
    if(winStreak<4)
    {
        counterRow = checkY;
        counterColumn = checkX;
        winStreak = 0 ; //reset winStreak
        while (board[checkY][checkX] == board[counterRow][counterColumn] && winStreak<4 ) // check diagonally upwards to the left
        {
            winStreak ++;
            counterRow --;
            counterColumn ++;
            if(board[checkY][checkX] != board[counterRow][counterColumn]) // check diagonally downwards to the right
            {
                counterRow = checkY ;
                counterColumn = checkX;
                winStreak--; //because player placement has returned to its original spot winStreak have to decrease by 1 unit
                while (board[checkY][checkX] == board[counterRow][counterColumn] && winStreak<4)
                {
                    winStreak ++;
                    counterRow ++;
                    counterColumn --;
                }//end while
            }//end if
        }//end while
    }//end of diagonal 1 */


    //check diagonal 2
    if(winStreak<4)
    {
        counterRow = checkY;
        counterColumn = checkX;
        winStreak = 0 ; //reset winStreak
        while (board[checkY][checkX] == board[counterRow][counterColumn] && winStreak<4 ) // check diagonally upwards to the left
        {
            winStreak ++;
            counterRow --;
            counterColumn --;
            if(board[checkY][checkX] != board[counterRow][counterColumn]) // check diagonally downwards to the right
            {
                counterRow = checkY ;
                counterColumn = checkX;
                winStreak--; //because player placement has returned to its original spot winStreak have to decrease by 1 unit
                while (board[checkY][checkX] == board[counterRow][counterColumn] && winStreak<4 )
                {
                    winStreak ++;
                    counterRow ++;
                    counterColumn ++;
                }//end while
            }//end if
        }//end while
    }// end of diagonal 2 */

 return winStreak ;

} // end checkWin Function



void resetGame ()
{
        for (int y =1 ; y <=5 ;y++)//for loop reset board
        {
            for(int x=1 ; x <=5; x++)
            {
                board [y][x] = ' ' ;
            }// end for loop
        }// end of for loop
        main(); // repeat the main function
}// end of reset game function
