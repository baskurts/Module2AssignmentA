#include "./headers/RationalNumber.h"
#include <iostream>

int main() {

    RationalNumber r1;
    std::cout << "Rational Number 1 Fraction Form: ";
    r1.printRationalNumber();

    std::cout << "Rational Number 1 Quotient Form: ";
    r1.printRationalNumber(2);

    
    r1.setNumerator(4);
    r1.setDenominator(6);
    std::cout << "Rational Number 1 Fraction Form: ";
    r1.printRationalNumber();

    std::cout << "Rational Number 1 Quotient Form: ";
    r1.printRationalNumber(2);

    
    RationalNumber r2(2, 4);
    std::cout << "Rational Number 2 Fraction Form: ";
    r2.printRationalNumber();

    std::cout << "Rational Number 1 Quotient Form: ";
    r2.printRationalNumber(2);

    
    int num, denom;
    r2.getNumerator(num);
    r2.getDenominator(denom);
    std::cout << "Rational Number 2 Numerator: " << num << " \nRational Number 2 Denominator: " << denom << std::endl;

    
    std::cout << "Rational Number 1 equals Rational Number 2 ?" << (r1.equalRationalNumber(r2) ? "True" : "False") << std::endl;

    return 0;
}
