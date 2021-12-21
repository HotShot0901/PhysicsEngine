#include "vector3.hpp"

namespace vectors
{
    Vector3Struct::Vector3Struct(float _x, float _y, float _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    Vector3 Vector3::xUnit = Vector3(1, 0, 0);
    Vector3 Vector3::yUnit = Vector3(0, 1, 0);
    Vector3 Vector3::zUnit = Vector3(0, 0, 1);

    Vector3 Vector3::once = Vector3(1, 1, 1);
    Vector3 Vector3::zero = Vector3(0, 0, 0);

    float Vector3::magnitude() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    float Vector3::magnitudeSqr() const
    {
        return x * x + y * y + z * z;
    }

    void Vector3::normalize()
    {
        (*this) *= 1 / this->magnitude();
    }

    Vector3 Vector3::normalized() const
    {
        Vector3 v = Vector3(x, y, z);
        v.normalize();
        return v;
    }

    void Vector3::scale(float scaler)
    {
        (*this) *= scaler;
    }

    // Getters
    float Vector3::MaxElement() const {
        return std::max(std::max(x, y), z);
    }

    // Operators
    // Adition
    // Vector-Vector addition
    Vector3 Vector3::operator+(Vector3 &v) const
    {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    void Vector3::operator+=(Vector3 &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    // Vector-Scaler addition
    Vector3 Vector3::operator+(float scaler) const
    {
        return Vector3(x + scaler, y + scaler, z + scaler);
    }

    void Vector3::operator+=(float scaler)
    {
        x += scaler;
        y += scaler;
        z += scaler;
    }

    // Subtraction
    // Vector-Vector subtraction
    Vector3 Vector3::operator-(Vector3 &v) const
    {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    void Vector3::operator-=(Vector3 &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    // Vector-Scaler subtraction
    Vector3 Vector3::operator-(float scaler) const
    {
        return Vector3(x - scaler, y - scaler, z - scaler);
    }

    void Vector3::operator-=(float scaler)
    {
        x -= scaler;
        y -= scaler;
        z -= scaler;
    }

    // Multiplicaition
    // Vector-Vector multiplication
    float Vector3::operator*(Vector3 &v) const
    {
        Vector3 _v = Vector3(this->x, this->y, this->y);
        return Vector3::dot(_v, v);
    }

    // Vector-Scaler multiplication
    Vector3 Vector3::operator*(float scaler) const
    {
        return Vector3(x * scaler, y * scaler, z * scaler);
    }

    void Vector3::operator*=(float scaler)
    {
        x *= scaler;
        y *= scaler;
        z *= scaler;
    }

    float Vector3::distance(Vector3 &v1, Vector3 &v2)
    {
        float dist = 0;

        float xDist = v2.x - v1.x;
        float yDist = v2.y - v1.y;
        float zDist = v2.z - v1.z;

        return sqrt(xDist * xDist + yDist * yDist + zDist * zDist);
    }

    float Vector3::distanceSqr(Vector3 &v1, Vector3 &v2)
    {
        float dist = 0;

        float xDist = v2.x - v1.x;
        float yDist = v2.y - v1.y;
        float zDist = v2.z - v1.z;

        return xDist * xDist + yDist * yDist + zDist * zDist;
    }

    float Vector3::dot(Vector3 &v1, Vector3 &v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    Vector3 Vector3::cross(Vector3 &v1, Vector3 &v2)
    {
        float x = v1.y * v2.z - v1.z * v2.y;
        float y = v1.x * v2.z - v1.z * v2.x;
        float z = v1.x * v2.y - v1.y * v2.x;

        return Vector3(x, y, z);
    }

    Vector3 Vector3::MaxVAL(Vector3 &v1, Vector3 &v2)
    {
        return Vector3(
            std::max(v1.x, v2.x),
            std::max(v1.y, v2.y),
            std::max(v1.z, v2.z));
    }

    // Other utility functions
    void Vector3::rotate(const Vector3 &v)
    {
        // X-Rotarion
        y = cos(v.x * M_PI / 180) * y - sin(v.x * M_PI / 180) * z;
        z = sin(v.x * M_PI / 180) * y + cos(v.x * M_PI / 180) * z;

        // Y-Rotarion
        x = cos(v.y * M_PI / 180) * x - sin(v.y * M_PI / 180) * z;
        z = sin(v.y * M_PI / 180) * x + cos(v.y * M_PI / 180) * z;

        // Z-Rotarion
        x = cos(v.z * M_PI / 180) * x - sin(v.z * M_PI / 180) * y;
        y = sin(v.z * M_PI / 180) * x + cos(v.z * M_PI / 180) * y;
    }

    Vector3Struct Vector3::Structure() const {
        return Vector3Struct(x, y, z);
    }

    std::ostream &operator<<(std::ostream &dout, Vector3 &v)
    {
        dout << "<Vector3>: " << v.x << "i ";

        if (v.y < 0)
            dout << "- ";
        else
            dout << "+ ";

        dout << abs(v.y) << "j ";

        if (v.z < 0)
            dout << "- ";
        else
            dout << "+ ";

        dout << abs(v.z) << "k";

        return dout;
    }
};
