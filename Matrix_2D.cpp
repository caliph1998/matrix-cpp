#include <cmath>
#include <iostream>
#include <vector>
#include "Matrix_2D.h"

int main () {
  Matrix_2D<int> m(3,4), n(4,3);
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
   m = v;
   n = v;
  Matrix_2D<int> l = m.dot(n);
  v = {70, 80, 90, 158, 184, 210, 246, 288, 330};
  Matrix_2D<int> test_l(3,3);
  test_l = v;
  std::cout<< l[2][1];
  return 0;
}