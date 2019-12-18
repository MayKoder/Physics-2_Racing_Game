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
	chassis.color = Red;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());
	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();

	Cube m(1.8f,0.6,1.5f);
	m.color = Red;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&m.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 m_offset(0, 1.25f,2.1f );
	m_offset = m_offset.rotate(q.getAxis(), q.getAngle());
	m.transform.M[12] += m_offset.getX();
	m.transform.M[13] += m_offset.getY();
	m.transform.M[14] += m_offset.getZ();

	Cube a(0.5, 0.8,0.8);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&a.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 a_offset = {0, 2, 1.2 };
	a_offset = a_offset.rotate(q.getAxis(), q.getAngle());
	a.transform.M[12] += a_offset.getX();
	a.transform.M[13] += a_offset.getY();
	a.transform.M[14] += a_offset.getZ();
	a.color = Grey;

	Cube z(0.25f, 0.4f, 0.4f);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&z.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 z_offset = { 0.5f, 1.4f, 2.4f };
	z_offset = z_offset.rotate(q.getAxis(), q.getAngle());
	z.transform.M[12] += z_offset.getX();
	z.transform.M[13] += z_offset.getY();
	z.transform.M[14] += z_offset.getZ();
	z.color = Grey;

	Cube w(0.25f, 0.4f, 0.4f);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&w.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 w_offset = { -0.5f, 1.4f, 2.4f };
	w_offset = w_offset.rotate(q.getAxis(), q.getAngle());
	w.transform.M[12] += w_offset.getX();
	w.transform.M[13] += w_offset.getY();
	w.transform.M[14] += w_offset.getZ();
	w.color = Grey;


	Cube b(1.4, 1,1.5);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&b.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 b_offset = {0, 2, -0.2 };
	b_offset = b_offset.rotate(q.getAxis(), q.getAngle());
	b.transform.M[13] += b_offset.getY();
	b.transform.M[14] += b_offset.getZ();
	b.transform.M[12] += b_offset.getX();
	b.color = White;	
	
	Cube c(0.1, 0.3,.3);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&c.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 c_offset = {.6, 2.2, -1.5 };
	c_offset = c_offset.rotate(q.getAxis(), q.getAngle());
	c.transform.M[13] += c_offset.getY();
	c.transform.M[14] += c_offset.getZ();
	c.transform.M[12] += c_offset.getX();
	c.color = Yellow;

	Cube d(0.1, 0.3,.3);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&d.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 d_offset = {-.6, 2.2, -1.5 };
	d_offset = d_offset.rotate(q.getAxis(), q.getAngle());
	d.transform.M[13] += d_offset.getY();
	d.transform.M[14] += d_offset.getZ();
	d.transform.M[12] += d_offset.getX();
	d.color = Yellow;

	Cube e(2, 0.07,.5);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&e.transform);
	q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 e_offset = {0, 2.35, -1.5 };
	e_offset = e_offset.rotate(q.getAxis(), q.getAngle());
	e.transform.M[13] += e_offset.getY();
	e.transform.M[14] += e_offset.getZ();
	e.transform.M[12] += e_offset.getX();
	e.color = Yellow;





	a.Render();
	z.Render();
	w.Render();
	b.Render();
	c.Render();
	d.Render();
	e.Render();
	m.Render();
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