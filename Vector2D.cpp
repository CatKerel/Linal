#include "Vector2D.h"

Vector2D::Vector2D() {
    this->x = 0;
    this->y = 0;
}

Vector2D::Vector2D(double x, double y) {
    this->x = x;
    this->y = y;
}

double Vector2D::getX() const { return x; }
double Vector2D::getY() const { return y; }

void Vector2D::setX(double x) { this->x = x; }
void Vector2D::setY(double y) { this->y = y; }

double Vector2D::getLength() const {
    return sqrt(x * x + y * y);
}

bool Vector2D::operator==(const Vector2D& v2) const {
    return (x == v2.getX() && y == v2.getY());
}

bool Vector2D::operator!=(const Vector2D& v2) const {
    return !(x == v2.getX() && y == v2.getY());
}

Vector2D Vector2D::operator+(const Vector2D& v2) const {
    double x2 = x + v2.x;
    double y2 = y + v2.y;
    return Vector2D(x2, y2);
}

Vector2D Vector2D::operator-(const Vector2D& v2) const {
    double x2 = x - v2.x;
    double y2 = y - v2.y;
    return Vector2D(x2, y2);
}

Vector2D Vector2D::operator*(const double a) const {
    double x2 = x * a;
    double y2 = y * a;
    return Vector2D(x2, y2);
}

Vector2D Vector2D::operator/(const double a) const {
    double x2 = x / a;
    double y2 = y / a;
    return Vector2D(x2, y2);
}

Vector2D Vector2D::operator+=(const Vector2D& b) {
    x += b.x;
    y += b.y;
    return *this;
}

Vector2D Vector2D::operator-=(const Vector2D& b) {
    x -= b.x;
    y -= b.y;
    return *this;
}

Vector2D Vector2D::operator*=(const double b) {
    x *= b;
    y *= b;
    return *this;
}

Vector2D Vector2D::operator/=(const double b) {
    x /= b;
    y /= b;
    return *this;
}

Vector2D operator*(double a, const Vector2D& v) {
    double x2 = a * v.getX();
    double y2 = a * v.getY();
    return Vector2D(x2, y2);
}
    
double scalarProduct(Vector2D v1, Vector2D v2) {
    return (v1.getX() * v2.getX() + v1.getY() * v2.getY());
}

double getAngle(Vector2D v1, Vector2D v2) {
    return (scalarProduct(v1, v2) / (v1.getLength() * v2.getLength()));
}

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2D& v) {
    double a, b;
    is >> a;
    is >> b;
    v.setX(a);
    v.setY(b);
    return is;
}