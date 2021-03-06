#include <cmath>
#include "vec3.h"

// Assignment
vec3::vec3() {
    set(0, 0, 0);
}

vec3::vec3(double x, double y, double z) {
    set(x, y, z);
}

// Vector arithmetic operators
vec3 vec3::operator+(vec3 rhs) {
    return vec3( m_vec[0] + rhs.x(),
                 m_vec[1] + rhs.y(),
                 m_vec[2] + rhs.z());
}

vec3 vec3::operator-(vec3 rhs) {
    return vec3( m_vec[0] - rhs.x(),
                 m_vec[1] - rhs.y(),
                 m_vec[2] - rhs.z());
}

vec3 vec3::operator*(vec3 rhs) {
    return vec3( m_vec[0] * rhs.x(),
                 m_vec[1] * rhs.y(),
                 m_vec[2] * rhs.z());
}

vec3 vec3::operator/(vec3 rhs) {
    return vec3( m_vec[0] / rhs.x(),
                 m_vec[1] / rhs.y(),
                 m_vec[2] / rhs.z());
}

// Scalar arithmetic operators
vec3 vec3::operator+(double scalar) {
    return vec3(m_vec[0] + scalar,
                m_vec[1] + scalar,
                m_vec[2] + scalar);
}

vec3 vec3::operator-(double scalar) {
    return vec3(m_vec[0] - scalar,
                m_vec[1] - scalar,
                m_vec[2] - scalar);
}

vec3 vec3::operator*(double scalar) {
    return vec3(m_vec[0] * scalar,
                m_vec[1] * scalar,
                m_vec[2] * scalar);
}

vec3 vec3::operator/(double scalar) {
    return vec3(m_vec[0] / scalar,
                m_vec[1] / scalar,
                m_vec[2] / scalar);
}

// Assignment operators
vec3 vec3::set(double x, double y, double z) {
    m_vec[0] = x;
    m_vec[1] = y;
    m_vec[2] = z;
    return *this;
}

vec3 vec3::operator +=(vec3 rhs) {
    m_vec[0] += rhs.x();
    m_vec[1] += rhs.y();
    m_vec[2] += rhs.z();
    return *this;
}

vec3 vec3::operator -=(vec3 rhs) {
    m_vec[0] -= rhs.x();
    m_vec[1] -= rhs.y();
    m_vec[2] -= rhs.z();
    return *this;
}

vec3 vec3::operator *=(vec3 rhs) {
    m_vec[0] *= rhs.x();
    m_vec[1] *= rhs.y();
    m_vec[2] *= rhs.z();
    return *this;
}

vec3 vec3::operator /=(vec3 rhs) {
    m_vec[0] /= rhs.x();
    m_vec[1] /= rhs.y();
    m_vec[2] /= rhs.z();
    return *this;
}

vec3 vec3::operator %(vec3 rhs) {
    return vec3(fmod(m_vec[0], rhs.x()),
               fmod(m_vec[1], rhs.y()),
               fmod(m_vec[2], rhs.z()));
}

vec3 vec3::operator +=(double scalar) {
    m_vec[0] += scalar;
    m_vec[1] += scalar;
    m_vec[2] += scalar;
    return *this;
}

vec3 vec3::operator -=(double scalar) {
    m_vec[0] -= scalar;
    m_vec[1] -= scalar;
    m_vec[2] -= scalar;
    return *this;
}

vec3 vec3::operator *=(double scalar) {
    m_vec[0] *= scalar;
    m_vec[1] *= scalar;
    m_vec[2] *= scalar;
    return *this;
}

vec3 vec3::operator /=(double scalar) {
    m_vec[0] /= scalar;
    m_vec[1] /= scalar;
    m_vec[2] /= scalar;
    return *this;
}

// Vector products
double vec3::dot(vec3 &rhs) {
    return (m_vec[0] * rhs.x() +
            m_vec[1] * rhs.y() +
            m_vec[2] * rhs.z());
}


// Other
vec3 vec3::normalize() {
    double len = length();
    m_vec[0] /= len;
    m_vec[1] /= len;
    m_vec[2] /= len;
    return *this;
}

double vec3::length() {
    return sqrt(length_squared());
}

vec3 vec3::round() {
    // Elementwise round on the components
    return vec3(std::round(m_vec[0]), std::round(m_vec[1]), std::round(m_vec[2]));
}

vec3 vec3::floor() {
    return vec3(std::floor(m_vec[0]), std::floor(m_vec[1]), std::floor(m_vec[2]));
}

double vec3::sum() {
    return m_vec[0] + m_vec[1] + m_vec[2];
}

// Printing
std::ostream& operator<<(std::ostream &stream, vec3 &vec) {
    return stream << "[" << vec.x() << ", " << vec.y() << ", " << vec.z() << "]";
}
