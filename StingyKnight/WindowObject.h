#pragma once
#include "TXlib.h"

class WindowObject
{
protected:
	POINT point_screen;
	int height;
	int width;
public:
	WindowObject(POINT point_screen, int height, int width);
	virtual void draw(HDC &dc) = 0;
};

