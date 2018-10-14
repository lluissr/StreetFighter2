#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"


ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 8;
	ground.y = 377;
	ground.w = 848;
	ground.h = 63;

	background.x = 119;
	background.y = 127;
	background.w = 674;
	background.h = 199;

	ceiling.x = 93;
	ceiling.y = 8;
	ceiling.w = 763;
	ceiling.h = 48;

	bath.x = 164;
	bath.y = 66;
	bath.w = 336;
	bath.h = 51;

	bucket.x = 542;
	bucket.y = 85;
	bucket.w = 31;
	bucket.h = 25;
}


ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading honda scene");

	graphics = App->textures->Load("honda_stage2.png");

	App->player->Enable();
	
	App->audio->PlayMusic("honda.ogg");

	return true;
}

// UnLoad assets
bool ModuleSceneHonda::CleanUp()
{
	LOG("Unloading honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneHonda::Update()
{
	App->renderer->Blit(graphics, 0, 170, &ground);
	App->renderer->Blit(graphics, 0, 0, &background, 0.5f);
	App->renderer->Blit(graphics, 0, 0, &ceiling);
	App->renderer->Blit(graphics, 250, 135, &bath);
	App->renderer->Blit(graphics, 200, 160, &bucket);

	return UPDATE_CONTINUE;
}