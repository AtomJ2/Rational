#include "Rational.h"

Rational::Rational() {
    num = 0;
    denom = 1;
}

Rational::Rational(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Argument must not be zero");
    }

    num = numerator;
    denom = denominator;
}

int Rational::Numerator() const {
    return num;
}

int Rational::Denominator() const {
    return denom;
}

Rational operator+(const Rational& a, const Rational& b) {
    return Rational(a.num * b.denom + b.num * a.denom, a.denom * b.denom);
}

Rational operator*(const Rational& a, const Rational& b) {
    return Rational(a.num * b.num, a.denom * b.denom);
}

Rational operator/(const Rational& a, const Rational& b) {
    if (b.num == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return Rational(a.num * b.denom, a.denom * b.num);
}

Rational operator-(const Rational& a, const Rational& b) {
    return Rational(a.num * b.denom - b.num * a.denom, a.denom * b.denom);
}

bool operator==(const Rational& a, const Rational& b) {
    return (a.num == b.num) && (a.denom == b.denom);
}

std::ostream& operator<<(std::ostream& out, const Rational& a) {
    out << a.num << "/" << a.denom;
    return out;
}

std::istream& operator>>(std::istream& in, Rational& a) {
    if (!(in >> a.num)) {
        return in;
    }
    if (in.peek() != '/') {
        return in;
    }
    in.ignore(1);
    if (!(in >> a.denom)) {
        return in;
    }
    return in;
}