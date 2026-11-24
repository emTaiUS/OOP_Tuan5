class MangSo {
private:
    int* duLieu;    
    int soPhanTu;    

public:
    MangSo();                         
    MangSo(int n, int giaTri);                
    MangSo(const MangSo& khac);               
    ~MangSo();                                
    MangSo& operator=(const MangSo& khac);     

    int kichThuoc() const;                   
    int layPhanTu(int i) const;                
    void datPhanTu(int i, int giaTri);         
};