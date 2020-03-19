#pragma once
#include<iostream>
#include<cmath>
class Vector3D {
private:
    double x;
    double y;
    double z;
public:
    Vector3D();
    Vector3D(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double getLength() const;

    bool operator== (const Vector3D& v2) const;
    bool operator!= (const Vector3D& v2) const;

    Vector3D operator+ (const Vector3D& v2) const;
    Vector3D operator- (const Vector3D& v2) const;
    Vector3D operator* (const double a) const;
    Vector3D operator/ (const double a) const;

    Vector3D operator+= (const Vector3D& b);
    Vector3D operator-= (const Vector3D& b);
    Vector3D operator*= (const double b);
    Vector3D operator/= (const double b);

};

Vector3D operator* (double a, const Vector3D& v);
std::ostream& operator<<(std::ostream& os, const Vector3D& v);  //(õ; ó; z)
std::istream& operator>>(std::istream& is, Vector3D& v);

double scalarProduct(Vector3D v1, Vector3D v2);
double getAngle(Vector3D v1, Vector3D v2);
Vector3D vectorProduct(Vector3D v1, Vector3D v2);