/*
Smart pointers
*/

#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Entity{
public:
  Entity(){
    std::cout << "create entity" << '\n';
  }
  ~Entity(){
    std::cout << "Destroyed entity" << '\n';
  }
  void print_(){
    std::cout << "print " << '\n';
  }
};

int main() {
  //Unique Pointers
  {//make a new scope
    // for unique points constructor should be called explicityly
    //unique_ptr<Entity> entity(new Entity()); //this works but not the prefered way
    //preferred way is to call make unique
    unique_ptr<Entity> entity = make_unique<Entity>();
    entity->print_();
  }
  //unique pointers cannot be copied. If a copy happens then both point to same location
  //and if one is deleted the other gets sort of unknwon so this behavior is not supported by compiler

  //Shared Pointers solve this problem by allowing coping by maintaining something called reference count
  {
    shared_ptr<Entity> s1;
    {
      shared_ptr<Entity> shared_entity = make_shared<Entity>();
      s1 = shared_entity;
      weak_ptr<Entity> weak_entity
      weak_entity = shared_entity;
      std::cout << "inside" << '\n';
    }
    std::cout << "outside" << '\n';
  }
  //Here shared_ptr increses count when it gets assigned to s1 and will delete the entity only after the s1 also goes out of scope the entity gets deleted

  //next comes weak_ptr
  // weak_ptr<Entity> weak_entity creates a weak pointer but when a shared_ptr is assigned to it it will not incfement the reference count. This is used to check if the pointer is still
  // valid/ is there something etc. Thus not affecting the behavior of the shared_ptr


  return 0;
}
