#include "Da_thuc.h"
#include <iostream>

using namespace std;

DaThuc :: DaThuc():n(0){
    for(int i=0;i<=100;i++){
        a[i]=0;
    }
}

DaThuc :: DaThuc(int n , const int a[]):n(n){
    for(int i=0;i<=100;i++){
        if(i<=n){
            this->a[i]=a[i];
        }
        else this->a[i]=0;
    }
}

int DaThuc :: bac() const {
    int res=0;
    bool check=1;
    for (int i=0;i<=n;i++){
        if(a[i]!=0){
            res=i;
            check=0;
        }
    }
    if(check) return -1;
    return res;
}

int DaThuc :: operator[](int i) const{
    if(0<=i&&i<=n) return a[i];
    return 0;
}

DaThuc DaThuc::operator+ (const DaThuc& b) const {
    DaThuc res(*this);
    for(int i=0;i<=max(n,b.n);i++){
        res.a[i]+=b[i];
    }
    res.n=max(n,b.n);
    return res;
}

DaThuc DaThuc:: operator- (const DaThuc& b) const {
    DaThuc res(*this);
    for(int i=0;i<=max(n,b.n);i++){
        res.a[i]-=b[i];
    }
    res.n=max(n,b.n);

    return res;
}

long long  DaThuc :: giaTri(int x) const {
        long long res=0;
        for(int i=n;i>=0;i--){
            res=res*x+a[i];
        }
        return res;
}

DaThuc DaThuc :: operator* (const DaThuc& b) const {
    DaThuc res;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=b.n;j++){
            res.a[i+j]+=a[i]*b[j];
        }
    }
    res.n=n+b.n;
    return res;
}

std::ostream& operator << (std::ostream& os ,const DaThuc& p){
    bool check_first=0;
    for(int i=p.n;i>=0;i--){
        if(p[i]==0) continue;
        if(!check_first){
            if(i==1){
                if(p[i]==-1){
                    os<<"-";
                }
                else if(p[i]!=1){
                    os<<p[i];
                }
            }
            else{
                if(abs(p[i])!=1) os<<p[i];
                if(p[i]==-1) os <<"-";
            }
            if(i==1) os<<"x";
            else {
                if(i>1) os<<"x^"<<i;
                else if(i==0) os << p[i];
            }
            check_first=1;
        }
        else{
            if(p[i]>0){
                os<<" + ";
            }
            else os << " - ";
            if(abs(p[i])!=1) os<<abs(p[i]);
            if(i!=0){
                os<<"x";
                if(i>1) os <<"^"<<i;
            }
            else{
                os << abs(p[i]);
            }
        }
    }
    if(!check_first) os<<0;
    return os;
}


int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<=n;i++){
        cin >> a[i];
    }
    DaThuc p(n,a);
    cout <<p<<'\n';


    return 0;
}