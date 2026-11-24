#include "cam_bien.h"
#include <iostream>

using namespace std;


CamBien :: CamBien(int banDau):giaTri(banDau),soLan(0){};

int CamBien ::  doc() const {
    return giaTri;
}

int CamBien :: dem() const {
    return soLan;
}

void CamBien :: ghi(int moi){
    giaTri=moi;
    soLan++;
}

void CamBien :: ghi(int moi , int heSo){
    giaTri=moi * heSo;  
    soLan++;
}

CamBienNhietDo :: CamBienNhietDo(int banDau,int lech ):CamBien(banDau),doLech(lech){};

int CamBienNhietDo :: getDoLech() const {
    return doLech;
}

void CamBienNhietDo :: ghi(int moi){
    CamBien :: ghi(moi+doLech);
}

