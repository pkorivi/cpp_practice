#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// static inside a struct/Class

//

class entity{
public:
  static int var;
  int a;
  //static methods cannot access non static members
  static void print_(){
    std::cout << "static func" << '\n';
    std::cout << a << '\n'; //this fails as a is non static
  }
};

//this is needed for linker to link and code to work for all static variables
int entity::var;

int main(int argc, char const *argv[]) {
  entity a;
  entity b;
  entity c;
  a.var=5;
  std::cout << b.var << '\n'; //as var is static, there is only one instance of var for all instances of entity
  std::cout << c.var<< " " << '\n';
  c.print_();
  //Its good to refer to it as than based on objects as there is no real meaning of it as only one instance is used everywhere
  std::cout << entity::var << '\n';
  entity::print_();

  return 0;
}
