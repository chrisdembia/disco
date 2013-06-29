
class Joint : public fwk::NamedInterface
{
public:

    Joint(XMLFile serialization);

    RigidBody rigidbody(string name) const;
    Frame body
};
