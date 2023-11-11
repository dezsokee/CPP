#include "Polynomial.h"
#include <cmath>

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree;
    this->coefficients = new double[degree + 1];

    for (int i = 0; i < degree + 1; ++i) {
        this->coefficients[i] = coefficients[i];
    }
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

Polynomial Polynomial::derivative() const {
    Polynomial result(this->capacity - 1, this->coefficients);

    for (int i = 0; i < this->capacity; ++i) {
        result.coefficients[i] = this->coefficients[i + 1] * (i + 1);
    }

    return result;
}

double Polynomial::operator[](int index) const {
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {

    if (a.capacity > b.capacity) {
        Polynomial result(a.capacity, a.coefficients);

        for (int i = 0; i < result.capacity + 1; ++i) {
            result.coefficients[i] = a.coefficients[i] - b.coefficients[i];
        }

        return result;
    } else {
        Polynomial result(b.capacity, b.coefficients);

        for (int i = 0; i < result.capacity + 1; ++i) {
            result.coefficients[i] = a.coefficients[i] - b.coefficients[i];
        }

        return result;
    }
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {

        if (a.capacity > b.capacity) {
            Polynomial result(a.capacity, a.coefficients);

            for (int i = 0; i < result.capacity + 1; ++i) {
                result.coefficients[i] = a.coefficients[i] + b.coefficients[i];
            }

            return result;
        } else {
            Polynomial result(b.capacity, b.coefficients);

            for (int i = 0; i < result.capacity + 1; ++i) {
                result.coefficients[i] = a.coefficients[i] + b.coefficients[i];
            }

            return result;
        }
}

Polynomial operator-(const Polynomial &a) {
    Polynomial result(a.capacity, a.coefficients);

    for (int i = 0; i < result.capacity + 1; ++i) {
        result.coefficients[i] = -a.coefficients[i];
    }

    return result;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    Polynomial result(a.capacity + b.capacity, a.coefficients);

    for (int i = 0; i < a.capacity + 1; ++i) {
        result.coefficients[i] = a.coefficients[i] * b.coefficients[i];
    }

    return result;
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    for (int i = 0; i < what.capacity + 1; ++i) {
        out << what.coefficients[i] << "x^" << i << " ";
    }

    return out;
}


