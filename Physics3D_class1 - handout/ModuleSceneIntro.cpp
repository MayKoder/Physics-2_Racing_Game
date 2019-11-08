#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"


ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	world_plane = new Plane(0.f, 1.f, 0.f, 1.f);
	world_plane->axis = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center
	App->camera->Move({2, 5, 2});
	App->camera->LookAt({ 0, 0, 0 });



	Cube* cube1 = new Cube();
	Sphere* sphere1 = new Sphere();
	sphere1->wire = true;

	//cube1->wire = true;
	cube1->SetPos(0, cube1->size.y / 2, 0);
	cube1->color = Blue;
	sphere1->SetPos(2, sphere1->radius, 0);


	world_objects.add(cube1);
	world_objects.add(sphere1);




	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");


	p2List_item<Primitive*>* item = world_objects.getFirst();

	while (item)
	{
		delete item->data;
		item = item->next;
	}


	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference

	world_plane->Render();


	p2List_item<Primitive*>* item = world_objects.getFirst();

	while (item)
	{
		c += 1;
		item->data->transform.rotate(c, {1, 1, 1});
		item->data->Render();
		item = item->next;
	}



	if (App->input->GetMouseButton(SDL_BUTTON_RIGHT) == KEY_REPEAT)
		App->camera->LookAt({ 0, 0, 0 });

	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe

	return UPDATE_CONTINUE;
}

