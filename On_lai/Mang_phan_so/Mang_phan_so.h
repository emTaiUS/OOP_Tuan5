#ifndef MANG_PHAN_SO_H
#define MANG_PHAN_SO_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class Fraction{
    private:
        long long num,denom;
        long long gcd(long long a,long long b);
        Fraction operator -(const Fraction& other) const ;
    public:
        Fraction(long long num=0,long long denom=1);
        void simplify();
        Fraction operator +(const Fraction& other) const ;
        bool operator < (const Fraction& other) const ;
        void output() const ;
        friend ostream& operator<<(ostream& os ,const Fraction& frac);
};

class FractionArray {
    private:
        vector<Fraction> v;
    public: 
        void loadFromFile (const string& filename);
        Fraction sum() const ;
        Fraction max() const ;
        Fraction min() const ;
        void sortArray();
        void output() const;

};


#endif