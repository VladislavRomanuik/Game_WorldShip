#pragma once

struct Point
{
	float x;
	float y;

	Point()
	{
		x = 0;
		y = 0;
	}

	Point(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator==(Point& pt2)
	{
		return (x == pt2.x) && (y == pt2.y);
	}
	
	Point operator+(Point& pt2)
	{
		return Point(x + pt2.x, y + pt2.y);
	}

	Point operator-(Point& pt2)
	{
		return Point(x - pt2.x, y - pt2.y);
	}

	Point operator/(float val)
	{
		return Point(x / val, y / val);
	}

	Point operator%(float val)
	{
		return Point((int)x % (int)val, (int)y % (int)val);
	}

	
};
