#include <string>
#include <cstdlib>
#include "test1.h"
#include <iostream>
using namespace std;

void tic :: excute(int AI) {                    //AI Steps
switch (AI) {

case 1:
        loc =1;
        step++;
        break;

case 2:
        if(back_ground[9] == Blank){
        loc = 9;
        }
        else{
        loc = 3;
        }
        step++;
        break;

case 3:
        if(back_ground[1]=="X" && back_ground[3]=="X" && back_ground[2]==Blank){
            loc = 2;
            step++;
            break;
        }
        else if(back_ground[4]=="O" && back_ground[5]=="O" && back_ground[6]==Blank){
            loc = 6;
            step++;
            break;
        }
        else if(back_ground[2]=="O" && back_ground[5]=="O" && back_ground[8]==Blank){
            loc = 8;
            step++;
            break;
        }
        else if(back_ground[5]=="O" && back_ground[6]=="O" && back_ground[4]==Blank){
            loc = 4;
            step++;
            break;
        }
        else if(back_ground[5]=="O" && back_ground[8]=="O" && back_ground[2]==Blank){
            loc = 2;
            step++;
            break;
        }
        else if(back_ground[5] == Blank){
        loc = 5;
        step++;
        break;
        }
        else if (back_ground[7] == Blank){
        loc = 7;
        step++;
        break;
        }else if (back_ground[3] == Blank){
        loc = 3;
        step++;
        break;
        }
case 4:
         if(back_ground[1]=="X" && back_ground[2]=="X" && back_ground[3]==Blank || back_ground[6]=="X" && back_ground[9]=="X" && back_ground[3]==Blank ){
            loc = 3;
            step++;
            break;
        }
        else if(back_ground[3]=="X" && back_ground[9]=="X" && back_ground[6]==Blank){
            loc = 6;
            step++;
            break;
        }
        else if(back_ground[7]=="O" && back_ground[9]=="O" && back_ground[8]==Blank){
            loc = 8;
            step++;
            break;
        }
        else if(back_ground[5]=="O" && back_ground[7]=="O" && back_ground[3]==Blank){
            loc = 3;
            step++;
            break;
        }
        else if(back_ground[3]=="O" && back_ground[5]=="O" && back_ground[7]==Blank){
            loc = 7;
            step++;
            break;
        }
        else if(back_ground[8]=="O" && back_ground[9]=="O" && back_ground[7]==Blank){
            loc = 7;
            step++;
            break;
        }
        else if(back_ground[7]=="X" && back_ground[9]=="X" && back_ground[8]==Blank){
            loc = 8;
            step++;
            break;
        }

        else if(back_ground[4] == Blank){
        loc = 4;
        step++;
        break;
        }
        else if(back_ground[2] == Blank){
        loc = 2;
        step++;
        break;
        }else if(back_ground[8] == Blank){
        loc = 8;
        step++;
        break;
        }else if(back_ground[6] == Blank){
        loc = 6;
        step++;
        break;
        }
case 5:
        if(back_ground[4] == Blank){
        loc = 4;
        step++;
        break;
        }
        else if (back_ground[7] == Blank){
        loc = 7;
        step++;
        break;
        }
        else if(back_ground[2] == Blank){
        loc = 2;
        step++;
        break;
        }else if(back_ground[8] == Blank){
        loc = 8;
        step++;
        break;
        }else if(back_ground[6] == Blank){
        loc = 6;
        step++;
        break;
        }
}
}


void tic::set_up(){                          //set up the empty array
    {

for (int i = 1; i < MaxSize; i++)
{
    back_ground[i] = Blank;
}
}
}

