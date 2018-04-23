#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;
class Entity{
public:
  int x,y;
    void move_(int xa, int ya){
      x+=xa;
      y+=ya;
    }
};

//here player is superset of entity, it will always have what entity has and probably more
class player : public Entity{
public:
  const char* name;
  void player_name(){std::cout << name << '\n';}
};

int main(){
  player p1;
  p1.x =4;
  p1.y =3;
  p1.move_(2,4);
  p1.name = "world dish";
  std::cout << p1.x << " " << p1.y << '\n';
  p1.player_name();
  return 0;
}
