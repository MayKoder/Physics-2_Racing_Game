#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;
struct PhysSensor3D;
enum SensorType;
class btHingeConstraint;

class ModuleMap : public Module
{
public:
	ModuleMap(Application* app, bool start_enabled = true);
	~ModuleMap();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	PhysBody3D* CreateRectangle(vec3, vec4, vec3, Color, float mass = 0.f);
	PhysBody3D* CreateCylinder(vec3, vec4, float, float, Color, float mass = 0.f);
	void CreateSensor(vec3, vec4, vec3, Color, SensorType, vec3, vec4 target_rotation = { 0, 0, 0, 1 });

	void FirstPhaseObjects();
	void SecondPhaseObjects();
	void ThirdPhaseObjects();
	void LastPhaseObjects();
	void CreateSensors();

	p2DynArray<Primitive*> obs_primitives;
	p2DynArray<PhysBody3D*> obs_bodys;
	btHingeConstraint* rotatingWheel;


public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	int winSound;
	int boostSound;
	int yaaySound;
	int deathSound;
	int sensorSound;

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;

	p2List<Primitive*> map_objects;
	p2List<PhysSensor3D*> map_sensors;
};
