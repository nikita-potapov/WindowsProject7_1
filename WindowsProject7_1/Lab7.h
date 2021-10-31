#pragma once
#include "framework.h"
void Picture1(HDC hdc);
void Lab7(HDC hdc, int numPicture);
void OlympicEmblem(HDC hdc);
void AlarmClock(HDC hdc);
void DrawCloud(HDC hdc);
void Star1(HDC hdc, int cx, int cy, int size);
void Star2(HDC hdc, int cx, int cy, int size);
void Star3(HDC hdc, int cx, int cy, int size);
void Image1(HDC hdc);
void Image2(HDC hdc);
void Image3(HDC hdc);
void GetRegularPolygonCords(int cx, int cy, int r, int n, double shift, POINT* ppoints);
void DrawRekursiveRegularPolygon(HDC hdc, int cx, int cy, int n, double shift, int size);
void DrawMikkiMouse(HDC hdc, int x, int y, float k);
void DrawLine(HDC hdc, int x1, int y1, int x2, int y2);