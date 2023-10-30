#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Matrix {
public:
    // Default constructor
    Matrix(int mRows = 10, int mCols = 10);

    // Copy constructor
    Matrix(const Matrix &what);

    // Move constructor
    Matrix(Matrix &&what);

    // Destructor
    ~Matrix();

    //fills the matrix with identical elements
    void fillMatrix(double value = 0);

    //fills the matrix with random real numbers in the range [a, b)
    void randomMatrix(int a, int b); //fills

    //prints the matrix
    void printMatrix(ostream &os = cout) const;

    //checks whether this matrix is a square one
    bool isSquare() const { return this->mRows == this->mCols; }

    int getRows() const { return this->mRows; }

    int getCols() const { return this->mCols; }

    friend Matrix operator+(const Matrix &x, const Matrix &y);

    friend Matrix operator*(const Matrix &x, const Matrix &y);

    friend istream &operator>>(istream &is, Matrix &mat);

    friend ostream &operator<<(ostream &os, const Matrix &mat);

    double* operator[] (int index);

    double* operator[] (int index) const;

    Matrix & operator=(const Matrix& mat);

    Matrix & operator=(Matrix&& mat);

private:
    //Data
    double **mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};

#endif /* MATRIX_H */