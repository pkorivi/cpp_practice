//Understanding move semantics -
//TODO - this code doesnt compile, make it work - https://www.youtube.com/watch?v=IOkgBrXCtfo
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;
//Lvalue- rvalue reference; move simantics

void print_(int& i){std::cout << "lvalue reference" << '\n';}
void print_(int&& i){std::cout << "rvalue reference" << '\n';}
//dont add void print_(int i) - this will confuse compiler

class en{
  private:
    int sz;
    double* arr_;
  public:
    en(const en& rhs){//copy constructor - Deep copy
      sz = rhs.sz;
      arr_ = new double[sz];
      for (size_t i = 0; i < sz; i++) {
        arr_[i]=rhs.arr_[i];
      }
    }
    en(en&& rhs){ //Move constructor - shallow copy-- //no const as we need to chnage the rhs value
      sz = rhs.sz;
      arr_ = rhs.arr_; //assign the current created object reference to the new object instead of copying into a new one - saving computation.
      rhs.arr_=nullptr; // this is important, if this is not done, both will be pointing to same location and when rhs gets destroyed our new variable will be without data.
    }
    ~en(){delete arr_;}
};

void foo(en v);
void foo_by_ref(en& v);

en createen(); //creates en

int main() {
  // int a=5; //a is Lvalue
  // int& b =a; //b is lvalue reference
  // //int&& c; //c is rvalue reference
  // print_(a); //calls  print_(int& i)
  // print_(6); //calls  print_(int&& i)

  //reuse is lvalue
  en reuse = createen();
  //when below foo is called expensive copy constructor is triggered
  foo(reuse);//1 //this creates a copy of reuse and passes it to - copy is expensive operation and this might be ok here as reuse can be used multiple times
  foo_by_ref(reuse);//2 // this does not call any constructor

  //For the below function if there is no move, a class is created and a costly copy is initiated which is not really needed
  //here createen will return a rvalue which will be destroyed immediately after copying in copy constructor, //better way is to use a move constructor
  //Now with defining move constructor, as createen returns a rvalue, move constructor is called with rvalue reference and an inexpensive shallow copy is called.
  foo(createen());//3

  //One more but be careful around this
  //Now lets say the reuse object created is no longer needed and you want to use it directly instead of copying in next funxtion call
  foo(std::move(reuse));//4 //this moves the reuse into object of foo for processing and reuse.arr_ = nullptr
  //rese is destroyed here & deletes array, in this case a null pointer- so dont use reuse after this -

  //out of 1-4, 2 is least expensive with no constructor, 3,4 are little more expensive
  //because of move operation and 1 is most expensive

  //Overloading copy, copy assignment with move and move assignment is an efficient way to use move semantics


  /*
  alternative to move constructor??
  use foo_by_value(en v) && foo_by_ref(en& v) This do the same job but messes up with multiple function declerations etc for same functionality
  */




  return 0;
}
