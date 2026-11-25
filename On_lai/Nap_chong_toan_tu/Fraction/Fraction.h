#ifndef FRACTION_H
#define FRACTION_H

using namespace std;

class Fraction{
    private:
        int Numerator ,Denominator;
    public:
        Fraction();
        Fraction(int x,int y);
        void input();
        void output();
        Fraction operator+(const Fraction& other);
        Fraction operator-(const Fraction& other);
        Fraction operator*(const Fraction& other);
        Fraction operator/(const Fraction& other);
        void reduce();
        int compare(Fraction other);
        bool isPositive();
        bool isNegative();
        bool isZero();

};





#endif