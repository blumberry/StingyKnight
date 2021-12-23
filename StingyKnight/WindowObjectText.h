#pragma once
#include "WindowObject.h"

class WindowObjectText : public WindowObject
{
protected:
	char text[100];
	COLORREF text_color;
	char font[20];
	int size_font;
	POINT left_top_point_framing;
	POINT right_bottom_point_fraiming;
	COLORREF framing_color;
	COLORREF framing_fill_color;
public:
	WindowObjectText(POINT pointscreen, int height, int width, char* _text, COLORREF textcolor, char* _font, int sizefont,
		POINT lefttoppointframing = POINT{ 0, 0 }, POINT rightbottompointfraiming = POINT{ 0, 0 },
		COLORREF framingcolor = TX_BLACK, COLORREF framingfillcolor = TX_BLACK);
	virtual void draw(HDC& dc);
	void setTextFromInt(int number);
};

