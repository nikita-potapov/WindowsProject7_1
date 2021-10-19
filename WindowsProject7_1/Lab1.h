#pragma once
#include "framework.h"
void Lab1(HDC hdc, int numPicture);
void drawHouse(HDC hdc, int x, int y);
void drawTree(HDC hdc, int x, int y);
void drawEllipseTree(HDC hdc, int x, int y);
void drawSpruce(HDC hdc, int x, int y);
void drawEllipseCloud(HDC hdc, int x, int y);
void drawCloud(HDC hdc, int x, int y);
void drawLineWithCircles(HDC hdc, int count, int x1, int y1, int x2, int y2);
void drawCircleByCenter(HDC hdc, int x, int y, int r);
void drawTheKIALogo(HDC hdc, int x, int y, float k = 1.0f);