#include "Fraction.h"
#include <iostream>

using namespace std;

Fraction ::Fraction():Numerator(0),Denominator(1){}

Fraction :: Fraction(int x,int y):Numerator(x),Denominator(y){}

void Fraction :: input(){
    cin >> Numerator >> Denominator;
}

void Fraction :: output(){
    reduce();
    cout <<Numerator<<"/"<<Denominator;
}

int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

void Fraction :: reduce(){
    int d=gcd(abs(Denominator),abs(Numerator));
    if(Denominator<0){
        Denominator=-Denominator;
        Numerator=-Numerator;
    }
    Denominator/=d;
    Numerator/=d;
}

Fraction Fraction :: operator+(const Fraction& other){
    return Fraction(Numerator*other.Denominator+other.Numerator*Denominator,Denominator*other.Denominator);
}

Fraction Fraction :: operator-(const Fraction& other){
    return Fraction(Numerator*other.Denominator-other.Numerator*Denominator,Denominator*other.Denominator);
}

Fraction Fraction :: operator*(const Fraction& other){
    return Fraction(Numerator*other.Numerator,Denominator*other.Denominator);
}

Fraction Fraction :: operator/(const Fraction& other){
    if(other.Numerator==0){
        throw std::exception();
    }
    return Fraction(Numerator*other.Denominator,Denominator*other.Numerator);
}

int Fraction :: compare(Fraction other){
    Fraction res = *this-other;
    res.reduce();
    if(res.Numerator==0) return 0;
    else if(res.Numerator>0) return 1;
    else return -1;
}

bool Fraction :: isNegative() {
    reduce();
    return Numerator<0;
}

bool Fraction :: isPositive(){
    reduce();
    return Numerator>0;
}

bool Fraction :: isZero(){
    return Numerator==0;
}

