#pragma once
#include "framework.h"
void Lab3(HDC hdc, int numPicture);
void drawLine(HDC  hdc, int x1, int y1, int x2, int y2, HPEN hPen);
void drawElka(HDC hdc, int x, int y, float k);
void drawHorizontalCount(HDC hdc, void (*drawf)(HDC, int, int, float), int x, int y, int count);
void drawVerticalCount(HDC hdc, void (*drawf)(HDC, int, int, float), int x, int y, int count);
void drawDiagonalCount(HDC hdc, void (*drawf)(HDC, int, int, float), int x, int y, int count);
void drawGrid(HDC hdc, void (*drawf)(HDC, int, int, float), int x, int y, int wCount, int hCount, float k);
void drawAboutElka(HDC hdc);
void drawTheKIALogo(HDC hdc, int x, int y, float k);
void drawAboutKIA(HDC hdc);

void drawAboutClausTree(HDC hdc);
void stClausTree(HDC hdc, int x, int y, float k);