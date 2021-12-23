#pragma once
#include "WindowObjectPicture.h"
#include "Map.h"
#include "Score.h"

class Person : public WindowObjectPicture
{
	int step;
    int last_time_burning;
    bool exit_door = false;
	Map* map;
	Score* score;

    void change_frame(int point_image_y);
    void takeCoin();
    void walkOnLava();
    void teleportate();
    void exitDoor();
    void move_up();
    void move_down();
    void move_right();
    void move_left();
public:
    Person(POINT pointscreen, int height, int width, POINT pointimage, char* file, COLORREF transparentcolor, int step,
        int last_time_burning, Map* map, Score* score);
    void update();
    void setMap(Map* _map);
    void setPointScreen(POINT point);
    void setExitDoorFalse();
    bool getExitDoor();
};

