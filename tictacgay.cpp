#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
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
const char BOT = 'O' ;


void displayBoard() ;//display board function
int checkWin (int checkY,int checkX) ;
void resetGame () ;
void botToGo ();
void botToBlock ();


int main()
{
displayBoard(); //display board before the game start
char answer ;
int x=0;
int y=0;
int gameModeChoosing;


cout<<"Choose game mode..."<<endl;
cout<<"1- 1 Player (Easy Mode)"<<endl;
cout<<"2- 2 Players "<<endl;
cin>>gameModeChoosing;

if(gameModeChoosing==2)
{
for(int i = 25 ; i > 0  ; i-=1)
{
        if (i%2 != 0)//Player 1 move-----------------------------
            {
                askAgain_4:
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
                    goto askAgain_4;
                }//end if-------------------------------------------

            } else if (i%2 == 0) // Player 2 move-----------------------------
            {   
                askAgain_2:
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
                    goto askAgain_2;
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
}else{
    for(int i = 25 ; i > 0  ; i-=1)
    {
            if (i%2 != 0)//Player 1 move-----------------------------
                {
                    askAgain_3:
                    cout<< "Player enter row: "   << endl ;
                    cin >> y ;
                    cout<< "Player enter column: " << endl ;
                    cin >> x ;

                    if (y >= 1 && y <= 5 && x >= 1 && x <= 5 && board[y][x] == ' ' )
                    {
                        board [y][x] = PLAYER1 ;
                        checkWin(y,x);
                    } else
                    {
                        cout << "invalid coordinate" <<endl ;
                        goto askAgain_3;
                    }//end if-------------------------------------------

                } else if (i%2 == 0) // Bot move-----------------------------
                {
                        botToBlock ();
                        checkWin(y,x);
                        
                }
                displayBoard();
                


            // decide if a player have won or draw
            if (checkWin(y,x) == 4 && y>=1 && y<=5 && x>=1 && x<=5 )
            {
                if (board[y][x]== PLAYER1)
                {
                    cout << "You won."<< endl ;
                } else if(board[y][x] == BOT)
                {
                    cout<< "You lose." <<endl;
                }// end if
                i=-1;

            } else if(i == 1 )
            {
                cout<< "DRAW" << endl ;
            }
    }
}
    askAgain_1:
    cout << "Do you want to play again? [Y/N]" << endl ; // ask player to play again
    cin >> answer ;
    answer = toupper(answer) ;
    if (answer == 'Y')
    {
        resetGame();
    } else if (answer == 'N')
    {
        cout << "Thank you for playing" << endl ;
        return 0;
    } else
    {
        cout <<"Invalid answer" << endl;
        goto askAgain_1;
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

void botToGo (){
    int n1,n2;
    goBack:
    srand(time(NULL));
    int randomNum1 = rand() %5+1;
    int randomNum2 = rand() %5+1;
    n1=randomNum1; n2=randomNum2;
    if (board[n1][n2] == ' ')
        board[n1][n2] = BOT; 
    else
        goto goBack;
}
 void botToBlock (){
     
    

    
    for(int i=1;i<=5;i++)
        { 
            for(int j=1;j<=5;j++)
            {   
                int flag = 0, right_down = 0, left_up = 0;
                //horizontal check
                if (board[i][j]==PLAYER1){
                    
                    if (board[i][j+1]==PLAYER1 && board[i][j-1]==PLAYER1 && j==4){
                        if (board[i][2] == ' ')
                        {board[i][2]= BOT; 
                        goto exit; }
                        }
                    if (board[i][j+1]==PLAYER1 && board[i][j-1]==PLAYER1 && j==2){
                        if (board[i][4] == ' ')
                        {board[i][4]= BOT; 
                        goto exit;}
                        }
                    if (board[i][j-1]==PLAYER1 && j==3){
                        srand(time(NULL));
                        int numChoose = rand() % 2 +1; 
                        if(numChoose==1 && board[i][j+1]== ' '){
                        board[i][j+1]= BOT; 
                        goto exit;
                        }
                        else if(numChoose==2 && board[i][j-2]== ' '){
                        
                        board[i][j-2]= BOT;  cout<<i<<" "<<j;
                        goto exit;
                        }
                    }
                    if (board[i][j+1]==PLAYER1 && j==3){
                        srand(time(NULL));
                        int numChoose = rand() % 2 +1;
                        if(numChoose==1 && board[i][j-1] == ' '){
                        board[i][j-1]=BOT; 
                        goto exit;
                        }
                        else if(numChoose==2 && board[i][j+2] == ' '){
                        board[i][j+2]= BOT; 
                        goto exit;
                        }
                        }
                        flag = 0; right_down = 0; left_up = 0;
                }
                //vertical check
                if (board[i][j]==PLAYER1){
                    if (board[i+1][j]==PLAYER1 && board[i-1][j]==PLAYER1 && i==4){
                        if (board[2][j] == ' ')
                        {board[2][j]= BOT; 
                        goto exit;}
                        }
                    if (board[i+1][j]==PLAYER1 && board[i-1][j]==PLAYER1 && i==2){
                        if (board[4][j] == ' ')
                        {board[4][j]= BOT; 
                        goto exit;}
                        }
                    if (board[i-1][j]==PLAYER1 && i==3){
                        srand(time(NULL));
                        int numChoose = rand() % 2 +1; 
                        if(numChoose==1 && board[i+1][j]== ' '){
                        board[i+1][j]= BOT; 
                        goto exit;
                        }
                        else if(numChoose==2 && board[i-2][j]== ' '){
                        board[i-2][j]= BOT;
                        goto exit;
                        }
                    }
                    if (board[i+1][j]==PLAYER1 && i==3){
                        srand(time(NULL));
                        int numChoose = rand() % 2 +1;
                        if(numChoose==1 && board[i-1][j] == ' '){
                        board[i-1][j]=BOT; ;
                        goto exit;
                        }
                        else if(numChoose==2 && board[i+2][j] == ' '){
                        board[i+2][j]= BOT; ;
                        goto exit;
                        }
                        }
                        flag = 0; right_down = 0; left_up = 0;
                }
                       
                //diagonal 1 check

            }   
            } 
            
            botToGo ();
            exit:
            int nothing=0;
} // end botToBlock Function


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
        while (board[checkY][checkX] == board[checkY][counterColumn] && winStreak<4 ) // check to the right_down
        {

            winStreak ++;
            counterColumn ++;
            if(board[checkY][checkX] != board[checkY][counterColumn]) // check to the left_up
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
        while (board[checkY][checkX] == board[counterRow][counterColumn] && winStreak<4 ) // check diagonally upwards to the left_up
        {
            winStreak ++;
            counterRow --;
            counterColumn ++;
            if(board[checkY][checkX] != board[counterRow][counterColumn]) // check diagonally downwards to the right_down
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
        while (board[checkY][checkX] == board[counterRow][counterColumn] && winStreak<4 ) // check diagonally upwards to the left_up
        {
            winStreak ++;
            counterRow --;
            counterColumn --;
            if(board[checkY][checkX] != board[counterRow][counterColumn]) // check diagonally downwards to the right_down
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



