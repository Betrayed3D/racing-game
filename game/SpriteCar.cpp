#include "stdafx.h"
#include "SpriteCar.h"

CSpriteCar::CSpriteCar(Sint16 x, Sint16 y, Uint32 time)
	: CSprite(x, y, 100, 100, "car.gif", time)
{
	turn = 0;
	gear = 0;
	brakes = false;
}

CSpriteCar::~CSpriteCar()
{
}

void CSpriteCar::OnUpdate(Uint32 time, Uint32 deltaTime)
{
	// first thing done for you: retrieve the current speed
	float v = GetSpeed();

	// TODO: Everything else to calculate the new car's speed!
	
	// At the end, don't forget to set the new speed back to your car!
	SetSpeed(v);
	
	// TURN
	// TODO: modify Direction & Rotation

	CSprite::OnUpdate(time, deltaTime);
}
