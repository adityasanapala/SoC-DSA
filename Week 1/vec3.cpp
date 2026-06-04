#include "vec3.h"

#include <cmath>
#include <cstdio>

// Constructor
Vec3::Vec3(float i1, float i2, float i3) : x(i1), y(i2), z(i3) {}

// Operators
Vec3 Vec3::operator+(const Vec3& v2) const { return Vec3(x + v2.x, y + v2.y, z + v2.z); }

Vec3 Vec3::operator-(const Vec3& v2) const { return Vec3(x - v2.x, y - v2.y, z - v2.z); }

Vec3 Vec3::operator*(float n) const { return Vec3(x * n, y * n, z * n); }

Vec3 Vec3::operator/(float n) const { return Vec3(x / n, y / n, z / n); }

Vec3 Vec3::operator-() const { return Vec3(-x, -y, -z); }

float Vec3::operator[](int i) const {
    if (i == 0) return x;
    if (i == 1) return y;

    return z;
}

float& Vec3::operator[](int i) {
    if (i == 0) return x;
    if (i == 1) return y;
    return z;
}

Vec3 operator*(float n, const Vec3& v) { return Vec3(v.x * n, v.y * n, v.z * n); }

// Methods
void Vec3::print() const { printf("%f %f %f\n", x, y, z); }

float Vec3::length() const { return std::sqrt((x * x) + (y * y) + (z * z)); }

Vec3 Vec3::unit() const {
    float len = this->length();
    if (len > 0.0f) { return (*this / len); }
    return Vec3(0, 0, 0);
}

float Vec3::dot(const Vec3& v2) const { return (x * v2.x + y * v2.y + z * v2.z); }

Vec3 Vec3::cross(const Vec3& v2) const {
    return Vec3((y * v2.z - z * v2.y), (z * v2.x - x * v2.z), (x * v2.y - y * v2.x));
}

Vec3 Vec3::reflect(const Vec3& norm) const {
    Vec3 unorm = norm.unit();
    return (*this - unorm * (2.0f * this->dot(unorm)));
}

// Refracts an incident ray based on Snell's Law
Vec3 Vec3::refract(const Vec3& norm, float coeff) const {
    Vec3 uv = this->unit();
    Vec3 unorm = norm.unit();

    float dt = uv.dot(unorm);
    float discriminant = 1.0f - coeff * coeff * (1.0f - dt * dt);

    if (discriminant > 0.0f) {
        Vec3 r_out_perp = (uv - unorm * dt) * coeff;
        Vec3 r_out_parallel = unorm * (-std::sqrt(discriminant));
        return r_out_perp + r_out_parallel;
    }
    else { return Vec3(0.0f, 0.0f, 0.0f); }
}
