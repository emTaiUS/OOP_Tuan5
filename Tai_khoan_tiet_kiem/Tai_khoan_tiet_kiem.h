#ifndef TAI_KHOAN_TIET_KIEM_H
#define TAI_KHOAN_TIET_KIEM_H

#include <string>
using namespace std;

class TaiKhoan{
    protected:
        std::string soTaiKhoan;
        std::string chuTaiKhoan;
        long long soDu;
    public:
        TaiKhoan(const std::string&soTaiKhoan,const std::string&chuTaiKhoan,long long soDuBanDau);
        std::string getSoTaiKhoan() const ;
        std::string getChuTaiKhoan() const ;
        long long getSoDu() const;
        void napTien(long long soTien);
        bool rutTien(long long soTien);
        void xuat() const ;
};

class TaiKhoanTietKiem : public TaiKhoan{
    protected:
        int laiSuat;
        int soLanRut;
    public:
        TaiKhoanTietKiem(const std::string& soTaiKhoan,const std::string& chuTaiKhoan,long long soDuBanDau,int laiSuat);
        int getLaiSuat() const ;
        int getSoLanRut() const ;
        bool rutTien(long long soTien);
        void sangThangMoi();
        void xuat() const ;
};

class TaiKhoanCoKyHan :public TaiKhoanTietKiem{
    protected:
        int kyHanConLai;
    public:
        TaiKhoanCoKyHan(const std::string& SoTaiKhoan,const std::string& chuTaiKhoan,long long soDuBanDau,int laiSuat,int kyHanConLai);
        int getKyHanConLai() const ;
        bool rutTien(long long soTien);
        void sangThangMoi();
        void xuat() const ;
};

#endif