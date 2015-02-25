//  Yihao Cheng
//  Xiao Jiang
//  Andrew Nanjad
//  Tenzin Kalsang
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "test1.h"
using namespace std;


int main()
{
    //srand(time(NULL));
    tic a;                     //call the class
    a.set_up();                //call the function set_up
    a.display();               //call function display
    a.Play();                  //call function Play

system("pause");
return 0;
}
