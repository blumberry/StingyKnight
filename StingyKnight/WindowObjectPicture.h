#pragma once
#include "WindowObject.h"

class WindowObjectPicture : public WindowObject
{
protected:
	POINT point_image;
	HDC image;
	COLORREF transparent_color;
public:
	WindowObjectPicture(POINT pointscreen, int _height, int _width, POINT pointimage, char* file, COLORREF transparentcolor);
	~WindowObjectPicture();
	virtual void draw(HDC& dc);
	void drawSomeTimes(int times, HDC& dc);
};

