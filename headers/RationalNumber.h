#include "GreatestCommonFactor.h"
#include <iostream>
#include <stdexcept>

// the RationalNumber class represents a rational number.
// a rational number is any number that can be expressed as 
// a fraction, where both the numerator and the denominator 
// are integers, and the denominator is not equal to zero.
// a rational number may be expressed as a fraction or a
// quotient.

class RationalNumber : public GreatestCommonFactor {
private:
    int numerator;
    int denominator;

    void reduce() {
        int factor = gcf(numerator, denominator);
        numerator /= factor;
        denominator /= factor;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

public:
    RationalNumber() : numerator(1), denominator(1) {}

    RationalNumber(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    int gcf(int a, int b) const override {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void setNumerator(int num) {
        numerator = num;
        reduce();
    }

    void getNumerator(int& num) const {
        num = numerator;
    }

    void setDenominator(int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        denominator = denom;
        reduce();
    }

    void getDenominator(int& denom) const {
        denom = denominator;
    }

    void printRationalNumber() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    void printRationalNumber(int precision) const {
        std::cout.precision(precision);
        std::cout << std::fixed << static_cast<double>(numerator) / denominator << std::endl;
    }

    bool equalRationalNumber(const RationalNumber& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
};
