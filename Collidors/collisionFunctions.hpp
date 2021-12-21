#if !defined(COLLISION_FUNCTIONS_HPP)
#define COLLISION_FUNCTIONS_HPP

#include "sphereCollidor.hpp"
#include "boxCollidor.hpp"

// Sphere
IntersectionData SphereCollidor::Collide(Collidor* otherCollidor) {
    if (otherCollidor == ((Collidor*)this)) {
        return IntersectionData(false, INFINITY);

    } else if (otherCollidor->CollidorType == Collidor::SphereCollidor_T) {
        SphereCollidor* castedCollidor = ((SphereCollidor*) otherCollidor);

        float distance = Vector3::distance(otherCollidor->Position, this->Position);
        float rTotal = castedCollidor->Radius + this->Radius;

        return IntersectionData(distance < rTotal, distance - rTotal);
    }

    return IntersectionData(false, INFINITY);
}

std::vector<IntersectionData> SphereCollidor::Collide(std::vector<Collidor*>& collidors) {
    std::vector<IntersectionData> r;

    for (int i = 0, j = 0; i < collidors.size(); i++, j++) {
        r.push_back(Collide(collidors[i]));
    }

    return r;
}

// Box
IntersectionData BoxCollidor::Collide(Collidor* otherCollidor) {
    if (otherCollidor == ((Collidor*)this)) {
        return IntersectionData(false, INFINITY);

    } else if (otherCollidor->CollidorType == Collidor::BoxCollidor_T) {
        BoxCollidor* castedCollidor = ((BoxCollidor*) otherCollidor);
        
        Vector3 d1 = castedCollidor->minExtent - this->maxExtent;
        Vector3 d2 = this->minExtent - castedCollidor->maxExtent;

        Vector3 max = Vector3::MaxVAL(d1, d2);
        float maxMag = max.MaxElement();

        return IntersectionData(maxMag < 0, maxMag);
    }

    return IntersectionData(false, INFINITY);
}

std::vector<IntersectionData> BoxCollidor::Collide(std::vector<Collidor*>& collidors) {
    std::vector<IntersectionData> r;

    for (int i = 0, j = 0; i < collidors.size(); i++, j++) {
        r.push_back(Collide(collidors[i]));
    }

    return r;
}

#endif // COLLISION_FUNCTIONS_HPP
