#include <iostream>
#include "polygon.h"

// TODO(student): define the methods

std::string Polygon::to_string() const {
    std::string s;
    bool first = true;
    s += "{";
    for (const Point& p : points) {
      if (!first) s += ", ";
      s += "(";
      s += std::to_string(p.first);
      s += ", ";
      s += std::to_string(p.second);
      s += ")";
      first = false;
    }
    s += "}";
    return s;
  }

std::ostream& operator<<(std::ostream& os, const Polygon& p) {
  return os << p.to_string();
}
