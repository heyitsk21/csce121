#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <tuple>
#include <string>
#include <cmath>

using Point = std::pair<int,int>;
using Collection = std::vector<Point>;

class Polygon {
  Collection points;

 public:
  Polygon() : points{} {}
  virtual ~Polygon() {}
  virtual double area() const { /* shoelace formula */ return 0; }
  virtual double perimeter() const { /* sum of side lengths */ return 0; }
  std::string to_string() const; // defined in polygon.cpp;
};

class Triangle : public Polygon {

 public:
  Triangle() {}
  Triangle(const Point&, const Point&, const Point&) {}
};

class Rectangle : public Polygon {

 public:
  Rectangle() {}
  Rectangle(const Point&, const Point&) {}

};

class Square : public Rectangle {

 public:
  Square() {}
  Square(const Point&, unsigned) {}
};

/*
+-----------------------------------------+                     
| Polygon                                 |                     
+-----------------------------------------+  "composition of"   +----------------+
| - points : Collection of Points         | -----------------<> | Point          |
+-----------------------------------------+                     +----------------+
| + Polygon()                             |                     | + first : int  |
| + ~Polygon() - virtual                  |                     | + second : int |
| + area() : double - virtual, const      |                     +----------------+
| + perimeter() : double - virtual, const |
| + to_string() : string - const          |
+-----------------------------------------+
        ^                              ^
        | "is-a"                       | "is-a"
        |                              |
+-------+-----------------------+   +--+-----------------------+
| Triangle                      |   | Rectangle                |
+-------------------------------+   +--------------------------+
| + Triangle()                  |   | + Rectangle()            |
| + Triangle(Point,Point,Point) |   | + Rectangle(Point,Point) |
+-------------------------------+   +--------------------------+
                                       ^
                                       | "is-a"
                                       |
                   +-------------------+------+
                   | Square                   |
                   +--------------------------+
                   | + Square()               |
                   | + Square(Point,unsigned) |
                   +--------------------------+

Polygon() makes a polygon with no points (empty polygon, null polygon)
area() computes the area of the polygon (hint: shoelace formula)
perimeter() computes the perimeter of the polygon (sum of side lengths)
to_string() represents the polygon as a string listing the points, has already been implemented for you in polygon.cpp

Triangle() - makes a triangle with points at (1,0), (0,1), and (0,0).
Triangle(Point,Point,Point) - makes a triangle (polygon with 3 points).

Rectangle() - makes a rectangle with top-left point at (0,1) and bottom-left point at (1,0).
Rectangle(Point,Point) - makes a rectangle (polygon with 4 points, parallel sides, 90 degree angles) using top-left and bottom-right points.

Square() makes a square with top-left point at (0,1) and side-length 1
Square(Point,unsigned) - makes a square (rectangle with equal side lengths) using top-left point and side-length.

Note: you can add other methods

Shoelace formula:
Given points {(x1,y1), (x2,y2), ... ,(xn,yn)} in anti-clockwise order that define a simple polygon (no intersecting edges)
The area A of the polygon can be computed as 

2*A = x1*y2 - y1*x2 + x2*y3 - y2*x3 + ... + xn*y1 - yn*x1

Visually:

+ x1 y1 -
    X
+ x2 y2 -
    X
+ x3 y3 -
    X
  .....
    X
+ xn yn -
    X
  x1 y1

+x1*y2 -y1*x2
+x2*y3 -y2*x3
...
+xn*y1 -yn*x1
-------------
= 2*A

*/

// TODO(student): define the classes


std::ostream& operator<<(std::ostream&, const Polygon&);

#endif