void tic::Play(){                     //function for entering the X and O
    while (Over)
{
    Good = false;
    while (!Good)
    {
        cout << "Player 1 ";
        cout << "Enter your Location: ";
        if(step < 7){
        excute(step);                            //AI input
        //loc = rand_0ton1(9);                   //random steps for AI
        }

        if (loc >= 1 && loc <= 9 && back_ground[loc] == Blank)                 //to check if the location is occupied or not
        {
            Good = true;
            back_ground[loc] = "X";
        }

    }
    board();

    if (Game_Over(back_ground))                            //function for end the game or restart the game
    {
        Over = true;
        Good = true;
    }else{
    Good = false;
    }
    while (!Good)
    {
        cout << "Player 2 ";
        cout << "Enter your Location: ";
        cin >> loc;                                      //player input
        if (loc >= 1 && loc <= 9 && back_ground[loc] == Blank)
        {
            Good = true;
            back_ground[loc] = "O";
        }
        else
        {
            cout << "That location is occupied." << endl;
            board();
        }
    }
    board();

    if (Game_Over(back_ground))              //check for winning
    {
        while(true){
      cout << "Do you want to restart the game (Yes = 1, No = 0): ";
      cin >> decision;
      if (decision == 1)           //1 for restart
      {
         set_up();
         Over = true;
         step = 1;
         break;
      }
      if (decision == 0)           //0 for end
      {
          Over = false;
          break;
      }
      else
      {
        cout << "Entered the wrong letter "<< endl;
      }
        }
}
}
}
void tic::display()                                      //Display the head sentence
{
    cout << "Tic Tac Toe Game Starts" << endl;\
    cout << "        Welcome to TIC TAC TOE          "<<endl<<endl;;

	cout << "       Player 1 (X)  -  Player 2 (O)  " << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << "1" << "  |  " << "2" << "  |  " << "3" << endl;

	cout << "_____|_____|___" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << "4" << "  |  " << "5" << "  |  " << "6" << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << "7" << "  |  " << "8" << "  |  " << "9" << endl;

	cout << "     |     |     " << endl << endl;
}
bool tic::Game_Over(string back_ground[MaxSize])                 //function to check if the game ends or not
{

if (back_ground[1] == "X" && back_ground[2] == "X" && back_ground[3] == "X")
{
    cout << endl << "Game over, player X wins" << endl;
    return true;
}
if (back_ground[1] == "O" && back_ground[2] == "O" && back_ground[3] == "O")
{
    cout << endl << "Game over, player O wins" << endl;
    return true;
}
if (back_ground[4]=="X" && back_ground[5]=="X" && back_ground[6]=="X")
{
    cout <<endl << "Game over, player X wins" <<endl;
    return true;
}
if (back_ground[4]=="O" && back_ground[5]=="O" && back_ground[6]=="O")
{
    cout <<endl << "Game over, player O wins" <<endl;
    return true;
}
if (back_ground[1]=="X" && back_ground[4]=="X" && back_ground[7]=="X")
{
    cout <<endl << "Game over, player X wins" <<endl;
    return true;
}
if (back_ground[1]=="O" && back_ground[4]=="O" && back_ground[7]=="O")
{
    cout <<endl << "Game over, player O wins" <<endl;
   return true;
}
if (back_ground[7]=="X" && back_ground[8]=="X" && back_ground[9]=="X")
{
    cout <<endl << "Game over, player X wins" <<endl;
    return true;
}
if (back_ground[7]=="O" && back_ground[8]=="O" && back_ground[9]=="O")
{
    cout <<endl << "Game over, player O wins" <<endl;
    return true;
}
if (back_ground[2]=="X" && back_ground[5]=="X" && back_ground[8]=="X")
{
    cout <<endl << "Game over, player X wins" <<endl;
    return true;
}
if (back_ground[2]=="O" && back_ground[5]=="O" && back_ground[8]=="O")
{
    cout <<endl << "Game over, player O wins" <<endl;
    return true;
}
if (back_ground[3]=="X" && back_ground[6]=="X" && back_ground[9]=="X")
{
    cout <<endl << "Game over, player X wins" <<endl;
    return true;
}
if (back_ground[3]=="O" && back_ground[6]=="O" && back_ground[9]=="O")
{
    cout <<endl << "Game over, player O wins" <<endl;
    return true;
}
if (back_ground[1]=="X" && back_ground[5]=="X" && back_ground[9]=="X")
{
    cout <<endl << "Game over, player X wins" << endl;
    return true;
}
if (back_ground[1]=="O" && back_ground[5]=="O" && back_ground[9]=="O")
{
    cout <<endl << "Game over, player O wins" <<endl;
    return true;
}
if (back_ground[3]=="X" && back_ground[5]=="X" && back_ground[7]=="X")
{
    cout <<endl << "Game over, player X wins" <<endl;
    return true;
}
if (back_ground[3]=="O" && back_ground[5]=="O" && back_ground[7]=="O")
{
    cout <<endl << "Game over, player O wins" <<endl;
    return true;
}
if (back_ground[1] != Blank && back_ground[2] != Blank && back_ground[3] != Blank && back_ground[4] != Blank && back_ground[5] != Blank
         && back_ground[6] != Blank && back_ground[7] != Blank && back_ground[8] != Blank && back_ground[9] != Blank )
{
    cout << endl << "Game over, draw"  << endl;
    return true;
}
else
{
    cout << "Next players turn" <<endl;
}

return false;
}


void tic::board()                                    //function that display the game
{
	cout << "        Welcome to TIC TAC TOE          "<<endl<<endl;;

	cout << "       Player 1 (X)  -  Player 2 (O)  " << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << back_ground[1] << "  |  " << back_ground[2] << "  |  " << back_ground[3] << endl;

	cout << "_____|_____|___" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << back_ground[4] << "  |  " << back_ground[5] << "  |  " << back_ground[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << back_ground[7] << "  |  " << back_ground[8] << "  |  " << back_ground[9] << endl;

	cout << "     |     |     " << endl << endl;
}

