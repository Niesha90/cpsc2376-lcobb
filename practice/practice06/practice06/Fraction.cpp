#include "Fraction.h"
#include <stdexcept>

// The Simple Euclidean algorithm 
int myGCD(int a, int b) {
    if (b == 0) return a;
    return myGCD(b, a % b);
}

Fraction::Fraction(int n, int d) : num(n), den(d) {
    simplify();
}

void Fraction::simplify() {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    int gcd = myGCD(num, den);
    num /= gcd;
    den /= gcd;
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}

void Fraction::setNumerator(int n) {
    num = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    den = d;
    simplify();
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int newNum = lhs.num * rhs.den + rhs.num * lhs.den;
    int newDen = lhs.den * rhs.den;
    return Fraction(newNum, newDen);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int newNum = lhs.num * rhs.den - rhs.num * lhs.den;
    int newDen = lhs.den * rhs.den;
    return Fraction(newNum, newDen);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.num, lhs.den * rhs.den);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return Fraction(lhs.num * rhs.den, lhs.den * rhs.num);
}

#include <iostream>
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.num << "/" << f.den;
    return os;
}