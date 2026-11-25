#include "mang_so_dong.h"

using namespace std;

MangSo :: MangSo():duLieu(nullptr),soPhanTu(0){}

MangSo :: MangSo(int n,int giaTri):duLieu(n ? new int [n]:nullptr),soPhanTu(n){
    for(int i=0;i<n;i++){
        duLieu[i]=giaTri;
    }
}

MangSo :: MangSo(const MangSo& khac){
    soPhanTu=khac.soPhanTu;
    duLieu=new int [soPhanTu];
    for(int i=0;i<soPhanTu;i++){
        duLieu[i]=khac.duLieu[i];
    }
}

MangSo :: ~MangSo(){
    delete [] duLieu;
}

MangSo& MangSo :: operator= (const MangSo& khac){
    if(this!=&khac){
        delete[] duLieu;
        soPhanTu=khac.soPhanTu;
        if(soPhanTu){
            duLieu=new int [soPhanTu];
            for (int i=0;i<soPhanTu;i++){
                duLieu[i]=khac.duLieu[i];
            }
        }
        else {
            duLieu = nullptr;
        }
    }
    return *this;
}

int MangSo :: kichThuoc() const {
    return soPhanTu;
}

int MangSo :: layPhanTu(int i) const {
    return duLieu[i];
}

void MangSo :: datPhanTu(int i,int giaTri){
    duLieu[i]=giaTri;
}