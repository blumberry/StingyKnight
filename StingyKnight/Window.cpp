#include "Window.h"

Window::Window() {}

void Window::start()
{
	txCreateWindow(725, 725);
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_DARKGRAY);
        txClear();
        score.draw(txDC());
        if (level == 1) {
            map1.draw(txDC());
        }
        if (level == 2) {
            map2.draw(txDC());
        }
        if (level == 3) {
            map3.draw(txDC());
        }
        person.draw(txDC());
        person.update();
        nextLevel();
        txSleep(50);
    }
}

void Window::game()
{

}

void Window::nextLevel()
{
    if ((score.getCoins() == 5) && (level == 1)) {
        if (!map1.getDoorVisible()) {
            map1.setDoorVisibleTrue();
        }
        else if (person.getExitDoor())
        {
            person.setMap(&map2);
            person.setExitDoorFalse();
            person.setPointScreen(POINT{ 190, 180 });
            level = 2;
        }
    }
    if ((score.getCoins() == 10) && (level == 2)) {
        if (!map2.getDoorVisible()) {
            map2.setDoorVisibleTrue();
        }
        else if (person.getExitDoor())
        {
            person.setMap(&map3);
            person.setExitDoorFalse();
            person.setPointScreen(POINT{ 630, 350 });
            level = 3;
        }
    }
}