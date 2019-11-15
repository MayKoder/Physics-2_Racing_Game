#include "Globals.h"
#include "Application.h"
#include "ModulePhysics3D.h"
#include "Primitive.h"

// TODO 1: ...and the 3 libraries based on how we compile (Debug or Release)
// use the _DEBUG preprocessor define
#include"Bullet/include/btBulletDynamicsCommon.h"

#if _DEBUG

#pragma comment(lib, "Bullet/libx86/BulletCollision_debug.lib")
#pragma comment(lib, "Bullet/libx86/BulletDynamics_debug.lib")
#pragma comment(lib, "Bullet/libx86/LinearMath_debug.lib")

#else

#pragma comment(lib, "Bullet/libx86/BulletCollision.lib")
#pragma comment(lib, "Bullet/libx86/BulletDynamics.lib")
#pragma comment(lib, "Bullet/libx86/LinearMath.lib")

#pragma comment()

#endif // _DEBUG


ModulePhysics3D::ModulePhysics3D(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	debug_draw = NULL;
	debug = true;

	// TODO 2: Create collision configuration, dispacher
	// broad _phase and solver
	BTcollisionConfig = new btDefaultCollisionConfiguration();
	BTdispatcher = new btCollisionDispatcher(BTcollisionConfig);
	BTinterface = new btDbvtBroadphase();
	BTsolver = new btSequentialImpulseConstraintSolver();;

	//TODO 4: Uncomment the creation of the DebugDrawer
	debug_draw = new DebugDrawer();
}

// Destructor
ModulePhysics3D::~ModulePhysics3D()
{
	delete debug_draw;

	// TODO 2: and destroy them!
	delete BTdispatcher;
	delete BTinterface;
	delete BTsolver;
	delete BTcollisionConfig;

}

// ---------------------------------------------------------
bool ModulePhysics3D::Start()
{
	LOG("Creating Physics environment");

	// TODO 3: Create the world and set default gravity
	// Have gravity defined in a macro!
	world = new btDiscreteDynamicsWorld(BTdispatcher, BTinterface, BTsolver, BTcollisionConfig);
	btVector3 garvity = {GRAVITY_X, GRAVITY_Y , GRAVITY_Z };
	world->setGravity(garvity);

	//TODO 4: Uncomment and link the debug Drawer with our newly created Physics world
	 world->setDebugDrawer(debug_draw);

	{
		// TODO 6: Create a big rectangle as ground
		// Big rectangle as ground
		 btMotionState *motionState = new btDefaultMotionState();
		 btBoxShape *shape = new btBoxShape(btVector3(200.0f, 1.0f, 200.0f));
		 btRigidBody::btRigidBodyConstructionInfo rigidBodyInfo(/*mass*/0.0f, motionState, shape);
		 rectangle = new btRigidBody(rigidBodyInfo);
		 world->addRigidBody(rectangle);
	}
	{
		// TODO 6: Create a big rectangle as ground
		// Big rectangle as ground
		btMotionState *motionState = new btDefaultMotionState();
		btSphereShape *shape = new btSphereShape(1);
		btVector3 vec;
		shape->calculateLocalInertia(1, vec);
		btRigidBody::btRigidBodyConstructionInfo rigidBodyInfo(/*mass*/1.0f, motionState, shape, vec);
		rectangle = new btRigidBody(rigidBodyInfo);
		world->addRigidBody(rectangle);
	}




	return true;
}

// ---------------------------------------------------------
update_status ModulePhysics3D::PreUpdate(float dt)
{
	// TODO 5: step the world
	world->stepSimulation(dt);

	return UPDATE_CONTINUE;
}

// ---------------------------------------------------------
update_status ModulePhysics3D::Update(float dt)
{
	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if (App->input->GetKey(SDL_SCANCODE_B) == KEY_DOWN)
	{
		//rectangle->translate({0, 10, 0});
		rectangle->applyCentralForce({100, 500, 0});
		rectangle->activate();
	}

	if(debug == true)
	{
		//TODO 4: Uncomment the render of the debug render
		world->debugDrawWorld();
		
		if(App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
		{
			// TODO 7: Create a Solid Sphere when pressing 1 on camera position
		}
	}

	return UPDATE_CONTINUE;
}

// ---------------------------------------------------------
update_status ModulePhysics3D::PostUpdate(float dt)
{
	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePhysics3D::CleanUp()
{
	LOG("Destroying 3D Physics simulation");

	// TODO 3: ... and destroy the world here!
	world->removeRigidBody(rectangle);
	delete world;


	return true;
}

// =============================================
//TODO 4: Uncomment the definition of the Debug Drawer

void DebugDrawer::drawLine(const btVector3& from, const btVector3& to, const btVector3& color)
{
	line.origin.Set(from.getX(), from.getY(), from.getZ());
	line.destination.Set(to.getX(), to.getY(), to.getZ());
	line.color.Set(color.getX(), color.getY(), color.getZ());
	line.Render();
}

void DebugDrawer::drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color)
{
	point.transform.translate(PointOnB.getX(), PointOnB.getY(), PointOnB.getZ());
	point.color.Set(color.getX(), color.getY(), color.getZ());
	point.Render();
}

void DebugDrawer::reportErrorWarning(const char* warningString)
{
	LOG("Bullet warning: %s", warningString);
}

void DebugDrawer::draw3dText(const btVector3& location, const char* textString)
{
	LOG("Bullet draw text: %s", textString);
}

void DebugDrawer::setDebugMode(int debugMode)
{
	mode = (DebugDrawModes) debugMode;
}

int	 DebugDrawer::getDebugMode() const
{
	return mode;
}
