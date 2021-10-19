#pragma once
#include "framework.h"
void Lab6(HDC hdc, int numPicture);
void drawMyImage(HDC hdc);
void drawFrame(HDC hdc);
void showScore(HDC hdc);
void DrawTarget(HDC hdc);
void DrawSight(HDC hdc);
int insideTarget(int x, int y);
void Cross(HDC hdc, int cx, int cy, int size);
void Triangle(HDC hdc, int cx, int cy, int size);
void RecursiveCross(HDC hdc, int cx, int cy, int size);
void Circle(HDC hdc, int cx, int cy, int size);
void RecursiveTriangle(HDC hdc, int cx, int cy, int size);
void RecursiveRectagle(HDC hdc, int cx, int cy, int size);
void RecursiveCircle(HDC hdc, int cx, int cy, int size);

void moveDown();
void moveToLeft();
void moveUp();
void moveToRight();