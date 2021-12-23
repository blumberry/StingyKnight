#include "Person.h"

Person::Person(POINT pointscreen, int height, int width, POINT pointimage, char* file, COLORREF transparentcolor, int _step,
    int lasttimeburning, Map* _map, Score* _score) : WindowObjectPicture(pointscreen, height, width, pointimage, file,
        transparentcolor)
{
    step = _step;
    last_time_burning = lasttimeburning;
    map = _map;
    score = _score;
}

void Person::update()
{
    if (GetAsyncKeyState(VK_RIGHT)) {
        move_right();
    }
    if (GetAsyncKeyState(VK_LEFT)) {
        move_left();
    }
    if (GetAsyncKeyState(VK_UP)) {
        move_up();
    }
    if (GetAsyncKeyState(VK_DOWN)) {
        move_down();
    }
}

void Person::move_right()
{
    change_frame(height * 2);
    if ((map->getCell(POINT{ point_screen.x + width, point_screen.y + height / 2 }) != 0) &&        // first person point to be checked
        (map->getCell(POINT{ point_screen.x + width, point_screen.y + height - 5 }) != 0) &&        // second person point to be checked
        (point_screen.x + width <= map->getPointScreen().x + map->getWidth()))                      // right map borderline
    {
        point_screen.x += step;
        takeCoin();
        walkOnLava();
    }
    else {
        teleportate();
        exitDoor();
    }
}

void Person::move_left()
{
    change_frame(height);
    if ((map->getCell(POINT{ point_screen.x - 2, point_screen.y + height / 2 }) != 0) &&            // first person point to be checked
        (map->getCell(POINT{ point_screen.x - 2, point_screen.y + height - 5 }) != 0) &&            // second person point to be checked
        (point_screen.x >= map->getPointScreen().x))                                                // left map borderline
    {
        point_screen.x -= step;
        takeCoin();
        walkOnLava();
    }
    else {
        teleportate();
        exitDoor();
    }
}

void Person::move_up()
{
    change_frame(height * 3);
    if ((map->getCell(POINT{ point_screen.x + width / 2, point_screen.y + 16 }) != 0) &&            // person point to be checked
        (point_screen.y + 5 >= map->getPointScreen().y))                                            // upper map borderline
    {
        point_screen.y -= step;
        takeCoin();
        walkOnLava();
    }
    else {
        teleportate();
        exitDoor();
    }
}

void Person::move_down()
{
    change_frame(height * 0);
    if ((map->getCell(POINT{ point_screen.x + width / 2, point_screen.y + height + 5 }) != 0) &&    // person point to be checked
        (point_screen.y + height <= map->getPointScreen().y + map->getHeight() - 7))                // bottom map borderline
    {
        point_screen.y += step;
        takeCoin();
        walkOnLava();
    }
    else {
        teleportate();
        exitDoor();
    }
}

void Person::change_frame(int point_image_y)
{
    point_image.y = point_image_y;
    if (point_image.x == width * 2)
    {
        point_image.x = 0;
    }
    else
    {
        point_image.x += width;
    }
}

void Person::takeCoin()
{
    if (map->getCell(POINT{ point_screen.x + width / 3, point_screen.y + height / 3 }) == 3)        // person point to be checked
    {
        score->increment_coins();
        map->setCell(POINT{ point_screen.x + width / 3, point_screen.y + height / 3 }, 1);
    }
}

void Person::walkOnLava()
{
    if (map->getCell(POINT{ point_screen.x + width / 3, point_screen.y + height * 2 / 3 }) == 4)    // person point to be checked
    {
        int time_burning = clock();
        if ((time_burning - last_time_burning < 0) || (time_burning - last_time_burning > 1500))
        {
            score->decrement_hearts();
        }
        last_time_burning = time_burning;
    }
}

void Person::teleportate()
{
    if (map->getCell(POINT{ point_screen.x + width / 3, point_screen.y + height / 3 }) == 2)
    {
        point_screen = map->getTeleport(POINT{ point_screen.x + width / 3, point_screen.y + height / 3 });
    }
}

void Person::setMap(Map* _map)
{
    map = _map;
}

void Person::setPointScreen(POINT point)
{
    point_screen = point;
}

void Person::exitDoor()
{
    if (map->getCell(POINT{ point_screen.x + width / 3, point_screen.y + height / 3 }) == 5)
    {
        exit_door = true;
    }
}

bool Person::getExitDoor()
{
    return exit_door;
}

void Person::setExitDoorFalse()
{
    exit_door = false;
}