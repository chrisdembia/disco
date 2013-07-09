
// TODO

#include <disco.h>

int main()
{

    System::Ptr sys = new System();
    Frame::Ptr inertial = sys.inertial_frame();

    // Connectivity.
    // ------------
    Frame::Ptr translate = sys.frame_new("translate");
    Frame::Ptr yaw = translate.frame_new("yaw");
    Frame::Ptr roll = translate.frame_new("roll");
    RigidBody::Ptr rear_wheel = roll.rigid_body_new("rear_wheel");
    RigidBody::Ptr frame = rear_wheel.rigid_body_new("rear_frame");
    RigidBody::Ptr fork = frame.rigid_body_new("fork");
    RigidBody::Ptr front_wheel = fork.rigid_body_new("front_wheel");

    // TODO can't do rolling joint, because that means you know the geometry of
    // the surface you're rolling on.
    // TODO can take care of that with a constraint though.
    rear_wheel.joint_is(new RollingJoint(TODO));
    frame.joint_is(new RevoluteJoint("pitch"),
            Transform::rotateZ(90 * degrees));
    fork.joint_is(new RevoluteJoint("steer"));
    front_wheel.joint_is(new RevoluteJoint("q5"));

    PositionConstraint::Ptr front_wheel_contact = 

    // TODO this API does not permit loops in general.

    // TODO inertial.joint_is


    RigidBody::Ptr rear_wheel = sys.rigid_body_new("rear_wheel");
    RigidBody::Ptr frame = sys.rigid_body_new("rear_frame");
    RigidBody::Ptr fork = sys.rigid_body_new("fork");
    RigidBody::Ptr front_wheel = sys.rigid_body_new("front_wheel");

    rear_wheel.mass_is(1.2 * kilograms);
    rear_wheel.inertia_is(
            Inertia<rear_wheel>::Cylinder(1.5 * meters, 2.0 * meters));
    rear_wheel.center_of_mass_is(
            Position<rear_wheel>(1.5 * meters, 0 * meters, 0 * meters));

    RevoluteJoint::Ptr 
// TODO    RevoluteJoint(










    return EXIT_SUCCESS;
}
