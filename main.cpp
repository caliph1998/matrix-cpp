#include <cmath>
#include <iostream>
#include <vector>
#include "Matrix_2D.h"
typedef Matrix_2D<int> mat;
void testTranspose() {
    
}

int main () {

  mat m(3,4), n(4,3);
//   std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//    m = v;
//    n = v;
m.random();
n.random(time(NULL));
  mat l = m.dot(n);
  m.show();
  std::cout<<"\n";
  n.show();
  
  std::cout<<"\n";
  l.show();
  return 0;
}