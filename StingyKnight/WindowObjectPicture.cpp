#include "WindowObjectPicture.h"

WindowObjectPicture::WindowObjectPicture(POINT pointscreen, int _height, int _width, POINT pointimage, char* file, COLORREF transparentcolor)
	: WindowObject(pointscreen, _height, _width)
{
	point_image = pointimage;
	image = txLoadImage(file);
	if (!image) {
		txMessageBox("Can't upload BMP file");
		exit(-1);
	}
	transparent_color = transparentcolor;
};

WindowObjectPicture::~WindowObjectPicture()
{
	txDeleteDC(image);
}

void WindowObjectPicture::draw(HDC& dc)
{
	txTransparentBlt(dc, point_screen.x, point_screen.y, width, height, image, point_image.x, point_image.y, transparent_color);
}

void WindowObjectPicture::drawSomeTimes(int times, HDC& dc)
{
	int x_heart_screen = point_screen.x;
	for (int i = 0; i < times; i++) {
		txTransparentBlt(dc, x_heart_screen, point_screen.y, width, height, image, point_image.x, point_image.y, transparent_color);
		x_heart_screen += width;
	}
}