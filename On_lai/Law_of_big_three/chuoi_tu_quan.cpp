#include "chuoi_tu_quan.h"
#include <cstring>

using namespace std;

Chuoi :: Chuoi():kyTu(new char [1]),doDai(0){
    kyTu[0]='\0';
}

Chuoi :: Chuoi(const char *s):kyTu(new char [strlen(s)+1]),doDai(strlen(s)){
    strcpy(kyTu,s);
}

Chuoi :: Chuoi(const Chuoi& khac):kyTu(new char[khac.doDai+1]),doDai(khac.doDai){
    strcpy(kyTu,khac.kyTu);
}

Chuoi :: ~Chuoi (){
    delete [] kyTu;
}

Chuoi& Chuoi:: operator=(const Chuoi& khac){
    if(this != &khac){
        delete [] kyTu;
        doDai=khac.doDai;
        kyTu = new char [doDai+1];
        strcpy(kyTu,khac.kyTu);
    }
    return *this;
}

Chuoi& Chuoi :: operator +=(const Chuoi&khac){
    char * temp = new char [doDai+khac.doDai+1];
    strcpy(temp,kyTu);
    strcat(temp,khac.kyTu);
    delete []kyTu;
    kyTu = temp;
    doDai+=khac.doDai;

    return *this;
}

int Chuoi :: layDoDai() const {
    return doDai;
}

char Chuoi :: layKyTu(int i) const {
    return kyTu[i];
}

void Chuoi :: datKyTu(int i,char c){
    kyTu[i]=c;
}

const char * Chuoi :: c_str() const {
    return kyTu;
}