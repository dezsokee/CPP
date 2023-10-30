#include <random>
#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) : mRows(mRows), mCols(mCols) {
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;

    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }

    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;

    this->mElements = what.mElements;

    what.mRows = 0;
    what.mCols = 0;

    what.mElements = nullptr;
}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        delete[] mElements[i];
    }

    delete[] mElements;
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << this->mElements[i][j] << " ";
        }
        os << endl;
    }
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(a, b);

    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = dist(mt);
        }
    }
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if(x.mRows != y.mRows || x.mCols != y.mCols || x.mRows <= 0 || x.mCols <= 0 || y.mRows <= 0 || y.mCols <= 0) {
        throw out_of_range("Can't add the matrixes!");
    } else {
        Matrix temp(x.mRows, x.mCols);
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < x.mCols; ++j) {
                temp.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
            }
        }

        return temp;
    }
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if(x.mCols != y.mRows || x.mRows <= 0 || x.mCols <= 0 || y.mRows <= 0 || y.mCols <= 0) {
        throw out_of_range("Can't multiply the matrices!");
    } else {
        Matrix temp(x.mRows, y.mCols);

        temp.fillMatrix(0);

        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < y.mCols; ++j) {
                for (int k = 0; k < x.mCols; ++k) {
                    temp.mElements[i][j] += (x.mElements[i][k] * y.mElements[k][j]);
                }
            }
        }

        return temp;
    }
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is>>mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            cout<<mat.mElements[i][j]<<" ";
        }
        cout<<endl;
    }

    return os;
}

double *Matrix::operator[](int index) {
    return this->mElements[index];
}

double *Matrix::operator[](int index) const {
    return this->mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    this->mRows = mat.mRows;
    this->mCols = mat.mCols;

    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = mat.mElements[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    this->mElements = mat.mElements;

    mat.mRows = 0;
    mat.mCols = 0;
    mat.mElements = nullptr;

    return *this;
}




