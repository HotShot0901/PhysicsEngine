#if !defined(VECTOR3_HPP)
#define VECTOR3_HPP

#include <cmath>
#include <iostream>

namespace vectors {
    struct Vector3Struct {
        public:
            float x, y, z;
            Vector3Struct(float, float, float);
        
    };

    class Vector3 {
        public:
            float x, y, z;

            // Identity Vectors
            static Vector3 xUnit;
            static Vector3 yUnit;
            static Vector3 zUnit;

            static Vector3 once;
            static Vector3 zero;

            Vector3(float i=0, float j=0, float k=0) : x{i}, y{j}, z{k} {}
            Vector3(Vector3Struct *v) { x=v->x; y=v->y; z=v->z; }

            float magnitude() const;
            float magnitudeSqr() const;
            void normalize();
            Vector3 normalized() const;
            void scale(float);


            // Getters
            float MaxElement() const;


            // Operators
            // Adition
            Vector3 operator + (Vector3&) const;
            void operator += (Vector3&);
            Vector3 operator + (float) const;
            void operator += (float);
            
            // Subtraction
            Vector3 operator - (Vector3&) const;
            void operator -= (Vector3&);
            Vector3 operator - (float) const;
            void operator -= (float);

            // Multiplicaition
            float operator * (Vector3&) const;
            Vector3 operator * (float) const;
            void operator *= (float);


            friend std::ostream& operator << (std::ostream&, Vector3&);

            // Static Vector utility functions
            static float distance(Vector3&, Vector3&);
            static float distanceSqr(Vector3&, Vector3&);
            static float dot(Vector3&, Vector3&);
            static Vector3 cross(Vector3&, Vector3&);
            static Vector3 MaxVAL(Vector3&, Vector3&);

            // Other utility functions
            void rotate(const Vector3& v);
            Vector3Struct Structure() const;
    };
};

#endif // VECTOR3_HPP
