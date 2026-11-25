class Chuoi {
private:
    char* kyTu;     // mảng cấp phát bằng new char[...], kết thúc bằng '\0'
    int doDai;      // số ký tự, không tính '\0'

public:
    Chuoi();                                  // chuỗi rỗng
    Chuoi(const char* s);                     // chép nội dung của chuỗi kiểu C s
    Chuoi(const Chuoi& khac);                 // hàm tạo sao chép
    ~Chuoi();                                 // hàm hủy
    Chuoi& operator=(const Chuoi& khac);      // toán tử gán sao chép
    Chuoi& operator+=(const Chuoi& khac);     // nối khac vào cuối

    int layDoDai() const;                     // số ký tự
    char layKyTu(int i) const;                // ký tự thứ i, 0 <= i < layDoDai()
    void datKyTu(int i, char c);              // đổi ký tự thứ i thành c
    const char* c_str() const;                // dãy ký tự, kết thúc bằng '\0'
};
