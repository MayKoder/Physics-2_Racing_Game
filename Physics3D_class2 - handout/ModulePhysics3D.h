#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2List.h"
#include "Primitive.h"

// TODO 1: Add Bullet common include btBulletDynamicsCommon.h
#include"Bullet/include/btBulletDynamicsCommon.h"

#define GRAVITY_Y -10.f
#define GRAVITY_X 0.f
#define GRAVITY_Z 0.f

class DebugDrawer;

class ModulePhysics3D : public Module
{
public:
	ModulePhysics3D(Application* app, bool start_enabled = true);
	~ModulePhysics3D();

	bool Start();
	update_status PreUpdate(float dt);
	update_status Update(float dt);
	update_status PostUpdate(float dt);
	bool CleanUp();

private:

	bool debug;
	btDiscreteDynamicsWorld* world;

	//World settings
	btCollisionDispatcher* BTdispatcher;
	btDbvtBroadphase* BTinterface;
	btSequentialImpulseConstraintSolver* BTsolver;
	btDefaultCollisionConfiguration* BTcollisionConfig;


	DebugDrawer* debug_draw;
	btRigidBody* rectangle;

};

//TODO 4: Uncomment the declaration of the Debug Drawer

class DebugDrawer : public btIDebugDraw
{
public:
	DebugDrawer() : line(0,0,0)
	{}

	void drawLine(const btVector3& from, const btVector3& to, const btVector3& color);
	void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color);
	void reportErrorWarning(const char* warningString);
	void draw3dText(const btVector3& location, const char* textString);
	void setDebugMode(int debugMode);
	int	 getDebugMode() const;

	DebugDrawModes mode;
	Line line;
	Primitive point;
};
