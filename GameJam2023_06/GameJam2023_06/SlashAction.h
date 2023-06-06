#pragma once
#include "Collider/SphereCollider.h"
#define D_ATTACK_RANGE (75)
#define D_ATTACK_SPEED (0.1f)

class SlashAction:
	public SphereCollider
{
public:
	SlashAction();
	~SlashAction();
	SlashAction(Location location, float radius = 3);

private:
	Location drawLocation;
	int image;
	float angle;

public:
	void Update();
	void Draw()const;

};

