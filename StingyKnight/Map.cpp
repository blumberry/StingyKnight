#include "Map.h"

Map::Map(POINT pointscreen, char* file, COLORREF transparentcolor, int blocksize, POINT point_image_earth, POINT point_image_road,
	POINT point_image_teleport, POINT point_image_coin, POINT point_image_lava, POINT point_image_door, int order_of_teleports,
    POINT doorinarray, int level)
	: WindowObjectPicture(pointscreen, blocksize*10, blocksize*10, POINT{0,0}, file, transparentcolor)
{
    int a[10][10] = { { 0, 0, 0, 0, 1, 1, 1, 1, 0, 1},
                      { 0, 2, 0, 0, 1, 0, 0, 1, 1, 1},
                      { 0, 1, 0, 1, 3, 0, 0, 0, 0, 0},
                      { 0, 3, 0, 1, 0, 0, 4, 3, 1, 0},
                      { 0, 1, 4, 1, 1, 1, 1, 0, 1, 0},
                      { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                      { 0, 0, 1, 1, 1, 0, 1, 1, 1, 0},
                      { 0, 0, 3, 0, 1, 0, 1, 0, 0, 0},
                      { 0, 1, 1, 0, 1, 1, 3, 1, 2, 0},
                      { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0} };

    int b[10][10] = { { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
                      { 0, 2, 1, 0, 0, 1, 0, 0, 0, 0},
                      { 0, 3, 1, 0, 0, 3, 1, 0, 0, 0},
                      { 0, 0, 0, 0, 0, 0, 4, 3, 1, 2},
                      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      { 0, 0, 0, 0, 1, 4, 1, 1, 0, 0},
                      { 0, 0, 0, 3, 1, 0, 0, 1, 0, 0},
                      { 0, 0, 0, 1, 0, 0, 0, 3, 1, 2},
                      { 0, 4, 1, 2, 0, 0, 0, 0, 0, 0},
                      { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0} };

    int c[10][10] = { { 0, 0, 0, 0, 0, 0, 1, 3, 1, 2},
                      { 1, 0, 1, 1, 1, 0, 0, 1, 4, 1},
                      { 2, 1, 1, 0, 1, 1, 0, 0, 1, 1},
                      { 1, 0, 0, 0, 1, 1, 0, 1, 1, 0},
                      { 0, 0, 0, 1, 3, 4, 1, 1, 0, 1},
                      { 0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
                      { 1, 1, 0, 0, 1, 1, 0, 1, 1, 0},
                      { 2, 0, 0, 1, 1, 0, 1, 3, 0, 0},
                      { 1, 1, 0, 1, 4, 1, 1, 0, 2, 1},
                      { 0, 3, 0, 3, 1, 1, 0, 0, 1, 1} };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (level == 1) {
                array_of_cells[i][j] = a[i][j];
            }
            if (level == 2) {
                array_of_cells[i][j] = b[i][j];
            }
            if (level == 3) {
                array_of_cells[i][j] = c[i][j];
            }
        }
    }
    block_size = blocksize;
    point_image_cells[0] = point_image_earth;
    point_image_cells[1] = point_image_road;
    point_image_cells[2] = point_image_teleport;
    point_image_cells[3] = point_image_coin;
    point_image_cells[4] = point_image_lava;
    point_image_cells[5] = point_image_door;
    door_in_array = doorinarray;
    for (int i = 0; i < 5; i++) {
        point_screen_teleports[i] = POINT{ -1, -1 };
    }
    int k = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (array_of_cells[i][j] == 2) {
                point_screen_teleports[(order_of_teleports / k) % 10 - 1] = POINT{ j * block_size + point_screen.x,
                    i* block_size + point_screen.y - 7 };
                k *= 10;
            }
        }
    }
}

void Map::draw(HDC& dc)
{
    POINT block_screen{ point_screen.x, point_screen.y };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            switch (array_of_cells[i][j]) {
            case 0:
                txTransparentBlt(dc, block_screen.x, block_screen.y, block_size, block_size, image,
                    point_image_cells[0].x, point_image_cells[0].y, transparent_color);
                break;
            case 1:
                txTransparentBlt(dc, block_screen.x, block_screen.y, block_size, block_size, image,
                    point_image_cells[1].x, point_image_cells[1].y, transparent_color);
                break;
            case 2:
                txTransparentBlt(dc, block_screen.x, block_screen.y, block_size, block_size, image,
                    point_image_cells[2].x, point_image_cells[2].y, transparent_color);
                break;
            case 3:
                txTransparentBlt(dc, block_screen.x, block_screen.y, block_size, block_size, image,
                    point_image_cells[1].x, point_image_cells[1].y, transparent_color);
                txTransparentBlt(dc, block_screen.x, block_screen.y, block_size, block_size, image,
                    point_image_cells[3].x, point_image_cells[3].y, transparent_color);
                break;
            case 4:
                txTransparentBlt(dc, block_screen.x, block_screen.y, block_size, block_size, image,
                    point_image_cells[4].x, point_image_cells[4].y, transparent_color);
                break;
            case 5:
                txTransparentBlt(dc, block_screen.x, block_screen.y, block_size, block_size, image,
                    point_image_cells[5].x, point_image_cells[5].y, transparent_color);
                break;
            }
            block_screen.x += block_size;
        }
        block_screen.y += block_size;
        block_screen.x = point_screen.x;
    }
}

int Map::getCell(POINT point)
{
    return array_of_cells[(point.y - point_screen.y) / block_size][(point.x - point_screen.x) / block_size];
}

void Map::setCell(POINT point, int type_cell)
{
    array_of_cells[(point.y - point_screen.y) / block_size][(point.x - point_screen.x) / block_size] = type_cell;
}

POINT Map::getPointScreen()
{
    return point_screen;
}

int Map::getHeight()
{
    return height;
}

int Map::getWidth()
{
    return width;
}

POINT Map::getTeleport(POINT point)
{
    int x_teleport = (point.x - point_screen.x) / block_size * block_size + point_screen.x;
    int y_teleport = (point.y - point_screen.y) / block_size * block_size + point_screen.y - 7;
    for (int i = 0; i < 5; i++) {
        if ((point_screen_teleports[i].x == x_teleport) && (point_screen_teleports[i].y == y_teleport)) {
            if ((point_screen_teleports[i+1].x == -1) || (i == 4)) {
                return point_screen_teleports[0];
            }
            return point_screen_teleports[i+1];
        }
    }
    return point;
}

bool Map::getDoorVisible()
{
    if (array_of_cells[door_in_array.y][door_in_array.x] == 5) {
        return true;
    }
    return false;
}

void Map::setDoorVisibleTrue()
{
    array_of_cells[door_in_array.y][door_in_array.x] = 5;
}