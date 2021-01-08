#pragma once

#include "Camera.h"
#include "SDL2/SDL.h"
#include "ECS/TransformComponent.h"
#include "Game.h"

// its ok that target is uninitialized because we will set it before the first update()
Camera::Camera(int x, int y, int w, int h)
{
    cam = { x, y, w, h };
    panSpeed = 0.04;
}

void Camera::centerOnEntity(Entity* e)
{
	target = e;
}

int Camera::xPosition()
{
    return cam.x;
}

int Camera::yPosition()
{
    return cam.y;
}

void Camera::update()
{
    if (target == nullptr)
    {
        throw std::runtime_error("target of Camera is nullptr!!!");
    }

    TransformComponent targetTransform = target->getComponent<TransformComponent>();
    int targetCenterX = targetTransform.position.x + (targetTransform.width / 2);
    int targetCenterY = targetTransform.position.y + (targetTransform.height / 2);

    int targetX = targetCenterX - (CONSTANTS_GAME_WINDOW_WIDTH / 2);
    int targetY = targetCenterY - (CONSTANTS_GAME_WINDOW_HEIGHT / 2);

    if (cam.x != targetX)
    {
        cam.x = cam.x + ((static_cast<int>(targetX - cam.x)) * panSpeed);
    }

    if (cam.y != targetY)
    {
        cam.y = cam.y + ((static_cast<int>(targetY) - cam.y) * panSpeed);
    }

    if (cam.x < 0)
    {
        cam.x = 0;
    }

    if (cam.y < 0)
    {
        cam.y = 0;
    }

    int endOfMapHorizontal = (World::mapWidth - cam.w) + 1;
    if (cam.x > endOfMapHorizontal)
    {
        cam.x = endOfMapHorizontal;
    }

    int endOfMapVertical = (World::mapHeight - cam.h) + 1;
    if (cam.y > endOfMapVertical)
    {
        cam.y = endOfMapVertical;
    }
}
