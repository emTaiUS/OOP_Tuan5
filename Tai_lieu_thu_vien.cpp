#include <iostream>
#include <string>

using namespace std;

class TaiLieu {
    protected:
        std::string maSo;
        std::string tieuDe;
        int namXuatBan;
    public:
        TaiLieu(const std::string& maSo, const std::string& tieuDe, int namXuatBan);
        std::string getMaSo() const;
        std::string getTieuDe() const;
        int getNamXuatBan() const;
        int tuoi(int namHienTai) const;
        long long phiMuon(int soNgay) const;
        void xuat() const;
};

TaiLieu :: TaiLieu(const std::string&maSo,const std::string& tieuDe,int namXuatBan) : maSo(maSo),tieuDe(tieuDe),namXuatBan(namXuatBan){};

std::string TaiLieu:: getMaSo() const {
    return maSo;
}

std::string TaiLieu:: getTieuDe() const {
    return tieuDe;
}

int TaiLieu::getNamXuatBan() const {
    return namXuatBan;
}

int TaiLieu::tuoi(int namHienTai) const {
    return namHienTai-namXuatBan;
}

long long TaiLieu::phiMuon(int soNgay)const {
    return 1000*(long long)soNgay;
}

void TaiLieu:: xuat()const {
    cout <<maSo<<" | "<<tieuDe<<" | "<<namXuatBan<<'\n';
}

class Sach : public TaiLieu {
    protected:
        std::string tacGia;
        int soTrang;
    public:
        Sach(const std::string& maSo, const std::string& tieuDe, int namXuatBan,
            const std::string& tacGia, int soTrang);
        std::string getTacGia() const;
        int getSoTrang() const;
        long long phiMuon(int soNgay) const;
        void xuat() const;
};

Sach::Sach(const std::string& maSo, const std::string& tieuDe, int namXuatBan,
            const std::string& tacGia, int soTrang): TaiLieu(maSo,tieuDe,namXuatBan),tacGia(tacGia),soTrang(soTrang){};

std::string Sach:: getTacGia() const {
    return tacGia;
}

int Sach :: getSoTrang() const {
    return soTrang;
}

long long Sach:: phiMuon(int soNgay) const {
    return TaiLieu::phiMuon(soNgay)+(long long)soNgay*soTrang*10;
}

void Sach::xuat() const {
    TaiLieu::xuat();
    cout <<tacGia<<" | "<<soTrang<<'\n';
}


class TapChi : public TaiLieu {
    protected:
        int soPhatHanh;
        int thang;
    public:
        TapChi(const std::string& maSo, const std::string& tieuDe, int namXuatBan,
            int soPhatHanh, int thang);
        int getSoPhatHanh() const;
        int getThang() const;
        long long phiMuon(int soNgay) const;
        void xuat() const;
};

TapChi :: TapChi(const std:: string &maSo,const std::string&tieuDe,int namXuatBan,int soPhatHanh,int thang)
    :TaiLieu(maSo,tieuDe,namXuatBan),soPhatHanh(soPhatHanh),thang(thang){};

int TapChi::getSoPhatHanh() const {
    return soPhatHanh;
}

int TapChi::getThang() const {
    return thang;
}

long long TapChi::phiMuon(int soNgay) const {
    long long price= TaiLieu::phiMuon(soNgay);
    if(2026-namXuatBan>5) return price/2;
    else return price;
}

void TapChi::xuat()const {
    TaiLieu::xuat();
    cout <<soPhatHanh<<" | "<<thang<<'\n';
}
