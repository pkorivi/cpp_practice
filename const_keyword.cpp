#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class entity{
private:
  int x;
  int* y;// same as int* y,x;  here y is pointer but x is integer
public:
  //const like this in end works only inside classes
  int getx() const{ //here const after function paranthesis and before flower braces states that this function cannot modify any members of the class
    //x =4; this fails
    return x;
  }
  //this below functions returns a constant pointer to a constant integer and the function cannot modify any of the contents of class
  const int* const gety() const{
    return y;
  }
};

//here e is taken as const reference thus contents of e cannot be modified
void print_entity(const entity& e){
  std::cout << e.getx() << '\n'; // this works but if I remove const from getx, getx will not
  //gurantee that it will not modify the entity which is in conflict and function will not work
}

int main(){
  const int b =5;
  //a=2; // cannot happen as a is const
  // below is same as int const* a;
  const int* a = new int; //I cannot modify the contents of that pointer
  //*a =2; //this fails as the content is defined as constant so assigning new value fails
  a=(int*)&b; // this works as pointer address can be modified

  //const after * makes 'a' constant.
  int* const c = new int; // here contents can be changed but  pointer cannot be reassigned
  *c =6;
  //c = nullptr; // this fails - pointer cannot be reassigned
  int z =5;
  const int* const d = &z; //I cannot change neither pointer nor the contents of it

  // Dont do this - deferencing a const with non const pointer
  // a=(int*)&b;
  // std::cout << *a << '\n';
  // *a = 7;
  std::cout << *a << '\n';
  std::cout << b << '\n';
  std::cout << *c << '\n';

  ///////////////////////////////////////////////
  entity e;
  print_entity(e);
//using mutable keyworkd, mutable int a. We will be able to modify a even in a const function
  return 0;
}
