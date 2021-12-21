#if !defined(COLLIDOR_BASE_HPP)
#define COLLIDOR_BASE_HPP

#include "../vectors/vectors.hpp"    // NOTE: Remove when imported in iData
using namespace vectors;

#include <vector>
#include "../intersectionData.hpp"

class Collidor {
    public:
        Vector3 Position;
        bool isTrigger = false;

        enum {
            BoxCollidor_T,
            SphereCollidor_T,
            PlaneCollidor_T
        } CollidorType;

        virtual IntersectionData Collide(Collidor*) = 0;
        virtual std::vector<IntersectionData> Collide(std::vector<Collidor*>&) = 0;
};

#endif // COLLIDOR_BASE_HPP
