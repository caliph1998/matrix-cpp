#include <cmath>
#include <iostream>
#include <vector>


template<class T> 
class Matrix_2D {
  public:
    int row;
    int col;

    using D2 = std::vector<std::vector<T>>;
    using size_type = typename std::vector<T>::size_type;
    D2 elem;
    Matrix_2D (int r, int c) : row(r), col(c), elem(r, std::vector<T>(c, 0)) {}
    void transpose ();
    std::vector<T>& operator[](size_type i) {
      if (i > elem.size() - 1) throw std::invalid_argument("out of range");
      return elem[i];
    }
    Matrix_2D<T> dot(Matrix_2D<T>& M);
    void operator=(std::vector<T>& v);
    bool operator==(Matrix_2D<T> & M);
};

template<class T>
void  Matrix_2D<T>::transpose () {
  D2 t_elem (col, std::vector<T>(row, 0));
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      t_elem[j][i] = elem[i][j];
    }
  }
  elem = std::move(t_elem);
  std::swap(row, col);
}

template<class T>
Matrix_2D<T> Matrix_2D<T>::dot(Matrix_2D<T>& M) {
  if (col != M.row) throw std::invalid_argument("inappropriate dimensions for dot product");
  Matrix_2D<T> result(row, M.col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < M.col; j++) {
      for (int k = 0; k < col; k++) {
        result[i][j] += (*this)[i][k] * M[k][j];
      }
    }
  }
  return result;
}

template<class T>
void Matrix_2D<T>::operator=(std::vector<T>& v) {
  if (v.size() != row * col) throw std::invalid_argument("v.size() must equal row * col");

  typename std::vector<T>::iterator it= v.begin();

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      elem[i][j] = *it;
      it++;
    }
  }
}

template<class T>
bool Matrix_2D<T>::operator==(Matrix_2D& M) {
  if (row != M.row || col != M.col) return false;

  return elem == M.elem;
}