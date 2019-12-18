#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
	rotating = false;
	current_angle = 0;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Grey;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	chassis.color = Purple;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());
	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();

	Cube a(0.5, 0.8,0.8);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&a.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 a_offset = {0, 2, 1.2 };
	a_offset = a_offset.rotate(q.getAxis(), q.getAngle());
	a.transform.M[12] += a_offset.getX();
	a.transform.M[13] += a_offset.getY();
	a.transform.M[14] += a_offset.getZ();
	a.color = Grey;

	Cube b(1.4, 1.5,1.5);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&b.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 b_offset = {0, 2, -0.2 };
	b_offset = b_offset.rotate(q.getAxis(), q.getAngle());
	b.transform.M[13] += b_offset.getY();
	b.transform.M[14] += b_offset.getZ();
	b.transform.M[12] += b_offset.getX();
	b.color = White;	
	
	Cube c(1.4, 1.5,1.5);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&b.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 c_offset = {0, 2, -0.2 };
	c_offset = c_offset.rotate(q.getAxis(), q.getAngle());
	c.transform.M[13] += c_offset.getY();
	c.transform.M[14] += c_offset.getZ();
	c.transform.M[12] += c_offset.getX();
	c.color = White;





	a.Render();
	b.Render();
	chassis.Render();
}

//Cube PhysVehicle3D::CreateCarPart(){

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}

void PhysVehicle3D::SmoothRotation(float target, vec3 s_axis) 
{
	rotating = true;
	target_angle = target;
	axis = s_axis;
}