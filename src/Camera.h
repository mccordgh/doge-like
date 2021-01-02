#pragma once

#include "ECS/ECS.h"
#include "SDL2/SDL.h"

class Camera
{
public:
	Camera(int x, int y, int w, int h);

	void centerOnEntity(Entity* e);
	void update();

	int xPosition();
	int yPosition();

private:
	Entity* target;
	SDL_Rect cam;

	float panSpeed;
};