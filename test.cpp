#include <iostream>
#include <cmath>

#include "engine.hpp"

using namespace std;
using namespace vectors;

int main() {
    SphereCollidor* sp = new SphereCollidor(Vector3::zero, 1);

    RigidBody_World* world = new RigidBody_World();
    RigidBody* rb = new RigidBody(Vector3::zero, sp);

    Vector3 force = Vector3(1, 0, 0);

    rb->ApplyForce(force);

    float dt = 0.1;
    float i = 0;
    while (i < 1) {
        rb->Update(dt);
        i += dt;
    }

    cout << endl << (*rb) << endl;

    return 0;
}
