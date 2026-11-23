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
    return 1000*soNgay;
}

void TaiLieu:: xuat()const {
    
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




int main(){




    return 0;
}