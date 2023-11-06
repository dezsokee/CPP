#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree;
    this->coefficients = new double[degree + 1];
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double[that.capacity + 1];

    for (int i = 0; i < that.capacity + 1; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity;
    this->coefficients = that.coefficients;

    that.capacity = 0;
    that.coefficients = nullptr;
}

Polynomial::~Polynomial() {
    delete[] this->coefficients;
}

int Polynomial::degree() const {
    return this->capacity;
}

double Polynomial::evaluate(double x) const {
    double result = 0;

    for (int i = 0; i < this->capacity + 1; ++i) {
        result += this->coefficients[i] * pow(x, i);
    }

    return result;
}


