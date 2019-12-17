#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define MAX_BOOST_ACCELERATION 3000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status PreUpdate(float dt);
	update_status Update(float dt);
	bool CleanUp();

	void RespawnCar();
	void LastCheckPoint();
	void FinishGame();



public:

	PhysVehicle3D* vehicle;
	PhysSensor3D* lastCheckPoint;
	float turn;
	float acceleration;
	float brake;
	bool respawn;
	bool speed_bost;
	bool super_boost;
	bool game_finished;


	Cylinder* wheels[4];
	PhysBody3D* pb_wheels[4];
	Cube* cabin[4];
	PhysBody3D* pb_cabin[4];

private:
	float restart_timer;

};