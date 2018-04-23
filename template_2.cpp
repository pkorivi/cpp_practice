#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

template<typename T> // or template<class T> also works
void print_(T val){
  std::cout << val << '\n';
}

//Non type parameters for templates
template<int N>  //This could also be template<typename T, int N>
class my_arr{
  private:
    int A[N]; //T A[N] - thus the type of array can also be defined at runtime
  public:
    int get_array_size(){return N;}

};

int main() {
  //Mentioning of float, string is not needed if the compiler can figureout the type implicityly
  print_(1.345); //print_<float>(1.345)
  print_("anna"); //print_<string>("anna")
  print_(121); //print_<int>(121);
  //Here we can create an array at compile time by using template paramaters
  my_arr<5> x; //my_arr<int,5> x;
  std::cout << x.get_array_size() << '\n';
  return 0;
}
