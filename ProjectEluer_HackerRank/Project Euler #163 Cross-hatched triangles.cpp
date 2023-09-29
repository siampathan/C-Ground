
#include <iostream>
#include <vector>
#include <cmath>

const double Epsilon = 0.0000001;

struct Point
{

  Point(double x_, double y_)
  : x(x_), y(y_)
  {}

  bool operator==(const Point& other) const
  {
    return fabs(x - other.x) < Epsilon &&
           fabs(y - other.y) < Epsilon; 
  }

  double x;
  double y;
};


const double Height  = sqrt(3.0) / 2;
Point A(0,   0);
Point B(1,   0);
Point C(0.5, Height);
const Point NoIntersection(9999999, 9999999);
class Line
{
public:
  Line(const Point& from, const Point& to)
  {
    a = from.y - to.y;
    b = to.x - from.x;
    c = to.x*from.y - from.x*to.y;
  }
  Point intersect(const Line& other) const
  {
    auto determinant = a * other.b - other.a * b;
    if (fabs(determinant) < Epsilon)
      return NoIntersection;

    auto x = (c * other.b - other.c * b) / determinant;
    auto y = (a * other.c - other.a * c) / determinant;
    return Point(x, y);
  }

  double determinant(const Point& p) const
  {
    return a * p.x + b * p.y - c;
  }

private:
  double a;
  double b;
  double c;
};

bool insideHull(const Point& p)
{
  
  Line bottom  (A, B);
  Line topRight(B, C);
  Line topLeft (C, A);
  if (bottom  .determinant(p) < -Epsilon) return false;
  if (topRight.determinant(p) < -Epsilon) return false;
  if (topLeft .determinant(p) < -Epsilon) return false;

  return true;
}
bool isValidTriangle(const Line& a, const Line& b, const Line& c)
{
  Point ab = a.intersect(b);
  Point bc = b.intersect(c);
  Point ac = a.intersect(c);

  if (ab == NoIntersection) 
    return false;
  if (bc == NoIntersection)
    return false;
  if (ac == NoIntersection)
    return false;
  if (ab == bc)
    return false;
  return insideHull(ab) && insideHull(bc) && insideHull(ac);
}

int main()
{
  unsigned int size = 36;
  std::cin >> size;

  
  Point AB((A.x+B.x)/2, (A.y+B.y)/2);
  Point AC((A.x+C.x)/2, (A.y+C.y)/2);
  Point BC((B.x+C.x)/2, (B.y+C.y)/2);

  std::vector<Line> lines;
  for (unsigned int i = 0; i < size; i++)
    lines.push_back(Line(Point(A.x, i * Height), Point(B.x, i * Height)));
  for (unsigned int i = 0; i < size; i++)
  {
    lines.push_back(Line(Point(i, A.y), Point(BC.x + i, BC.y)));
    if (i > 0)
      lines.push_back(Line(Point(-(double)i, A.y), Point(BC.x - (double)i, BC.y)));
  }
  for (unsigned int i = 0; i < size; i++)
    lines.push_back(Line(Point(i, A.y), Point(C.x + i, C.y)));
  for (unsigned int i = 0; i < size; i++)
    lines.push_back(Line(Point(i+1, B.y), Point(C.x + i, C.y)));
  for (unsigned int i = 0; i < 2*size-1; i++)
    lines.push_back(Line(Point(i+1, B.y), Point(AC.x + i, AC.y)));
  for (unsigned int i = 1; i < 2*size; i++)
    lines.push_back(Line(Point(i * C.x, 0), Point(i * C.x, Height)));


  A.x *= size; A.y *= size;
  B.x *= size; B.y *= size;
  C.x *= size; C.y *= size;

  unsigned int count = 0;

  for (unsigned int i = 0; i < lines.size(); i++)
    for (unsigned int j = i + 1; j < lines.size(); j++)
    {
      
      auto first = lines[i].intersect(lines[j]);
      if (first == NoIntersection || !insideHull(first))
        continue;
      for (unsigned int k = j + 1; k < lines.size(); k++)
      
        if (isValidTriangle(lines[i], lines[j], lines[k]))
          count++;
    }

  std::cout << count << std::endl;
}