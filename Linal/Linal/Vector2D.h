#pragma once
#include<iostream>
#include<cmath>
class Vector2D {
private:
    double x;
    double y;
public:
    Vector2D();
    Vector2D(double x, double y);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    double getLength() const;

    bool operator== (const Vector2D& v2) const;
    bool operator!= (const Vector2D& v2) const;

    Vector2D operator+ (const Vector2D& v2) const;
    Vector2D operator- (const Vector2D& v2) const;
    Vector2D operator* (const double a) const;
    Vector2D operator/ (const double a) const;

    Vector2D operator+= (const Vector2D& b);
    Vector2D operator-= (const Vector2D& b);
    Vector2D operator*= (const double b);
    Vector2D operator/= (const double b);

};
Vector2D operator* (double a, const Vector2D& v);  
std::ostream& operator<<(std::ostream& os, const Vector2D& v);  //(õ; ó)
std::istream& operator>>(std::istream& is, Vector2D& v); 
double scalarProduct(Vector2D v2, Vector2D v3);
double getAngle(Vector2D v2, Vector2D v3);
