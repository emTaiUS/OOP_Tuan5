#include <iostream>
#ifndef SO_TIEN_H
#define SO_TIEN_H

class SoTien {
    private:
        int dong,xu;
    public:
        SoTien();                                  // 0 đồng 0 xu
        SoTien(long long dong, long long xu);      // giá trị là dong * 100 + xu

        long long getDong() const;
        long long getXu() const;

        SoTien operator+(const SoTien& khac) const;
        SoTien operator-(const SoTien& khac) const;

        SoTien& operator+=(const SoTien& khac);
        SoTien& operator-=(const SoTien& khac);

        bool operator==(const SoTien& khac) const;
        bool operator!=(const SoTien& khac) const;
        bool operator<(const SoTien& khac) const;
        bool operator<=(const SoTien& khac) const;
        bool operator>(const SoTien& khac) const;
        bool operator>=(const SoTien& khac) const;

        friend std::ostream& operator<<(std::ostream& os, const SoTien& st);
};

#endif 