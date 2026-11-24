#include <iostream>
#ifndef CAM_BIEN_H
#define CAM_BIEN_H
using namespace std;

class CamBien {
    protected:
        int giaTri;
        int soLan;
    public:
        CamBien(int banDau) ;
        int doc() const ;
        int dem() const;
        void ghi(int moi) ;
        void ghi(int moi, int heSo) ;
};
class CamBienNhietDo : public CamBien {
    protected:
        int doLech;
    public:
        CamBienNhietDo(int banDau, int lech) ;
        int getDoLech() const ;
        using CamBien :: ghi;
        void ghi(int moi) ;
};

#endif