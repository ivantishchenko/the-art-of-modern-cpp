#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix {
public:
    Matrix() : num_rows_(0), num_cols_(0) {}
    Matrix(int rows, int cols) {
        Reset(rows, cols);
    }
    void Reset(int new_rows, int new_cols) {
        if(new_rows < 0 || new_cols < 0) throw out_of_range("Negative dims");
        if(new_rows == 0 || new_cols == 0) new_cols = new_rows = 0;

        num_rows_ = new_rows;
        num_cols_ = new_cols;
        values_.assign(num_rows_, vector<int>(num_cols_));
    }
    int At(int i, int j) const {
        CheckIdx(i, j);
        return values_[i][j];
    }
    int& At(int i, int j) {
        CheckIdx(i, j);
        return values_[i][j];
    }
    int GetNumRows() const{ 
        return num_rows_;
    }
    int GetNumColumns() const {
        return num_cols_;
    }
private:
    void CheckIdx(int rows, int cols) const {
        if(rows >= num_rows_ || cols >= num_cols_ || rows < 0 || cols < 0) {
            throw out_of_range("Out of bounds");
        }
    }
    int num_rows_;
    int num_cols_;
    vector<vector<int>> values_;
};

istream& operator>>(istream& stream, Matrix& matrix) {
    int rows, cols;
    stream >> rows >> cols;
    matrix.Reset(rows, cols);
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            stream >> matrix.At(i, j);
        }
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Matrix& matrix) {
    stream << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << endl;
    for(int i = 0; i < matrix.GetNumRows(); ++i) {
        for(int j = 0; j < matrix.GetNumColumns(); ++j) {
            stream << matrix.At(i, j) << " ";
        }
        stream << endl;
    }
    return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    if(rhs.GetNumRows() != lhs.GetNumRows() || rhs.GetNumColumns() != lhs.GetNumColumns()) {
        return false;
    }
    for(int i = 0; i < lhs.GetNumRows(); ++i) {
        for(int j = 0; j < lhs.GetNumColumns(); ++j) {
            if(lhs.At(i, j) != rhs.At(i, j)) {
                return false;
            }
        }
    }
    return true;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if(lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()) {
        throw invalid_argument("Dims do not match");
    }
    Matrix res(lhs.GetNumRows(), lhs.GetNumColumns());
    for(int i = 0; i < lhs.GetNumRows(); ++i) {
        for(int j = 0; j < lhs.GetNumColumns(); ++j) {
            res.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return res;
}

int main() {
  Matrix one;
  Matrix two;

  ifstream input("input.txt");
  ofstream output("output.txt");

  input >> one >> two;
  output << one + two << endl;
     
  return 0;
}
