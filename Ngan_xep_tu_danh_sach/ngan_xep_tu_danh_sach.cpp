#include "ngan_xep_tu_danh_sach.h"
#include <iostream>

using namespace std;

DanhSach :: DanhSach():a(nullptr),n(0){}

DanhSach :: DanhSach(const DanhSach & b):a(b.n ? new int [b.n] : nullptr),n(b.n){
    for(int i=0;i<n;i++) a[i]=b.a[i];
}

DanhSach& DanhSach::operator= (const DanhSach& b){
    if(this!=&b){
        n=b.n;
        delete []a;
        if(n>0){
            for(int i=0;i<n;i++){
                a[i]=b.a[i];
            }
        }
        else a=nullptr;
    }
    return *this;
}

DanhSach :: ~DanhSach(){
    delete [] a;
    n=0;
}

int DanhSach :: kichThuoc() const {
    return n;
}

int DanhSach :: layTai(int i) const {
    return a[i];
}

void DanhSach :: ganTai(int i,int x){
    a[i]=x;
}

void DanhSach :: themCuoi(int x){
    int* p = new int [n+1];
    for(int i=0;i<n;i++){
        p[i]=a[i];
    }
    p[n]=x;
    delete [] a ,a=p,n++;
}

void DanhSach :: xoaCuoi(){
    if(n>0) n--;
}

void DanhSach :: xoaDau(){
    if(n>0){
        for(int i=0;i<n-1;i++){
            a[i]=a[i+1];
        }
        n--;
    }
}

int NganXep :: dinh() const {
    if(kichThuoc()>0)   return a[DanhSach::kichThuoc()-1];
    else return 0;
}

bool NganXep :: rong() const {
    return DanhSach::kichThuoc()==0;
}

int NganXep :: layRa(){
    if(DanhSach::kichThuoc()>0){
        int res=layTai(kichThuoc()-1);
        DanhSach::xoaCuoi();
        return res;
    }
    else return 0;
}


void NganXep :: dayVao(int x){
    themCuoi(x);
}
