#pragma once
#include "WindowObjectPicture.h"

class Map : public WindowObjectPicture
{
	int array_of_cells[10][10];
	int block_size;
	POINT point_image_cells[6];
	POINT point_screen_teleports[5];
	POINT door_in_array;
	bool door_visible = false;

public:
	Map(POINT pointscreen, char* file, COLORREF transparentcolor, int blocksize, POINT point_image_earth, POINT point_image_road,
		POINT point_image_teleport, POINT point_image_coin, POINT point_image_lava, POINT point_image_door, int order_of_teleports,
		POINT doorinarray, int level);
	virtual void draw(HDC& dc);
	int getCell(POINT point);
	void setCell(POINT point, int type_cell);
	POINT getPointScreen();
	int getHeight();
	int getWidth();
	POINT getTeleport(POINT point);
	bool getDoorVisible();
	void setDoorVisibleTrue();
};

