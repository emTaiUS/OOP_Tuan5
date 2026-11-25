#include <iostream>
#include "so_tien.h";

using namespace std;

SoTien :: SoTien():dong(0),xu(0){}

SoTien :: SoTien(long long dong,long long xu):dong((dong*100+xu)/100),xu((dong*100+xu)%100){}


long long SoTien :: getDong() const {
    return dong;
}

long long SoTien :: getXu() const {
    return xu;
}

SoTien SoTien:: operator+(const SoTien& khac) const {
    return SoTien(dong+khac.dong,xu+khac.xu);
}

SoTien SoTien:: operator-(const SoTien& khac) const {
    return SoTien(dong-khac.dong,xu-khac.xu);
}

SoTien& SoTien :: operator+=(const SoTien & khac){
    *this=*this+khac;
    return *this;
}

SoTien& SoTien :: operator-=(const SoTien& khac){
    *this=*this-khac;
    return *this;
}

bool SoTien :: operator==(const SoTien& khac) const {
    return (dong*100+xu)==(khac.dong*100+khac.xu);
}

bool SoTien :: operator!=(const SoTien& khac) const {
    return !(*this==khac);
}

bool SoTien :: operator<(const SoTien& khac ) const {
    return (dong*100+xu)<(khac.dong*100+khac.xu);
}

bool SoTien :: operator<=(const SoTien& khac) const {
    return *this<khac||*this==khac;
}

bool SoTien :: operator>(const SoTien& khac) const {
    return !(*this<=khac);
}

bool SoTien :: operator>=(const SoTien&khac) const {
    return (*this>khac)||(*this==khac);
}

std::ostream& operator << (std::ostream& os , const SoTien&st){
    os << st.dong<<" dong "<<st.xu<<" xu";
    return os ;
}