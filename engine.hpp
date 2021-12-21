#if !defined(PHYSICS_ENGINE)
#define PHYSICS_ENGINE

#include <iostream>
#include "./vectors/vectors.hpp"

#include "./Collidors/boxCollidor.hpp"
#include "./Collidors/sphereCollidor.hpp"
#include "./Collidors/collisionFunctions.hpp"

#include "./RigidBody/rigidbody.hpp"
#include "./RigidBody/rigidbodyWorld.hpp"

#define ENGINE_NAME PhysicsEngine

class ENGINE_NAME {
    public:
        // static 
};

#endif // PHYSICS_ENGINE
