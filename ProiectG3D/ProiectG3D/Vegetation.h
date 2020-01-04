#pragma once
#include"Object.h"

class Vegetation:public Object
{
public:
	enum class Type
	{
		FLOWER,
		GRASS,
		BUSH
	};

public:
	Vegetation(Type type, const Transform& transform = Transform());

	void UpdateThenDraw(const Camera& camera) override;

private:

	std::vector<float> rotations;

};

