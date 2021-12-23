#pragma once
#include "Score.h"
#include "Map.h"
#include "Person.h"

class Window
{
	Score score{ POINT{ 30, 8 }, 72, 695, 60, 68, POINT{ 0, 0 }, (char*)"heart.bmp", TX_WHITE, 63, 63, POINT{ 269, 304 },
		(char*)"map.bmp", RGB(0, 32, 64), 0, 0, TX_WHITE, (char*)"Comic Sans MS", 60, TX_BLACK };
	Map map1{ POINT{ 47, 80 }, (char*)"map.bmp", RGB(0, 32, 64), 63, POINT{ 26, 24 }, POINT{ 24, 245 }, POINT{ 104, 245 },
		POINT{ 269, 304 }, POINT{ 103, 23 }, POINT{ 335, 245 }, 12, POINT{ 0, 9}, 1 };
	Map map2{ POINT{ 47, 80 }, (char*)"map.bmp", RGB(0, 32, 64), 63, POINT{ 26, 24 }, POINT{ 24, 245 }, POINT{ 104, 245 },
		POINT{ 269, 304 }, POINT{ 103, 23 }, POINT{ 335, 245 }, 14253, POINT{ 1, 9}, 2 };
	Map map3{ POINT{ 47, 80 }, (char*)"map.bmp", RGB(0, 32, 64), 63, POINT{ 26, 24 }, POINT{ 24, 245 }, POINT{ 104, 245 },
		POINT{ 269, 304 }, POINT{ 103, 23 }, POINT{ 335, 245 }, 1324, POINT{ 9, 9}, 3 };
	Person person{ POINT{ 625, 85 }, 73, 48, POINT{ 0, 0 }, (char*)"knight.bmp", TX_WHITE , 10, 0, &map1, &score };
	int level = 1;
public:
	Window();
	void start();
	void game();
	void nextLevel();
};
