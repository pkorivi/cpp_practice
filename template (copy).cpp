#include <vector>
#include <iostream>
using namespace std;


#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class Shape {
protected:
  double bounding_box_width;
  double bounding_box_height;
public:
  Shape(double width, double height): bounding_box_width(width), bounding_box_height(height){}
  virtual double getShapeArea() {
    return getBoundingBoxArea();
  }
  double getBoundingBoxArea() {
    std::cout << bounding_box_width<<" " << bounding_box_height<<'\n';
    return bounding_box_width * bounding_box_height;
  }
};

class Circle: public Shape {
private:
  double radius;
public:
  Circle(double radius): Shape(2*radius, 2*radius), radius(radius) {}
  double getShapeArea(){
    std::cout << "cicle" << '\n';
    return radius * radius * M_PI;
  };
};

class Rectangle: public Shape {
public:
  Rectangle(double width, double height): Shape(width, height){}
};

// creates shapes and adds them to the passed vector
void createShapes(vector<shared_ptr<Shape>> shapes) {
  shapes.push_back( make_shared<Circle>(5) );
  shapes.push_back( make_shared<Rectangle>(10, 20) );
}

// accepts two iterators and computes the sum of all areas of all shapes in the range.
template< typename IterT>
double accumulateShapeAreas( IterT start_it, IterT end_it) {
  //TODO
  double sum=0;

    //std::cout << *start_it << '\n';
  for(start_it; start_it!=end_it;start_it++){
    std::cout << " f" << '\n';
    //sum += (*(*it).get()).getShapeArea();
  }

  return 1;
}
//without template
double accumulateShapeAreas2( std::vector<Shape>::iterator start_it, std::vector<Shape>::iterator end_it) {
  //TODO
  double sum=0;

    //std::cout << *start_it << '\n';
  for(start_it; start_it!=end_it;start_it++){
    std::cout << " f" << '\n';
    //sum += (*(*it).get()).getShapeArea();
  }

  return 1;
}

int main() {
  std::vector<shared_ptr<Shape>> shapes;
  createShapes(shapes);
  std::cout << accumulateShapeAreas(shapes.begin(),shapes.end()) << '\n';
  return 0;
}
