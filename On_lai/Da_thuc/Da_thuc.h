#ifndef DA_THUC_H
#define DA_THUC_H
#include <iostream>


using namespace std;


class DaThuc {
    private:
        int n;
        int a[101];
    public:
        DaThuc();
        DaThuc(int n, const int a[]);
        int bac() const;
        int operator[](int i) const;
        DaThuc operator+(const DaThuc& b) const;
        DaThuc operator-(const DaThuc& b) const;
        DaThuc operator*(const DaThuc& b) const;
        long long giaTri(int x) const;
        friend std::ostream& operator<<(std::ostream& os, const DaThuc& p);
};





#endif