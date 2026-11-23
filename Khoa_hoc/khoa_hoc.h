#ifndef KHOA_HOC_H
#define KHOA_HOC_H
#include <string>

using namespace std;

class KhoaHoc {
protected:
    std::string maKhoa;
    int soBuoi;
    int hocPhiMoiBuoi;
public:
    KhoaHoc(const std::string& ma, int buoi, int phi);
    std::string getMaKhoa() const;
    int getSoBuoi() const;
    int getHocPhiMoiBuoi() const ;
    long long hocPhi() const ;
    void xuat() const ;
};
class KhoaHocTrucTiep : public KhoaHoc {
protected:
    int phiPhong;
public:
    KhoaHocTrucTiep(const std::string& ma, int buoi, int phi, int phong) ;
    int getPhiPhong() const  ;
    long long hocPhi() const ;
    void xuat() const ;
};
class KhoaHocTrucTuyen : public KhoaHoc {
protected:
    int soTuan;
public:
    KhoaHocTrucTuyen(const std::string& ma, int buoi, int phi, int tuan) ;
    int getSoTuan() const ;
    long long hocPhi() const  ;
    void xuat() const ;
};



#endif