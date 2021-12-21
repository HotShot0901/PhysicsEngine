#if !defined(RIGIDBODY)
#define RIGIDBODY

#include "../vectors/vectors.hpp"
#include "../Collidors/collidorBase.hpp"

class RigidBody {
    private:
        Vector3 Position;
        Vector3 Velocity;
        Vector3 Force;

        float mass;

        Collidor* collidor;
        bool isDynamic;

    public:
        RigidBody(Vector3& _position , Collidor* _collidor , float _mass=1, bool      _isDynamic=true) : 
                  Position{_position}, collidor {_collidor},  mass{_mass} , isDynamic{_isDynamic}      {}

        void ApplyForce(Vector3&);
        void Update(float);

        // Getters
        Vector3   GetPosition() const { return Position; }
        Vector3   GetVelocity() const { return Velocity; }
        Vector3   GetForce()    const { return Force;    }
        Vector3   GetMass()     const { return mass;     }
        Collidor* GetCollidor() const { return collidor; }

        friend std::ostream& operator << (std::ostream&, RigidBody&);
};

std::ostream& operator << (std::ostream& dout, RigidBody& collidor) {
    dout << "<RigidBody>" << std::endl
         << "Position : " << collidor.Position << std::endl
         << "Velocity : " << collidor.Velocity << std::endl
         << "Mass     : " << collidor.mass;

    return dout;
}


void RigidBody::ApplyForce(Vector3& _force) {
    Force = _force;
}

void RigidBody::Update(float dt) {
    if (!isDynamic) return;

    Force.scale(1 / mass);

    Velocity += Force;

    Position += (Velocity * dt);

    Force = Vector3::zero;
}

#endif // RIGIDBODY
