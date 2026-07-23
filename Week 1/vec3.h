#ifndef VEC3_H

#define VEC3_H

class Vec3 {
public:
    float x, y, z;

    // Constructor
    Vec3(float i1 = 0.0f, float i2 = 0.0f, float i3 = 0.0f);

    // Operators
    Vec3 operator-() const;
    Vec3 operator+(const Vec3& v2) const;
    Vec3 operator-(const Vec3& v2) const;
    Vec3 operator*(float n) const;
    Vec3 operator/(float n) const;
    float operator[](int i) const;
    float& operator[](int i);

    // Methods
    void print() const;
    float length() const;
    Vec3 unit() const;
    float dot(const Vec3& v2) const;
    Vec3 cross(const Vec3& v2) const;
    Vec3 reflect(const Vec3& norm) const;
    Vec3 refract(const Vec3& norm, float coeff) const;
};

// Free function for commutative multiplication: float * Vec3
Vec3 operator*(float n, const Vec3& v);

#endif  // VEC3_H
