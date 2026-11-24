#ifndef NGAN_XEP_TU_DANH_SACH_H
#define NGAN_XEP_TU_DANH_SACH_H
#include <iostream>

class DanhSach {
    protected:
        int* a;
        int n;
    public:
        DanhSach();
        DanhSach(const DanhSach& b);
        DanhSach& operator=(const DanhSach& b);
        ~DanhSach();
        int kichThuoc() const ;
        int layTai(int i) const ;
        void ganTai(int i,int x);
        void themCuoi(int x);
        void xoaCuoi();
        void xoaDau();
};

class NganXep : private DanhSach {
    public:
        void dayVao(int x) ;
        int layRa() ;
        int dinh() const;
        bool rong() const ;
        using DanhSach::kichThuoc;
};
#endif