#include <disco/disco.h>

int main()
{
    System::Ptr sys = System("double pendulum");

    RigidBody::Ptr link1 = sys.rigid_body_new("link1");
    RigidBody::Ptr link2 = sys.rigid_body_new("link2");

    Length L = 1 * meter;
    link1.joint_is(new RevoluteJoint("theta1",
                Transform(),
                Transform()));
    link2.joint_is(new RevoluteJoint("theta2",
                Transform::translationZ(L1),
                Transform()));

    link1.mass_is(1 * kilogram);
    link2.mass_is(1 * kilogram);

    link1.center_of_mass_is(Position<link1>(0.5 * L, 0, 0));

//    link1.center_of_mass_from_origin_is(Position


    sys.state()["theta1"] = 1.57;



    N = sys.newtonianFrame();
    RigidBody::Ptr link1 = sys.bodyNew("link1");

    Meters diameter(1.0);
    Meters length(1.0);
    CylinderBody::Ptr link1 = CylinderBody("link1", Kilograms(1.0), diameter,
            length);
    CylinderBody::Ptr link2 = CylinderBody("link2", Kilograms(1.0), diameter,
            length);


    link1.massIs(Kilograms(1.0));
    link1.centerOfMassIs(Position(N.origin(), Vector(0.0)));
    link1.inertiaTensorIs(
            CylinderInertiaTensor(Position(), Frame));

    link2.massIs(Kilograms(1.0));
    link2.centerOfMassIs(Position());

    sys.bodyNew(link1);
    sys.bodyNew(link2);

    // Can't use factory function here; b/c Joint will have subclasses.
    RevoluteJoint::Ptr groundLink1 = new RevoluteJoint("groundLink1",
            TODObaseBody,
            N,
            link1,
            link1.frame());

    RevoluteJoint::Ptr link1Link2 = new RevoluteJoint("link1Link2",
            link1,
            Frame(Position(link1.origin(), length * link1.frame().x()),
                EulerXYZ(link1.orientation(), 0, 0, 0)),
            link2,
            link2.frame());

    sys.jointNew(groundLink1); // TODO how come you don't need to do this in
    // OpenSim?
    sys.jointNew(link1Link2);

    // TODO something with states, to set initial state?
    Simulation::Ptr sim("sim1");
    sim.timeIs(Seconds(5.0));
    // TODO what is getting populated when this call is made? 
    // TODO where do the states live?


            Frame(Position(N.origin(), Vector(0.0)), EulerXYZ(0, 0, 0)),
            Frame(Position(link1.frame.origin()
            Position(N.origin(), Vector(0.0)),
            

    Fram

    This is NOT like MotionGenesis because here we define a system using joints.



    link1







    sys = System("double pendulum");
    N = sys.newtonianFrame();
    RigidBody::Ptr link1 = sys.bodyNew("link1");
    link1.jointIs(new RevoluteJoint());

    RigidBody::Ptr link2 = link1.bodyNew("link2");
    link2.jointIs(new RevoluteJoint());

    Meters diameter(1.0);
    Meters length(1.0);
    CylinderBody::Ptr link1 = CylinderBody("link1", Kilograms(1.0), diameter,
            length);
    CylinderBody::Ptr link2 = CylinderBody("link2", Kilograms(1.0), diameter,
            length);

