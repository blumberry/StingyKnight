#pragma once
#include "WindowObjectPicture.h"
#include "WindowObjectText.h"

class Score : public WindowObject
{
	WindowObjectPicture heart;
	WindowObjectPicture coin;
	WindowObjectText score_coin;
	COLORREF framing_color;
	int hearts;
	int coins;
public:
	Score(POINT pointscreen, int _height, int _width, int height_heart, int width_heart, POINT point_image_heart, char* file_heart,
		COLORREF transparent_color_heart, int height_coin, int width_coin, POINT point_image_coin, char* file_coin,
		COLORREF transparent_color_coin, int height_score_coin, int width_score_coin, COLORREF text_score_coin_color, char* font,
		int text_score_coin_size_font, COLORREF framingcolor, int _hearts = 3, int _coins = 0);
	virtual void draw(HDC &dc);
	void increment_coins();
	void decrement_hearts();
	int getCoins();
};

