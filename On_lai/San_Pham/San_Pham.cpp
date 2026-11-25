#include <iostream>
#include "San_Pham.h"

using namespace std;

SanPham :: SanPham():ma(0),gia(0),soLuong(0){}

SanPham :: SanPham(int ma,int gia ,int soLuong):ma(ma),gia(gia),soLuong(soLuong){}

int SanPham ::layMa() const {
    return ma;
}

int SanPham :: layGia() const {
    return gia;
}

int SanPham :: laySoLuong() const {
    return soLuong;
}

long long SanPham :: giaTri() const {
    return 1LL*gia*soLuong;
}

std::ostream& operator <<(std::ostream& os, const SanPham& sp ){
    os << sp.ma << ' ' << sp.gia << ' '<< sp.soLuong;
    return os;
}

SanPhamGiamGia :: SanPhamGiamGia(int ma,int gia,int soLuong,int pct):SanPham(ma,gia,soLuong),phanTramGiam(pct){}

long long SanPhamGiamGia :: giaTri() const {
    return SanPham::giaTri()*(100-phanTramGiam)/100;
}

KhoSanPham :: KhoSanPham():ds(nullptr),soLoai(0){}

KhoSanPham :: KhoSanPham(const KhoSanPham& khac):ds(khac.soLoai?new SanPham [khac.soLoai]:nullptr),soLoai(khac.soLoai){
    for(int i=0;i<soLoai;i++){
        ds[i]=khac.ds[i];
    }
};

KhoSanPham :: ~KhoSanPham(){
    delete []ds;
}

KhoSanPham& KhoSanPham :: operator=(const KhoSanPham& khac){
    if(this!=&khac){
        soLoai=khac.soLoai;
        delete []ds;
        ds = new SanPham [soLoai];
        for(int i=0;i<soLoai;i++){
            ds[i]=khac.ds[i];
        }
    }
    return *this;
}

KhoSanPham& KhoSanPham:: operator+=(const SanPham&sp){
    SanPham* res=new SanPham[soLoai+1];
    for(int i=0;i<soLoai;i++){
        res[i]=ds[i];
    }
    res[soLoai]=sp;
    soLoai++;
    delete []ds;
    ds=res;
    return *this;
}

SanPham& KhoSanPham:: operator[](int i){
    return ds[i];
}

const SanPham& KhoSanPham :: operator[](int i) const {
    return ds[i];
}

int KhoSanPham :: soLuongLoai() const {
    return soLoai;
}

long long KhoSanPham :: tongGiaTri() const {
    long long res=0;
    for(int i=0;i<soLoai;i++){
        res+=ds[i].giaTri();
    }
    return res;
}

