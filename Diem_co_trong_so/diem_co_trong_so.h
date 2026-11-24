#ifndef DIEM_CO_TRONG_SO_H
#define DIEM_CO_TRONG_SO_H
using namespace std;

class DayDiem {
    protected:
        int* diem;
        int n;
    public:
        DayDiem(int so=0,int d=0);
        DayDiem(const DayDiem& b) ;
        DayDiem& operator=(const DayDiem& b) ;
        ~DayDiem();
        int kichThuoc() const ;
        int layDiem(int i) const ; 
        void datDiem(int i,int d) ;
};

class DayDiemTrongSo : public DayDiem {
    protected:
        int* trongSo;
    public:
        DayDiemTrongSo(int so=0,int d=0,int w=1) ;
        DayDiemTrongSo(const DayDiemTrongSo& b) ;
        DayDiemTrongSo& operator=(const DayDiemTrongSo& b) ;
        ~DayDiemTrongSo();
        int layTrongSo(int i) const ;
        void datTrongSo(int i,int w) ;
        void them(int d,int w) ;
        long long tuSo() const ;
        long long mauSo() const ;
};

#endif