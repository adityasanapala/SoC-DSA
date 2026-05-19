#include <iostream>
using namespace std;

#include <cmath>

class Vec3{
private:
    float x;
    float y;
    float z;
public:
    Vec3(float a, float b, float c){
        x = a;
        y = b;
        z = c;
    }
    Vec3 operator+(const Vec3& t)const{
        return Vec3(x + t.x, y + t.y , z + t.z);
    }
    Vec3 operator-(const Vec3& t)const{
        return Vec3(x - t.x, y - t.y , z - t.z);
    }
    Vec3 operator*(float n)const{
        return Vec3(x*n, y*n , z*n);
    }
    Vec3 operator/(float n)const{
        return Vec3(x/n, y/n, z/n);
    }
    Vec3 operator-()const{
        return Vec3 (-x, -y, -z);
    }
    float operator[](int i)const{
        if (i == 0) return x;
        else if (i == 1) return y;
        else return z;
    }
    float length()const{
        return sqrt(x*x + y*y + z*z);
    }
    Vec3 unit()const{
        return Vec3(x / length(), y/length(), z/length());
    }
    float dot(const Vec3 & v)const{
        return (v.x * x + v.y * y + v.z * z);
    }
    Vec3 cross (const Vec3 & v)const{
    return Vec3(y * v.z - z * v.y, z * v.x - x * v.z , x * v.y - y * v.x);
    }
    Vec3 reflect(const Vec3& n)const{
        Vec3 unit_n= n.unit();
        return *this -unit_n* 2*(this->dot(unit_n));
        
    }
    Vec3 refract(const Vec3 & normal, float eta)const{
        Vec3 unit_v = this->unit();
        Vec3 unit_n = normal.unit();
        
        float cos1 = -(unit_v.dot(unit_n));
        float cos2 = sqrt(1 - (1/(eta*eta)) * (1 - cos1*cos1));
        
        return unit_v * (1/eta) + unit_n * (cos1/eta - cos2);
    }
};

int main(){
    Vec3 v1(1, 0, 0);
    Vec3 v2(0, 1, 0);
    Vec3 v3(3, 4, 0);

    // operator+
    Vec3 add = v1 + v2;
    cout << "v1+v2: " << add[0] << " " << add[1] << " " << add[2] << endl;
    // expected: 1 1 0

    // operator-
    Vec3 sub = v1 - v2;
    cout << "v1-v2: " << sub[0] << " " << sub[1] << " " << sub[2] << endl;
    // expected: 1 -1 0

    // operator*
    Vec3 mul = v3 * 2;
    cout << "v3*2: " << mul[0] << " " << mul[1] << " " << mul[2] << endl;
    // expected: 6 8 0

    // operator/
    Vec3 div = v3 / 2;
    cout << "v3/2: " << div[0] << " " << div[1] << " " << div[2] << endl;
    // expected: 1.5 2 0

    // unary -
    Vec3 neg = -v3;
    cout << "neg v3: " << neg[0] << " " << neg[1] << " " << neg[2] << endl;
    // expected: -3 -4 0

    // length
    cout << "length v3: " << v3.length() << endl;
    // expected: 5

    // unit
    Vec3 u = v3.unit();
    cout << "unit v3: " << u[0] << " " << u[1] << " " << u[2] << endl;
    // expected: 0.6 0.8 0

    // dot
    cout << "dot v1,v2: " << v1.dot(v2) << endl;
    // expected: 0 (perpendicular)

    // cross
    Vec3 cr = v1.cross(v2);
    cout << "cross v1,v2: " << cr[0] << " " << cr[1] << " " << cr[2] << endl;
    // expected: 0 0 1

    // reflect
    Vec3 incident(1, -1, 0);
    Vec3 normal(0, 1, 0);
    Vec3 ref = incident.reflect(normal);
    cout << "reflect: " << ref[0] << " " << ref[1] << " " << ref[2] << endl;
    // expected: 1 1 0

    // refract
    Vec3 inc2(0, -1, 0);
    Vec3 norm2(0, 1, 0);
    Vec3 refr = inc2.refract(norm2, 1.5);
    cout << "refract: " << refr[0] << " " << refr[1] << " " << refr[2] << endl;
    // expected: 0 -1 0 (straight down, no bending at 0 degrees)
}