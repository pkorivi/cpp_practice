#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

/* //without virtual
class Entity{
public:
  string getname(){return "entity:";}
};
*/
class Entity{
public:
  virtual string getname(){return "entity:";}
};

//here player is superset of entity, it will always have what entity has and probably more
class player : public Entity{
public:
  string m_name;
  player(const string& name) : m_name(name){}
  string getname() override{return m_name;}
};

int main(){
  //the usual way
  Entity* e = new Entity();
  std::cout << e->getname() << '\n';//entity
  player* p = new player("rephla");
  std::cout << p->getname() << '\n';//rephla

  //trouble here p of type player is assigned to entity pointer
  Entity* e1 = p;
  std::cout << e1->getname() << '\n'; //(prints entity - if virtual is not used in the baseclass In general methods are called by the type of the object)
  //Now in baseclass virtual is used, it will point the function to the over ridden function with the object

  // To make the e1 call getname of the object we should declare getname as virtual in entity - this helps to call the base class function


  return 0;
}
