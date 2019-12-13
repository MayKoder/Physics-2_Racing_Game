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
		//Height 3 - Map start
	CreateRectangle({ 7,1,0 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 7,1,3 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ 7,1,6 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 7,1,9 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ 7,1,12 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 7,1,15 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ 7,1,18 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 6,1,21 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ 5,1,24 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 4,1,27 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ 3,1,30 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 3,1,33 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ 3,1,36 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	//Height 9 - Beginning of starting ramps
	CreateRectangle({ 3,1,39 }, { 0,0,0,1 }, { 1,9.f,1 }, Green);
	CreateRectangle({ 3,1,42 }, { 0,0,0,1 }, { 1,9.f,1 }, Yellow);
	CreateRectangle({ 3,1,45 }, { 0,0,0,1 }, { 1,9.f,1 }, Green);
	CreateRectangle({ 3,1,48 }, { 0,0,0,1 }, { 1,9.f,1 }, Yellow);
	//Height 13 - Starting ramps
	CreateRectangle({ 3,1,51 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ 3,1,54 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ 3,1,57 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ 3,1,60 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ 3,1,63 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ 3,1,66 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ 3,1,69 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ 3,1,72 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ 3,1,75 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ 3,1,78 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ 3,1,81 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ 3,1,84 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ 3,1,87 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ 3,1,90 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	//Height 6 - End of starting ramps
	CreateRectangle({ 3,1,93 }, { 0,0,0,1 }, { 1,6.f,1 }, Green);
	CreateRectangle({ 3,1,96 }, { 0,0,0,1 }, { 1,6.f,1 }, Yellow);
	CreateRectangle({ 3,1,99 }, { 0,0,0,1 }, { 1,6.f,1 }, Green);
	CreateRectangle({ 3,1,102 }, { 0,0,0,1 }, { 1,6.f,1 }, Yellow);
	CreateRectangle({ 3,1,105 }, { 0,0,0,1 }, { 1,6.f,1 }, Green);
	//Height 3 - First curve firs half
	CreateRectangle({ 4,1,108 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 5,1,111 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 6,1,114 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 7,1,117 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 8,1,120 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 9,1,123 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 10,1,126 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 10,1,129 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 10,1,132 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 10,1,135 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 9,1,137 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 8,1,139 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 7,1,141 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 6,1,143 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 5,1,145 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ 4,1,147 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ 3,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	//First curve second half
	CreateRectangle({ 1,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -1,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -3,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -5,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -7,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -9,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -11,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -13,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -15,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -17,1,149 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -18,1,147 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -19,1,145 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -20,1,143 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -21,1,141 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -22,1,139 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -23,1,137 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -24,1,135 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -25,1,132 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -25,1,129 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -25,1,126 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -24,1,123 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -23,1,120 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -22,1,117 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -21,1,114 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -20,1,111 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -19,1,108 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -18,1,105 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -17,1,102 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -16,1,99 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -17,1,97 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -18,1,95 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -20,1,95 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -22,1,95 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -24,1,95 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -25,1,97 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -26,1,99 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -25,1,102 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -24,1,105 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -23,1,108 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -22,1,111 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	//Second curve ------------------------------------------------
	CreateRectangle({ -26,1,128 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -27,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -28,1,132 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -29,1,134 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -30,1,136 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -31,1,138 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -32,1,140 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -33,1,142 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -34,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -36,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -38,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -40,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -42,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -44,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -47,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -50,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -53,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -56,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -59,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -62,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -65,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -68,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -71,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -74,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -77,1,144 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);

	//Right side limits ------------------------------------------------------------------------------------------------------
	CreateRectangle({ -7,1,0 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -7,1,3 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ -7,1,6 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -7,1,9 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ -7,1,12 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -7,1,15 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ -7,1,18 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -6,1,21 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ -5,1,24 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -4,1,27 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ -3,1,30 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -3,1,33 }, { 0,0,0,1 }, { 1,3.f,1 }, Green);
	CreateRectangle({ -3,1,36 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	//Height 9
	CreateRectangle({ -3,1,39 }, { 0,0,0,1 }, { 1,9.f,1 }, Green);
	CreateRectangle({ -3,1,42 }, { 0,0,0,1 }, { 1,9.f,1 }, Yellow);
	CreateRectangle({ -3,1,45 }, { 0,0,0,1 }, { 1,9.f,1 }, Green);
	CreateRectangle({ -3,1,48 }, { 0,0,0,1 }, { 1,9.f,1 }, Yellow);
	CreateRectangle({ -3,1,51 }, { 0,0,0,1 }, { 1,9.f,1 }, Green);
	CreateRectangle({ -3,1,54 }, { 0,0,0,1 }, { 1,9.f,1 }, Yellow);
	CreateRectangle({ -3,1,57 }, { 0,0,0,1 }, { 1,9.f,1 }, Green);
	CreateRectangle({ -3,1,60 }, { 0,0,0,1 }, { 1,9.f,1 }, Yellow);
	CreateRectangle({ -3,1,63 }, { 0,0,0,1 }, { 1,9.f,1 }, Green);
	CreateRectangle({ -3,1,66 }, { 0,0,0,1 }, { 1,9.f,1 }, Yellow);
	CreateRectangle({ -3,1,69 }, { 0,0,0,1 }, { 1,9.f,1 }, Green);
	//Height 13
	CreateRectangle({ -3,1,51 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ -3,1,54 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ -3,1,57 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ -3,1,60 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ -3,1,63 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ -3,1,66 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ -3,1,69 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ -3,1,72 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ -3,1,75 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ -3,1,78 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ -3,1,81 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ -3,1,84 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	CreateRectangle({ -3,1,87 }, { 0,0,0,1 }, { 1,13.f,1 }, Green);
	CreateRectangle({ -3,1,90 }, { 0,0,0,1 }, { 1,13.f,1 }, Yellow);
	//Height 6 - End of starting ramps
	CreateRectangle({ -3,1,93 }, { 0,0,0,1 }, { 1,6.f,1 }, Green);
	CreateRectangle({ -3,1,96 }, { 0,0,0,1 }, { 1,6.f,1 }, Yellow);
	CreateRectangle({ -3,1,99 }, { 0,0,0,1 }, { 1,6.f,1 }, Green);
	CreateRectangle({ -3,1,102 }, { 0,0,0,1 }, { 1,6.f,1 }, Yellow);
	CreateRectangle({ -3,1,105 }, { 0,0,0,1 }, { 1,6.f,1 }, Green);
	//First curve -------------------------------------------------
	CreateRectangle({ -4,1,108 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -5,1,111 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -6,1,114 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -6,1,117 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -5,1,120 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -4,1,123 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,1,126 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -3,1,129 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -3,1,132 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -4,1,134 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -6,1,136 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -8,1,136 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -10,1,136 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -11,1,134 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -12,1,132 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -12,1,129 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -11,1,126 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -10,1,123 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -9,1,120 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -8,1,117 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	//Second curve ------------------------------------------------
	//Second curve first half
	CreateRectangle({ -4,1,93 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -5,1,91 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -6,1,89 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -7,1,87 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -8,1,85 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -9,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	//Second curve mid
	CreateRectangle({ -11,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -13,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -15,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -17,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -19,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -21,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -23,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -25,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -27,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -29,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -31,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -33,1,83 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	//Second curve second half
	CreateRectangle({ -34,1,85 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -35,1,87 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -36,1,89 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -37,1,91 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -38,1,93 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -39,1,96 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -39,1,99 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -39,1,101 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -38,1,103 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -37,1,105 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -36,1,107 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -35,1,109 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -35,1,112 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -35,1,115 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -35,1,118 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -36,1,120 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -37,1,122 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -38,1,124 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -39,1,126 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -40,1,128 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -42,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -44,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -47,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -50,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -53,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -56,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -59,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -62,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -65,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -68,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -71,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, White);
	CreateRectangle({ -74,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, Red);
	CreateRectangle({ -77,1,130 }, { 0,0,0,1 }, { 1,3.f,1 }, White);

	//First floor ramps
	CreateRectangle({ 0, 1, 30 }, { 70, 1, 0, 0 }, { 5, 15, 0.2f }, Yellow);
	CreateRectangle({ 0, 1, 49 }, { 0, 1, 0, 0 }, { 5, 5, 8.f }, White);
	CreateRectangle({ 0, 4, 60 }, { 80, 1, 0, 0 }, { 5, 15, 0.2f }, White);
	CreateRectangle({ 0, 2, 82 }, { -85, 1, 0, 0 }, { 5, 42, 0.2f }, White);
	//Last ramp
	CreateRectangle({ -77,1,137 }, { 70,1,0,0 }, { 16,16,0.2f }, Blue);


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


