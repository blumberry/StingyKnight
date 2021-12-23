#include "WindowObjectText.h"

WindowObjectText::WindowObjectText(POINT pointscreen, int height, int width, char* _text, COLORREF textcolor, char* _font, int sizefont,
	POINT lefttoppointframing, POINT rightbottompointfraiming, COLORREF framingcolor, COLORREF framingfillcolor)
	: WindowObject(pointscreen, height, width)
{
	for (int i = 0; i < 100; i++) {
		text[i] = _text[i];
		if (_text[i] == '\0') {
			break;
		}
	}
	text_color = textcolor;
	for (int i = 0; i < 20; i++) {
		font[i] = _font[i];
		if (_font[i] == '\0') {
			break;
		}
	}
	size_font = sizefont;
	left_top_point_framing = lefttoppointframing;
	right_bottom_point_fraiming = rightbottompointfraiming;
	framing_color = framingcolor;
	framing_fill_color = framingfillcolor;
}

void WindowObjectText::draw(HDC& dc)
{
	txSetColor(framing_color, 1,  dc);
	txSetFillColor(framing_fill_color, dc);
	txRectangle(left_top_point_framing.x, left_top_point_framing.y, right_bottom_point_fraiming.x, right_bottom_point_fraiming.y, dc);
	txSetColor(text_color, 1, dc);
	txSelectFont(font, size_font, -1, FW_DONTCARE, false, false, false, 0, dc);
	txTextOut(point_screen.x, point_screen.y, text, dc);
}

void WindowObjectText::setTextFromInt(int number)
{
	if (number < 10) {
		text[0] = '0' + number % 10;
		text[1] = '\0';
	}
	else {
		text[0] = '0' + number / 10;
		text[1] = '0' + number % 10;
		text[2] = '\0';
	}
}