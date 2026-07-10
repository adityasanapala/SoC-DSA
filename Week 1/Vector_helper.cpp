#include<iostream>
#include <cmath>

using namespace std;

class Vec3 {
public:
    float x, y, z;

    Vec3(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }

    Vec3 operator+(const Vec3& v) const {
        return Vec3(x + v.x,
            y + v.y,
            z + v.z);
    }

    Vec3 operator-(const Vec3& v) const {
        return Vec3(x - v.x,
            y - v.y,
            z - v.z);
    }

    Vec3 operator*(float k) const {
        return Vec3(x * k,
            y * k,
            z * k);
    }
    Vec3 operator/(float k) const {
        return Vec3(x / k,
            y / k,
            z / k);
    }
    Vec3 operator-() const {
        return Vec3(-x, -y, -z);
    }
    float& operator[](int i) {
        if(i == 0) return x;
        if(i == 1) return y;
        if(i == 2) return z;
    }
    float length() const {
        return sqrt(x*x + y*y + z*z);
    }
    Vec3 unit() const {
        float len = length();
        if (len==0) return Vec3(0,0,0);
        return Vec3(x / len, y / len, z / len);
    }

    float dot(const Vec3& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    Vec3 cross(const Vec3& v) const {
        return Vec3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }
    Vec3 reflect(const Vec3& normal) const {
        return *this - normal * (2.0f * dot(normal));
    }

    Vec3 refract(const Vec3& normal, float refractive_index) const {
        float cos_theta = -this->unit().dot(normal);

        Vec3 r_out_perp =
            (*this + normal * cos_theta) * refractive_index;

        Vec3 r_out_parallel =
            normal * (-sqrt(fabs(1.0f - r_out_perp.dot(r_out_perp))));

        return r_out_perp + r_out_parallel;
    }
};


