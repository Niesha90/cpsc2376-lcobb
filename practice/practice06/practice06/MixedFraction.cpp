#include "MixedFraction.h"
#include <iostream>

MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(whole* d + n, d) {}

MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {}

std::ostream& operator<<(std::ostream& os, const MixedFraction& mf) {
    int whole = mf.getNumerator() / mf.getDenominator();
    int remainder = mf.getNumerator() % mf.getDenominator();

    if (remainder == 0) {
        os << whole;
    }
    else if (whole == 0) {
        os << remainder << "/" << mf.getDenominator();
    }
    else {
        os << whole << " " << remainder << "/" << mf.getDenominator();
    }

    return os;
}