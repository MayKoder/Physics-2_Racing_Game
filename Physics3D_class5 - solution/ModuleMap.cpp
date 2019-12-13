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

	//Create map
	//CreateSensor({ 0, 2, 20 }, {0, 0, 1, 0}, { 5, 15, 0.2f }, White);
	//Create map
	//Left side limits ------------------------------------------------------------------------------------------------------
	//Height 3 - Map start
	CreateCylinder({ 7,1,0 }, { 90,0,0,1 }, 0.5f, 3.f, Yellow);
	CreateCylinder({ 7,1,3 }, { 90,0,0,1 }, 0.5f, 3.f, Black);
	CreateCylinder({ 7,1,6 }, { 90,0,0,1 }, 0.5f, 3.f, Yellow);
	CreateCylinder({ 7,1,9 }, { 90,0,0,1 }, 0.5f, 3.f, Black);
	CreateCylinder({ 7,1,12 }, { 90,0,0,1 }, 0.5f, 3.f, Yellow);
	CreateCylinder({ 7,1,15 }, { 90,0,0,1 }, 0.5f, 3.f, Black);
	CreateCylinder({ 7,1,18 }, { 90,0,0,1 }, 0.5f, 3.f, Yellow);
	CreateCylinder({ 6,1,21 }, { 90,0,0,1 }, 0.5f, 3.f, Black);
	CreateCylinder({ 5,1,24 }, { 90,0,0,1 }, 0.5f, 3.f, Yellow);
	CreateCylinder({ 4,1,27 }, { 90,0,0,1 }, 0.5f, 3.f, Black);
	CreateCylinder({ 3,1,30 }, { 90,0,0,1 }, 0.5f, 3.f, Yellow);
	CreateCylinder({ 3,1,33 }, { 90,0,0,1 }, 0.5f, 3.f, Black);
	CreateCylinder({ 3,1,36 }, { 90,0,0,1 }, 0.5f, 3.f, Yellow);
	//Height 9 - Beginning of starting ramps
	CreateCylinder({ 3,1,39 }, { 90,0,0,1 }, 0.5f, 9.f, White);
	CreateCylinder({ 3,1,42 }, { 90,0,0,1 }, 0.5f, 9.f, White);
	CreateCylinder({ 3,1,45 }, { 90,0,0,1 }, 0.5f, 9.f, White);
	CreateCylinder({ 3,1,48 }, { 90,0,0,1 }, 0.5f, 9.f, White);
	//Height 13 - Starting ramps
	CreateCylinder({ 3,1,51 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,54 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,57 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,60 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,63 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,66 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,69 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,72 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,75 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,78 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,81 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,84 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,87 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ 3,1,90 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	//Height 6 - End of starting ramps
	CreateCylinder({ 3,1,93 }, { 90,0,0,1 }, 0.5f, 6.f, White);
	CreateCylinder({ 3,1,96 }, { 90,0,0,1 }, 0.5f, 6.f, White);
	CreateCylinder({ 3,1,99 }, { 90,0,0,1 }, 0.5f, 6.f, White);
	CreateCylinder({ 3,1,102 }, { 90,0,0,1 }, 0.5f, 6.f, White);
	CreateCylinder({ 3,1,105 }, { 90,0,0,1 }, 0.5f, 6.f, White);
	//Height 3 - First curve
	CreateCylinder({ 4,1,108 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 5,1,111 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 6,1,114 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 7,1,117 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 8,1,120 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 9,1,123 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 10,1,126 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 10,1,129 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 10,1,132 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 10,1,135 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 9,1,137 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 8,1,139 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 7,1,141 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 6,1,143 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 4,1,145 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 3,1,147 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ 1,1,147 }, { 90,0,0,1 }, 0.5f, 3.f, White);

	//Right side limits ------------------------------------------------------------------------------------------------------
	CreateCylinder({ -7,1,0 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -7,1,3 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -7,1,6 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -7,1,9 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -7,1,12 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -7,1,15 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -7,1,18 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -6,1,21 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -5,1,24 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -4,1,27 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -3,1,30 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -3,1,33 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -3,1,36 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	//Height 9
	CreateCylinder({ -3,1,39 }, { 90,0,0,1 }, 0.5f, 9.f, White);
	CreateCylinder({ -3,1,42 }, { 90,0,0,1 }, 0.5f, 9.f, White);
	CreateCylinder({ -3,1,45 }, { 90,0,0,1 }, 0.5f, 9.f, White);
	CreateCylinder({ -3,1,48 }, { 90,0,0,1 }, 0.5f, 9.f, White);
	CreateCylinder({ -3,1,51 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,54 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,57 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,60 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,63 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,66 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,69 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	//Height 13
	CreateCylinder({ -3,1,51 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,54 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,57 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,60 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,63 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,66 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	CreateCylinder({ -3,1,69 }, { 90,0,0,1 }, 0.5f, 13.f, White);
	//Height 6 - End of starting ramps
	CreateCylinder({ -3,1,93 }, { 90,0,0,1 }, 0.5f, 6.f, White);
	CreateCylinder({ -3,1,96 }, { 90,0,0,1 }, 0.5f, 6.f, White);
	CreateCylinder({ -3,1,99 }, { 90,0,0,1 }, 0.5f, 6.f, White);
	CreateCylinder({ -3,1,102 }, { 90,0,0,1 }, 0.5f, 6.f, White);
	CreateCylinder({ -3,1,105 }, { 90,0,0,1 }, 0.5f, 6.f, White);
	//Height 3 - First curve
	CreateCylinder({ -4,1,108 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -5,1,111 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -6,1,114 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -6,1,117 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -5,1,120 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -4,1,123 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -3,1,126 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -3,1,129 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -3,1,132 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -4,1,134 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -6,1,136 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -8,1,136 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -10,1,136 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -11,1,133 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -12,1,130 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	/*CreateCylinder({ -9,1,141 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -9,1,144 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -8,1,147 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -7,1,150 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -6,1,153 }, { 90,0,0,1 }, 0.5f, 3.f, White);
	CreateCylinder({ -5,1,156 }, { 90,0,0,1 }, 0.5f, 3.f, White);*/

	//First floor ramps
	CreateRectangle({ 0, 1, 30 }, { 70, 1, 0, 0 }, { 5, 15, 0.2f }, Yellow);
	CreateRectangle({ 0, 1, 49 }, { 0, 1, 0, 0 }, { 5, 5, 8.f }, White);
	CreateRectangle({ 0, 4, 60 }, { 80, 1, 0, 0 }, { 5, 15, 0.2f }, White);
	CreateRectangle({ 0, 2, 82 }, { -85, 1, 0, 0 }, { 5, 42, 0.2f }, White);


	CreateSensor({ 0, 2.5f, -10}, { 0, 0, 0, 1 }, { 10, 5, 0.2f }, White, GRAVITYMOD,{0, 10, 0});


	return ret;
}

// Load assets
bool ModuleMap::CleanUp()
{
	LOG("Unloading Intro scene");
	map_objects.clear();
	map_sensors.clear();
	return true;
}

// Update
update_status ModuleMap::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	p2List_item<Primitive*>* item = map_objects.getFirst();

	while (item)
	{
		item->data->Render();
		item = item->next;
	}


	return UPDATE_CONTINUE;
}

void ModuleMap::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

PhysBody3D* ModuleMap::CreateRectangle(vec3 position, vec4 rotation, vec3 size, Color s_color, float mass)
{

	Cube* object = new Cube();

	object->SetPos(position.x, position.y, position.z);
	object->size = size;
	object->color = s_color;
	object->SetRotation(rotation.x, { rotation.y, rotation.z, rotation.w });

	map_objects.add(object);
	return App->physics->AddBody(*object, mass);
}

void ModuleMap::CreateCylinder(vec3 position, vec4 rotation, float radius, float height, Color s_color, float mass)
{
	Cylinder* object = new Cylinder();


	
	object->SetPos(position.x, position.y, position.z);
	object->color = s_color;
	object->SetRotation(rotation.x, { rotation.y, rotation.z, rotation.w });

	object->height = height;
	object->radius = radius;

	App->physics->AddBody(*object, mass);
	map_objects.add(object);
}

void ModuleMap::CreateSensor(vec3 position, vec4 rotation, vec3 size, Color s_color, SensorType s_type,vec3 mod)
{

	Cube* object = new Cube();

	object->SetPos(position.x, position.y, position.z);
	object->size = size;
	object->color = s_color;
	object->SetRotation(rotation.x, { rotation.y, rotation.z, rotation.w });
	map_sensors.add(App->physics->AddSensor(*object, mod, s_type));

}


