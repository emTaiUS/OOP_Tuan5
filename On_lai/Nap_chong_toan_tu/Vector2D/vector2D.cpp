#include "vector2D.h"

#include <iostream>

using namespace std;

Vector2D :: Vector2D():x(0),y(0){}

Vector2D :: Vector2D(int x,int y):x(x),y(y){};

int Vector2D:: getX() const {
    return x;
}

int Vector2D :: getY() const {
    return y;
}

Vector2D Vector2D:: operator-(const Vector2D& v) const{
    return Vector2D(x-v.x,y-v.y);
}

Vector2D Vector2D:: operator+(const Vector2D& v) const {
    return Vector2D(x+v.x,y+v.y);
}

Vector2D Vector2D::operator-() const {
    return Vector2D(-x,-y);
}

Vector2D Vector2D::operator*(int k) const {
    return Vector2D(k*x,k*y);
}

bool Vector2D :: operator==(const Vector2D& v) const {
    return (x==v.x)&&(y==v.y);
}

bool Vector2D :: operator!=(const Vector2D& v) const {
    return !(*this==v);
}

Vector2D operator * (int k,const Vector2D&v){
    return Vector2D(k*v.x,k*v.y);
}

std::ostream& operator << (std::ostream& os ,const Vector2D& v){
    os <<"("<<v.x<<", "<<v.y<<')';
    return os;
}

std::istream& operator >>(std::istream& is ,Vector2D& v){
    is >> v.x >> v.y;
    return is;
}


