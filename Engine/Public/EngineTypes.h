//
// * ENGINE-X
//
// + Types.h
// representations of: 2D vector with floats, 2D vector with integers and RBGA color as four bytes
//

#pragma once

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exVector2
{
	float x, y;

	exVector2 operator-(const exVector2& other) const
	{
		return { this->x - other.x,this->y - other.y };
	}

	exVector2 operator+(const exVector2& other) const
	{
		return { this->x + other.x,this->y + other.y };
	}

	exVector2 operator*(const float& mulitpicationFactor) const
	{
		return { this->x * mulitpicationFactor, this->y * mulitpicationFactor };
	}
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exIntegerVector2
{
	int x, y;
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exColor
{
	unsigned char mColor[4];
};
