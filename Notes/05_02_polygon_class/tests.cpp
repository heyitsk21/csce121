#include <iostream>
#include "tests.h"
#include "polygon.h"

using std::cout, std::endl;

bool equals(double x, double y, double epsilon=1e-6) { return std::fabs(x - y) <= epsilon; }

template <typename T>
bool equals(const T& a, const T& b) { return a == b; }

bool polygon_perimeter_test(const Polygon& p, double expected, const std::string& name="polygon") {
    double actual = p.perimeter();
    if (! equals(actual, expected)) {
      cout << red << "[FAIL]"<< reset << " expected perimeter of "<<name<<" " << p << " to be " << expected << endl;
      cout << "       got " << actual << endl;
      return false;
    } else {
      cout << green << "[PASS]" << reset << " perimeter of "<<name<<" " << p << " is " << actual << endl;
      return true;
    }
}

bool polygon_area_test(const Polygon& p, double expected, const std::string& name) {
    double actual = p.area();
    if (! equals(actual, expected)) {
      cout << red << "[FAIL]"<< reset << " expected area of "<<name<<" " << p << " to be " << expected << endl;
      cout << "       got " << actual << endl;
      return false;
    } else {
      cout << green << "[PASS]" << reset << "    area   of "<<name<<" " << p << " is " << actual << endl;
      return true;
    }
}

PassFailCount test_triangle_perimeter() {
  unsigned pass_cnt = 0, fail_cnt = 0;

  std::vector<std::pair<Triangle,double>> testcases = {
  {{}, 3.414214},
  {{{11,12}, {1,3}, {12,0}}, 36.896973},
  {{{0,17}, {-8,11}, {-6,7}}, 26.134040},
  {{{14,3}, {4,12}, {8,-3}}, 37.463080},
  {{{11,3}, {4,4}, {17,-14}}, 47.302428},
  {{{3,-2}, {-6,-2}, {4,-14}}, 36.662094},
  {{{-3,9}, {-8,13}, {-16,3}}, 33.527194},
  {{{8,12}, {-5,14}, {-6,-4}}, 52.440994},
  {{{13,4}, {-5,4}, {7,-7}}, 46.808785},
  {{{5,-2}, {0,1}, {1,-11}}, 27.721404},
  };

  for (auto& tc : testcases) {
    polygon_perimeter_test(tc.first, tc.second, "triangle") ? pass_cnt++ : fail_cnt++;
  }

  return {pass_cnt, fail_cnt};
}

PassFailCount test_triangle_area() {
  unsigned pass_cnt = 0, fail_cnt = 0;

  std::vector<std::pair<Triangle,double>> testcases = {
  {{}, 0.5},
  {{{-8,3}, {-19,10}, {-9,-8}}, 64},
  {{{4,-2}, {-14,1}, {-13,-18}}, 169.5},
  {{{-2,13}, {-5,11}, {-14,3}}, 3},
  {{{5,4}, {-5,0}, {-8,-12}}, 54},
  {{{9,10}, {2,12}, {15,6}}, 8},
  {{{8,18}, {-3,15}, {-4,3}}, 64.5},
  {{{-1,12}, {-12,7}, {-12,-6}}, 71.5},
  {{{12,4}, {-4,4}, {-3,-4}}, 64},
  {{{-2,3}, {-10,4}, {2,-7}}, 38},
  };

  for (auto& tc : testcases) {
    polygon_area_test(tc.first, tc.second, "triangle") ? pass_cnt++ : fail_cnt++;
  }

  return {pass_cnt, fail_cnt};
}

PassFailCount test_rectangle_perimeter() {
  unsigned pass_cnt = 0, fail_cnt = 0;

  std::vector<std::pair<Rectangle,double>> testcases = {
  {{}, 4},
  {{{2,-3}, {10,-8}}, 26},
  {{{1,9}, {12,-1}}, 42},
  {{{-2,-2}, {4,-9}}, 26},
  {{{-15,1}, {-4,-13}}, 50},
  {{{-8,9}, {9,-3}}, 58},
  {{{-17,3}, {-3,-5}}, 44},
  {{{-11,6}, {7,-7}}, 62},
  {{{-19,3}, {-4,-6}}, 48},
  {{{0,-4}, {10,-12}}, 36},
  };

  for (auto& tc : testcases) {
    polygon_perimeter_test(tc.first, tc.second, "rectangle") ? pass_cnt++ : fail_cnt++;
  }

  return {pass_cnt, fail_cnt};
}

PassFailCount test_rectangle_area() {
  unsigned pass_cnt = 0, fail_cnt = 0;

  std::vector<std::pair<Rectangle,double>> testcases = {
  {{}, 1},
  {{{0,-6}, {10,-15}}, 90},
  {{{1,4}, {8,-8}}, 84},
  {{{-15,4}, {-2,-9}}, 169},
  {{{-11,3}, {3,-11}}, 196},
  {{{-12,3}, {1,-14}}, 221},
  {{{-4,11}, {11,1}}, 150},
  {{{-7,0}, {2,-7}}, 63},
  {{{0,14}, {6,0}}, 84},
  {{{5,-3}, {13,-13}}, 80},
  };

  for (auto& tc : testcases) {
    polygon_area_test(tc.first, tc.second, "rectangle") ? pass_cnt++ : fail_cnt++;
  }

  return {pass_cnt, fail_cnt};
}

PassFailCount test_square_perimeter() {
  unsigned pass_cnt = 0, fail_cnt = 0;

  std::vector<std::pair<Square,double>> testcases = {
  {{}, 4},
  {{{5,-6}, 2}, 8},
  {{{-9,2}, 7}, 28},
  {{{-2,-6}, 2}, 8},
  {{{-1,-7}, 3}, 12},
  {{{5,4}, 10}, 40},
  {{{-2,-4}, 10}, 40},
  {{{-2,8}, 7}, 28},
  {{{2,-8}, 6}, 24},
  {{{-5,-5}, 8}, 32},
  };

  for (auto& tc : testcases) {
    polygon_perimeter_test(tc.first, tc.second, "square") ? pass_cnt++ : fail_cnt++;
  }

  return {pass_cnt, fail_cnt};
}

PassFailCount test_square_area() {
  unsigned pass_cnt = 0, fail_cnt = 0;

  std::vector<std::pair<Square,double>> testcases = {
  {{}, 1},
  {{{-4,-9}, 2}, 4},
  {{{3,-10}, 3}, 9},
  {{{-5,-6}, 4}, 16},
  {{{3,-6}, 5}, 25},
  {{{0,-1}, 6}, 36},
  {{{9,9}, 7}, 49},
  {{{5,-9}, 8}, 64},
  {{{8,8}, 9}, 81},
  {{{6,-3}, 10}, 100},
  };

  for (auto& tc : testcases) {
    polygon_area_test(tc.first, tc.second, "square") ? pass_cnt++ : fail_cnt++;
  }

  return {pass_cnt, fail_cnt};
}

#define test_polygon(X) PassFailCount test_##X() {\
  unsigned pass_cnt = 0, fail_cnt = 0;\
\
  test(X##_perimeter);\
  test(X##_area);\
\
  return {pass_cnt, fail_cnt};\
}

test_polygon(triangle)
test_polygon(rectangle)
test_polygon(square)
