#include "Globals.h"
#include "Application.h"
#include "ModuleMap.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleMap::ModuleMap(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleMap::~ModuleMap()
{}

// Load assets
bool ModuleMap::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	Cube A;
	A.size = { 5, 15, 2 };
	A.color = White;
	A.SetPos(0, 2, 10);
	A.SetRotation(60, {1, 0, 0});
	App->physics->AddBody(A, 0.f);
	map_objects.add(&A);

	return ret;
}

// Load assets
bool ModuleMap::CleanUp()
{
	LOG("Unloading Intro scene");
	map_objects.clear();
	return true;
}

// Update
update_status ModuleMap::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	//p2List_item<Primitive*>* item = map_objects.getFirst();

	//while (item)
	//{
	//	item->data->Render();
	//	item = item->next;
	//}

	return UPDATE_CONTINUE;
}

void ModuleMap::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

