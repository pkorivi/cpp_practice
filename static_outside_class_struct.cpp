#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

//static outside a class/Struct - Its internal, only visible to that translation unit its declared in
//static inside a class/Struct -  shares memory with all the instances of class/struct

//This variable is only linked in this file -
//lets say s_var is defined in other file without static it works fine as the compiler links each file seperately.
//now if staic is not used then both files have same declaration, this fails. one way to over come is use extern int s_var in other file
static int s_var = 5;

//static can be added to functions also thus they can be only linked to the same file
static int get_int(){
  return 5;
}

int main(){
  return 0;
}
