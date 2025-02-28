#pragma once
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <stdexcept>
#include <numeric>

class Fraction {
private:
    int num, den;
    void simplify();
public:
    Fraction(int n = 0, int d = 1);
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int n);
    void setDenominator(int d);
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};

#endif 