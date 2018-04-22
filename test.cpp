#include <iostream>
#include <string>
#include <memory>
#include <vector>
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
void pointer_access(vector<Entity*>::iterator it_s,vector<Entity*>::iterator it_e){
  for (it_s; it_s!=it_e;it_s++) {
    (*it_s)->print_();
  }
}

void pointer_access_shared(vector<shared_ptr<Entity>>::iterator it_s, vector<shared_ptr<Entity>>::iterator it_e){
  for (it_s; it_s!=it_e;it_s++) {
    (*it_s)->print_();
  }
}

int main() {
  /*
  //Vector of pointers
  vector<Entity*> v;
  Entity* e =  new Entity();
  Entity* f =  new Entity();
  v.push_back(e);
  v.push_back(f);
  vector<Entity*>::iterator it = v.begin();
  pointer_access(v.begin(),v.end());
  (*it)->print_();
  */

  //vector of shared_ptr
  vector<shared_ptr<Entity>> v_shr;
  shared_ptr<Entity> shared_entity = make_shared<Entity>();
  v_shr.push_back(shared_entity);
  v_shr.push_back(make_shared<Entity>());
  vector<shared_ptr<Entity>>::iterator it_sh = v_shr.begin();
  pointer_access_shared(it_sh, v_shr.end());
  (*it_sh)->print_();

  return 0;
}
