#include <iostream>
#include <string>
#include "khoa_hoc.h"
using namespace std;

KhoaHoc :: KhoaHoc(const std::string& ma,int buoi,int phi) :maKhoa(ma),soBuoi(buoi),hocPhiMoiBuoi(phi){};

std::string KhoaHoc :: getMaKhoa() const {
    return maKhoa;
}

int KhoaHoc :: getSoBuoi() const {
    return soBuoi;
}

int KhoaHoc :: getHocPhiMoiBuoi () const {
    return hocPhiMoiBuoi;
}

long long KhoaHoc :: hocPhi() const {
    return 1LL*soBuoi*hocPhiMoiBuoi;
}

void KhoaHoc :: xuat() const {
    cout << "KHOA "<<maKhoa<<" BUOI "<<soBuoi<<" PHI "<<hocPhiMoiBuoi<<'\n';

}

KhoaHocTrucTiep::KhoaHocTrucTiep(const std::string&ma,int buoi,int phi,int phong) :KhoaHoc(ma,buoi,phi),phiPhong(phong){};

int KhoaHocTrucTiep::getPhiPhong() const {
    return phiPhong;
}

long long KhoaHocTrucTiep::hocPhi() const {
    return KhoaHoc::hocPhi()+phiPhong;
}

void KhoaHocTrucTiep::xuat() const {
    KhoaHoc::xuat();
    cout <<"TRUC_TIEP PHONG "<<phiPhong<<'\n';
}

KhoaHocTrucTuyen :: KhoaHocTrucTuyen(const std::string&ma,int buoi,int phi,int tuan) :
KhoaHoc(ma,buoi,phi),soTuan(tuan){};

int KhoaHocTrucTuyen::getSoTuan() const {
    return soTuan;
}

long long KhoaHocTrucTuyen :: hocPhi() const {
    if(soBuoi>=12){
        return KhoaHoc::hocPhi()*9/10;
    }
    else return KhoaHoc::hocPhi();
}

void KhoaHocTrucTuyen :: xuat() const {
    KhoaHoc::xuat();
    cout <<"TRUC_TUYEN TUAN "<<soTuan<<'\n';
}

