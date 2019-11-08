#include "Globals.h"
#include "Application.h"
#include "ModuleCamera3D.h"


ModuleCamera3D::ModuleCamera3D(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	CalculateViewMatrix();

	X = vec3(1.0f, 0.0f, 0.0f);
	Y = vec3(0.0f, 1.0f, 0.0f);
	Z = vec3(0.0f, 0.0f, 1.0f);

	Position = vec3(0.0f, 0.0f, 5.0f);
	Reference = vec3(0.0f, 0.0f, 0.0f);
}

ModuleCamera3D::~ModuleCamera3D()
{}

// -----------------------------------------------------------------
bool ModuleCamera3D::Start()
{
	LOG("Setting up the camera");
	bool ret = true;

	return ret;
}

// -----------------------------------------------------------------
bool ModuleCamera3D::CleanUp()
{
	LOG("Cleaning camera");

	return true;
}

// -----------------------------------------------------------------
update_status ModuleCamera3D::Update()
{
	// OnKeys WASD keys -----------------------------------

	// TODO 3: Make the camera go up/down when pressing R (up) F(down)
	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_REPEAT) 
	{
		Position += Y * 0.1f;
		Reference += Y * 0.1f;
	}
	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_REPEAT)
	{
		Position -= Y * 0.1f;
		Reference -= Y * 0.1f;
	}

	// TODO 4: Make the camera go forward (w) and backward with (s)
	// Note that the vectors X/Y/Z contain the current axis of the camera
	// you can read them to modify Position
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		Position -= Z * 0.1f;
		Reference -= Z * 0.1f;
	}
	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		Position += Z * 0.1f;
		Reference += Z * 0.1f;
	}



	// TODO 5: Make the camera go left (a) and right with (d)
	// Note that the vectors X/Y/Z contain the current axis of the camera
	// you can read them to modify Position
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		Position += X * 0.1f;
		Reference += X * 0.1f;
	}
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		Position -= X * 0.1f;
		Reference -= X * 0.1f;
	}


	// Mouse motion ----------------
	if(App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_REPEAT)
	{
		int dx = -App->input->GetMouseXMotion();
		int dy = -App->input->GetMouseYMotion();

		LOG("%i, %i", dx, dy);
		


		vec3 new_Z = Z * -1;

		new_Z = rotate(new_Z, (float)dx / 5, Y);

		new_Z = rotate(new_Z, (float)dy / 5, X);

		new_Z += Position;

		LookAt(new_Z);


	}

	// Recalculate matrix -------------
	CalculateViewMatrix();

	return UPDATE_CONTINUE;
}

// -----------------------------------------------------------------
void ModuleCamera3D::Look(const vec3 &Position, const vec3 &Reference, bool RotateAroundReference)
{
	this->Position = Position;
	this->Reference = Reference;

	Z = normalize(Position - Reference);
	X = normalize(cross(vec3(0.0f, 1.0f, 0.0f), Z));
	Y = cross(Z, X);

	if(!RotateAroundReference)
	{
		this->Reference = this->Position;
		this->Position += Z * 0.05f;
	}

	CalculateViewMatrix();
}

// -----------------------------------------------------------------
void ModuleCamera3D::LookAt( const vec3 &Spot)
{
	Reference = Spot;

	Z = normalize(Position - Reference);
	X = normalize(cross(vec3(0.0f, 1.0f, 0.0f), Z));
	Y = cross(Z, X);

	CalculateViewMatrix();
}


// -----------------------------------------------------------------
void ModuleCamera3D::Move(const vec3 &Movement)
{
	Position += Movement;
	Reference += Movement;

	CalculateViewMatrix();
}

// -----------------------------------------------------------------
float* ModuleCamera3D::GetViewMatrix()
{
	return &ViewMatrix;
}

// -----------------------------------------------------------------
void ModuleCamera3D::CalculateViewMatrix()
{
	ViewMatrix = mat4x4(X.x, Y.x, Z.x, 0.0f, X.y, Y.y, Z.y, 0.0f, X.z, Y.z, Z.z, 0.0f, -dot(X, Position), -dot(Y, Position), -dot(Z, Position), 1.0f);
	ViewMatrixInverse = inverse(ViewMatrix);
}
