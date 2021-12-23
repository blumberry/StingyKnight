#include "Score.h"

Score::Score(POINT pointscreen, int _height, int _width, int height_heart, int width_heart, POINT point_image_heart, char* file_heart,
	COLORREF transparent_color_heart, int height_coin, int width_coin, POINT point_image_coin, char* file_coin,
	COLORREF transparent_color_coin, int height_score_coin, int width_score_coin, COLORREF text_score_coin_color, char* font,
	int text_score_coin_size_font, COLORREF framingcolor, int _hearts, int _coins)
	: WindowObject(pointscreen, _height, _width),
	heart(POINT{ point_screen.x + 5, point_screen.y + 2 }, height_heart, width_heart, point_image_heart,
		file_heart, transparent_color_heart),
	coin(POINT{ point_screen.x + 595, point_screen.y + 2 }, height_coin, width_coin, point_image_coin,
			file_coin, transparent_color_coin),
	score_coin(POINT{ point_screen.x + 550, point_screen.y + 2 }, height_score_coin, width_score_coin, (char*)"0",
				text_score_coin_color, font, text_score_coin_size_font)
{
	framing_color = framingcolor;
	hearts = _hearts;
	coins = _coins;
}

void Score::draw(HDC &dc)
{
	txSetFillColor(framing_color, dc);
	txSetColor(framing_color, 1, dc);
	txRectangle(point_screen.x, point_screen.y, width, height, dc);
	heart.drawSomeTimes(hearts, dc);
	coin.draw(dc);
	score_coin.setTextFromInt(coins);
	score_coin.draw(dc);
}

void Score::increment_coins()
{
	coins++;
}

void Score::decrement_hearts()
{
	hearts--;
}

int Score::getCoins()
{
	return coins;
}