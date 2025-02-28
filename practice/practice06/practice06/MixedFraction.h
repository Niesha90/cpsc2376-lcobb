#pragma once
#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H

#include "Fraction.h"
#include <iostream>

class MixedFraction : public Fraction {
private:
    int whole;
public:
    
    MixedFraction(int whole, int n, int d);

    
    MixedFraction(const Fraction& fraction);

    
    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mf);
};

#endif 