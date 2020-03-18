#include "Vector3D.h"

Vector3D::Vector3D() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3D::Vector3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector3D::getX() const { return x; }
double Vector3D::getY() const { return y; }
double Vector3D::getZ() const { return z; }

void Vector3D::setX(double x) { this->x = x; }
void Vector3D::setY(double y) { this->y = y; }
void Vector3D::setZ(double z) { this->z = z; }

double Vector3D::getLength() const {
    return sqrt(x * x + y * y + z * z);
}

bool Vector3D::operator==(const Vector3D& v2) const {
    return (x == v2.getX() && y == v2.getY() && z == v2.getZ());
}

bool Vector3D::operator!=(const Vector3D& v2) const {
    return !(x == v2.getX() && y == v2.getY() && z == v2.getZ());
}

Vector3D Vector3D::operator+(const Vector3D& v2) const {
    double x2 = x + v2.x;
    double y2 = y + v2.y;
    double z2 = z + v2.z;
    return Vector3D(x2, y2, z2);
}

Vector3D Vector3D::operator-(const Vector3D& v2) const {
    double x2 = x - v2.x;
    double y2 = y - v2.y;
    double z2 = z - v2.z;
    return Vector3D(x2, y2, z2);
}

Vector3D Vector3D::operator*(const double a) const {
    double x2 = x * a;
    double y2 = y * a;
    double z2 = z * a;
    return Vector3D(x2, y2, z2);
}

Vector3D Vector3D::operator+=(const Vector3D& b) {
    x += b.x;
    y += b.y;
    z += b.z;
    return *this;
}

Vector3D Vector3D::operator-=(const Vector3D& b) {
    x -= b.x;
    y -= b.y;
    z -= b.z;
    return *this;
}

Vector3D Vector3D::operator*=(const double b) {
    x *= b;
    y *= b;
    z *= b;
    return *this;
}

Vector3D Vector3D::operator/=(const double b) {
    x /= b;
    y /= b;
    z /= b;
    return *this;
}

Vector3D operator*(double a, const Vector3D& v) {
    double x2 = a * v.getX();
    double y2 = a * v.getY();
    double z2 = a * v.getZ();
    return Vector3D(x2, y2, z2);
}

double scalarProduct(Vector3D v1, Vector3D v2) {
    return (v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ());
}

double getAngle(Vector3D v1, Vector3D v2) {
    return (scalarProduct(v1, v2) / (v1.getLength() * v2.getLength()));
}

Vector3D vectorProduct(Vector3D v1, Vector3D v2) {
    Vector3D v3;
    v3.setX(v1.getY() * v2.getZ() - v1.getZ() * v2.getY());
    v3.setY(v1.getZ() * v2.getX() - v1.getX() * v2.getZ());
    v3.setZ(v1.getX() * v2.getY() - v1.getY() * v2.getX());
    return v3;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << "(" << v.getX() << "; " << v.getY() << "; " << v.getZ() << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector3D& v) {
    double a, b, c;
    is >> a;
    is >> b;
    is >> c;
    v.setX(a);
    v.setY(b);
    v.setZ(c);
    return is;
}