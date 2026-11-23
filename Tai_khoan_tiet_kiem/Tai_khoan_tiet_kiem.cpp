#include "Tai_khoan_tiet_kiem.h"
#include <string>
#include <iostream>

using namespace std;

TaiKhoan :: TaiKhoan(const std::string&soTaiKhoan,const std::string&chuTaiKhoan,
            long long soDuBanDau):soTaiKhoan(soTaiKhoan),chuTaiKhoan(chuTaiKhoan),soDu(soDuBanDau){};

std::string TaiKhoan :: getSoTaiKhoan() const {
    return soTaiKhoan;
} 

std::string TaiKhoan :: getChuTaiKhoan() const {
    return chuTaiKhoan;
}

long long TaiKhoan :: getSoDu() const {
    return soDu;
}

void TaiKhoan :: napTien(long long soTien){
    soDu+=soTien;
}

bool TaiKhoan :: rutTien(long long soTien){
    if(soDu-soTien>=0) {
        soDu-=soTien;
        return true;
    }
    else return false;
}

void TaiKhoan :: xuat() const {
    cout <<soTaiKhoan<<" | "<<chuTaiKhoan<<" | "<<soDu<<'\n';
}

TaiKhoanTietKiem :: TaiKhoanTietKiem(const std::string&soTaiKhoan,const std::string&chuTaiKhoan,
            long long soDuBanDau,int laiSuat):TaiKhoan(soTaiKhoan,chuTaiKhoan,soDuBanDau),laiSuat(laiSuat),soLanRut(0){};

int TaiKhoanTietKiem :: getLaiSuat() const {
    return laiSuat;
}

int TaiKhoanTietKiem :: getSoLanRut() const {
    return soLanRut;
}

bool TaiKhoanTietKiem :: rutTien(long long soTien){
    if(soLanRut<2){
        if(TaiKhoan::rutTien(soTien)){
            soLanRut++;
            return 1;
        }
        else return 0;
    }
    else return 0;
}

void TaiKhoanTietKiem :: sangThangMoi(){
    soDu+=(soDu*laiSuat)/1000;
    soLanRut=0;
}


void TaiKhoanTietKiem :: xuat() const {
    TaiKhoan :: xuat();
    cout <<laiSuat<< " | "<<soLanRut<<'\n';
}

TaiKhoanCoKyHan :: TaiKhoanCoKyHan(const std::string&soTaiKhoan,const std::string&chuTaiKhoan,
            long long soDuBanDau,int laiSuat,int kyHanConLai):TaiKhoanTietKiem(soTaiKhoan,chuTaiKhoan,soDuBanDau,laiSuat),kyHanConLai(kyHanConLai){};

int TaiKhoanCoKyHan :: getKyHanConLai() const {
    return kyHanConLai;
}

bool TaiKhoanCoKyHan :: rutTien(long long soTien){
    if(kyHanConLai>0) return 0;
    else {
        return TaiKhoanTietKiem::rutTien(soTien);
    }
}

void TaiKhoanCoKyHan :: sangThangMoi(){
    TaiKhoanTietKiem::sangThangMoi();
    if(kyHanConLai>0) kyHanConLai--;
}

void TaiKhoanCoKyHan :: xuat() const {
    TaiKhoanTietKiem::xuat();
    cout <<kyHanConLai<<'\n';
}