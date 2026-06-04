#include <cmath>

class Vec3 {
public:
    float x, y, z;

    Vec3(float x=0, float y=0, float z=0): x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 operator-() const {
        return Vec3(-x, -y, -z);
    }

    Vec3 operator*(float s) const {
        return Vec3(x * s, y * s, z * s);
    }

    Vec3 operator/(float s) const {
        return Vec3(x / s, y / s, z / s);
    }

    float& operator[](int i) {
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
    }

    float operator[](int i) const {
        if(i == 0) return x;
        if(i == 1) return y;
        return z;
    }

    float length() const {
        return std::sqrt(x*x + y*y + z*z);
    }

    Vec3 unit() const {
        return *this / length();
    }

    float dot(const Vec3& other) const {
        return x*other.x + y*other.y + z*other.z;
    }

    Vec3 cross(const Vec3& other) const {
        return Vec3(
            y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x
        );
    }

    Vec3 reflect(const Vec3& normal) const {
    float d = this->dot(normal);

        if(d > 0)
            return *this;

        return *this - normal * (2.0f * d);
    }

    Vec3 refract(const Vec3& normal, float ri) const {
        Vec3 uv = this->unit();

        float cos_theta = -(uv.dot(normal));

        float k = 1.0f - ri * ri * (1.0f - cos_theta * cos_theta);

        if(k < 0.0f)
            return Vec3(0,0,0);

        return uv * ri +
               normal * (ri * cos_theta - std::sqrt(k));
    }
};

inline Vec3 operator*(float s, const Vec3& v) {
    return v * s;
}