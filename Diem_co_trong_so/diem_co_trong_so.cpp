#include <iostream>
#include "diem_co_trong_so.h"


using namespace std;

DayDiem :: DayDiem (int so,int d):diem(so ? new int [so]:nullptr),n(so){
    if(so){
        for(int i=0;i<so;i++){
            diem[i]=d;
        }
    }
}

DayDiem :: DayDiem (const DayDiem& b):diem(b.n ? new int [b.n]: nullptr),n(b.n){
    for(int i=0;i<n;i++){
        diem[i]=b.diem[i];
    }
}

DayDiem& DayDiem:: operator=(const DayDiem &b){
    if(this==&b) return *this;
    n=b.n;
    delete [] diem;
    if(b.n){
        diem = new int [n];

        for(int i=0;i<n;i++){
            diem[i]=b.diem[i];
        }

    }
    else {
        diem=nullptr;
    }
    return *this;
}

DayDiem :: ~DayDiem(){
    delete [] diem;
}

int DayDiem :: kichThuoc() const {
    return n;
}

int DayDiem :: layDiem(int i) const {
    if(i<n) return diem[i];
    else return -1;
}

void DayDiem :: datDiem(int i,int d){
    if(i<n) diem[i]=d;
    else return ;
}

DayDiemTrongSo :: DayDiemTrongSo(int so,int d,int w):DayDiem(so,d),trongSo(so ? new int [so]:nullptr){
    if(so){
        for(int i=0;i<so;i++){
            trongSo[i]=w;
        }
    }
}

DayDiemTrongSo :: DayDiemTrongSo(const DayDiemTrongSo&b):DayDiem::DayDiem(b),trongSo(b.n ? new int [b.n]:nullptr){
    for(int i=0;i<b.n;i++){
        trongSo[i]=b.trongSo[i];
    }
}
 
DayDiemTrongSo& DayDiemTrongSo:: operator = (const DayDiemTrongSo&b){
    DayDiem::operator=(b);
    if(this==&b) return *this;
    delete [] trongSo;
    if(n){
        trongSo=new int [n];
        for(int i=0;i<n;i++){
            trongSo[i]=b.trongSo[i];
        }
    }
    else {
        trongSo=nullptr;
    }
    return *this;
}   

DayDiemTrongSo :: ~DayDiemTrongSo(){
    delete [] trongSo;
}

int DayDiemTrongSo:: layTrongSo(int i) const {
    return trongSo[i];
}

void DayDiemTrongSo :: datTrongSo(int i,int w){
    trongSo[i]=w;
}

void DayDiemTrongSo :: them(int d,int w){
    int *p1 = new int [n+1];
    int *p2 = new int [n+1];
    for(int i=0;i<n;i++){
        p1[i]=diem[i];
        p2[i]=trongSo[i];
    }
    p1[n]=d;
    p2[n]=w;
    delete [] diem;
    delete [] trongSo;
    diem=p1;
    trongSo=p2;
    n++;
}

using ll = long long ;
ll DayDiemTrongSo::tuSo() const {
    ll res=0;
    for(int i=0;i<n;i++){
        res+=1LL*diem[i]*trongSo[i];        
    }
    return res;
}

ll DayDiemTrongSo :: mauSo() const {
    ll res=0;
    for (int i=0;i<n;i++){
        res+=trongSo[i];
    }
    return res;
}