
namespace disco
{

class System
{
public:

    System(XMLFile serialization);

    RigidBody rigidbody(string name) const;
        
    void step();
    void integrator();

private:
};
};
