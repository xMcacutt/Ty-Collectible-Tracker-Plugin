#include "pch.h"
#include "core.h"
#include "camera.h"
#include "hero.h"

CameraState Camera::getCameraState()
{
	return *(CameraState*)(Core::moduleBase + 0x27EBC8);
}

void Camera::setCameraState(CameraState state)
{
	*(CameraState*)(Core::moduleBase + 0x27EBC8) = state;
	*(CameraState*)(Core::moduleBase + 0x27EBD0) = state;
}

Vector3f Camera::getCameraPosition()
{
	return *(Vector3f*)(Core::moduleBase + 0x27EB78);
}

void Camera::setCameraPosition(Vector3f position)
{
	*(Vector3f*)(Core::moduleBase + 0x27EB78) = position;
}

Vector3f Camera::getCameraRotation()
{
	return *(Vector3f*)(Core::moduleBase + 0x27F2B4);
}

void Camera::setCameraRotation(Vector3f rotation)
{
	*(Vector3f*)(Core::moduleBase + 0x27F2B4) = rotation;
}

float Camera::getFreeCamSpeed()
{
	return *(float*)(Core::moduleBase + 0x254B08);
}

void Camera::setFreeCamSpeed(float speed = 0.6f)
{
	*(float*)(Core::moduleBase + 0x254B08) = speed;
}

float Camera::getCameraDistance()
{
	return *(float*)(Core::moduleBase + 0x27EC00);
}

void Camera::setCameraDistance(float distance)
{
	*(float*)(Core::moduleBase + 0x27EC00) = distance;
}

void Camera::setCameraDistanceValue(CameraDistanceLevel level, float distance) {
	*(float*)(Core::moduleBase + 0x27E7E8 + 0x8 * (int)level) = distance;
}

void Camera::setCameraGoof(float value = 1.0) {
	*(float*)(Core::moduleBase + 0x240488) = value;
}
