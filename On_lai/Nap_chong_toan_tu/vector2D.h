#ifndef VECTOR2D_H
#define VECTOR2D_H
#include<iostream>


class Vector2D {
private:
    int x, y;

public:         
    Vector2D();                           // vector không, tức (0, 0)
    Vector2D(int x=0, int y=0);

    int getX() const;
    int getY() const;

    Vector2D operator+(const Vector2D& v) const;    // tổng hai vector
    Vector2D operator-(const Vector2D& v) const;    // hiệu hai vector
    Vector2D operator-() const;                     // vector đối, toán tử một ngôi
    Vector2D operator*(int k) const;                // nhân với số nguyên, dạng v * k

    bool operator==(const Vector2D& v) const;
    bool operator!=(const Vector2D& v) const;

    friend Vector2D operator*(int k, const Vector2D& v);                   // dạng k * v
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
    friend std::istream& operator>>(std::istream& is, Vector2D& v);
};

#endif