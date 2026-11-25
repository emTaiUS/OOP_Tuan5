#ifndef SAN_PHAM_H
#define SAN_PHAM_H
#include <iostream>


using namespace std;


class SanPham {
private:
    int ma;
    int gia;
    int soLuong;
public:
    SanPham();                              // ma = 0, gia = 0, soLuong = 0
    SanPham(int ma, int gia, int soLuong);
    int layMa() const;
    int layGia() const;
    int laySoLuong() const;
    long long giaTri() const;               // gia * soLuong, dùng long long
    friend std::ostream& operator<<(std::ostream& os, const SanPham& sp);
};


class SanPhamGiamGia : public SanPham {
protected:
    int phanTramGiam;                       // từ 0 đến 100
public:
    SanPhamGiamGia(int ma, int gia, int soLuong, int pct);
    long long giaTri() const;               // định nghĩa lại
};


class KhoSanPham {
private:
    SanPham* ds;
    int soLoai;
public:
    KhoSanPham();                                          // rỗng
    KhoSanPham(const KhoSanPham& khac);                    // hàm tạo sao chép sâu
    ~KhoSanPham();                                         // hàm hủy
    KhoSanPham& operator=(const KhoSanPham& khac);         // gán sâu, trả *this
    KhoSanPham& operator+=(const SanPham& sp);             // thêm sp vào cuối, cấp phát lại
    SanPham& operator[](int i);                            // truy cập, sửa được
    const SanPham& operator[](int i) const;                // truy cập, chỉ đọc
    int soLuongLoai() const;
    long long tongGiaTri() const;                          // tổng giaTri() của mọi phần tử
};



#endif