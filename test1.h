#ifndef TEST1_H
#define TEST1_H
#include <string>
#include <cstdlib>

class tic                              //class that defines the variables and function
{
    private:
        std::string back_ground[10];
        int decision;
        int step = 1;
        int loc = 0;
        bool Over = true;
        bool Good = false;
        const std::string Blank = " ";
        const static int MaxSize = 10;
    public:
                                             //functions can be found under the main function
        void board();
  const void reset();                       //reset the game
        bool Game_Over(std::string back_ground[MaxSize]);
        void display();
        void set_up();
        void Play();
        void excute(int);         //AI input
       // int rand_0ton1 (int n) {return rand() %n+1;}

};
#endif // TEST1_H
