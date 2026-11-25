#include "Mang_phan_so.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

Fraction :: Fraction(long long num,long long denom):num(num),denom(denom){
    simplify();
}

long long Fraction :: gcd(long long a,long long b){
    a=abs(a);
    b=abs(b);
    while(b!=0){
        long long temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}



void Fraction :: simplify(){
    long long d=gcd(num,denom);
    if(denom<0){
        denom=-denom;
        num=-num;
    }
    num/=d;
    denom/=d;

}

Fraction Fraction :: operator +(const Fraction& other) const {
    return Fraction(num*other.denom+other.num*denom,denom*other.denom);
}

Fraction Fraction :: operator -(const Fraction& other) const {
    return Fraction(num*other.denom-other.num*denom,denom*other.denom);
}


bool Fraction :: operator < (const Fraction& other) const{
    return (*this-other).num<0;
}

void Fraction :: output () const {
    cout <<num<<'/'<<denom<<'\n';
}

ostream& operator << (ostream& os ,const Fraction& frac){
    os<<frac.num<<'/'<<frac.denom;
    return os;
}

void FractionArray :: loadFromFile(const string&filename){
    ifstream fin(filename);
    if(!fin){
        cout <<"Khong the mo file\n";
    }
    long long a,b;
    while (fin >> a >> b){
        Fraction temp(a,b);
        v.push_back(temp);
    }
    fin.close();
}

Fraction FractionArray::sum() const {
    Fraction res;
    for(int i=0;i<(int)v.size();i++){
        res=res+v[i];
        res.simplify();
    }
    return res;
}

void FractionArray :: sortArray(){
    sort(v.begin(),v.end());
}

Fraction FractionArray::max() const {
    Fraction res(-1e9-7,1);
    for(auto x:v){
        if(res<x){
            res=x;
        }
    }
    return res;
}

Fraction FractionArray::min() const {
    Fraction res(1e9+7,1);
    for(auto x:v){
        if(x<res){
            res=x;
        }
    }
    return res;
}

void FractionArray :: output() const {
    for(auto x : v){
        x.output();
    }
}


