#if !defined(SPHERE_COLLIDOR_HPP)
#define SPHERE_COLLIDOR_HPP

#include "collidorBase.hpp"
#include <iterator>

class SphereCollidor : public Collidor {
    public:
        float Radius;

        SphereCollidor(Vector3 _position, float _radius) : Radius{_radius} {
            Position = _position;
            CollidorType = Collidor::SphereCollidor_T;
        }

        SphereCollidor(Vector3 _position, float _radius, bool _isTrigger) : Radius{_radius} {
            Position = _position;
            CollidorType = Collidor::SphereCollidor_T;
        }

        SphereCollidor(SphereCollidor& other) : Radius{other.Radius} {
            Position = other.Position;
            CollidorType = Collidor::SphereCollidor_T;

            isTrigger = other.isTrigger;
        }

        virtual IntersectionData Collide(Collidor*) override;
        virtual std::vector<IntersectionData> Collide(std::vector<Collidor*>&) override;
        friend std::ostream& operator << (std::ostream&, SphereCollidor&);
};

std::ostream& operator << (std::ostream& dout, SphereCollidor& collidor) {
    dout << "<SphereCollidor>" << std::endl
         << "Position : " << collidor.Position << std::endl
         << "Radius   : " << collidor.Radius;

    return dout;
}

#endif // SPHERE_COLLIDOR_HPP
