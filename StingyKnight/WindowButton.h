#pragma once
#include "WindowObjectText.h"

class WindowButton : public WindowObjectText
{
	bool button_activate;
public:
	void buttonActivate();
	void setButtonActivateFalse();
	bool getButtonActivate();
};

