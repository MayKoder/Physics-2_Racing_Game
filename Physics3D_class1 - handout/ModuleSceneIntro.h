#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include"p2List.h"

#define BOUNCER_TIME 200

struct PhysBody3D;
class Cube;
class Plane;
class Primitive;
class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

	Plane* world_plane = nullptr;

	p2List<Primitive*> world_objects;
	
	float c = 0;

public:
};
