#pragma once
#include "framework.h"
void Lab5(HDC hdc, int numPicture);
void star(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color = RGB(0, 0, 0), float k = 0.4f);
void crown(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color = RGB(0, 0, 0), float k = 0.4f);
void triangle(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color = RGB(0, 0, 0), float k = 0.4f);
void MyFigure(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color = RGB(0, 0, 0), float k = 0.4f);
void MyFigure2(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color = RGB(0, 0, 0), float k = 0.03f);

void horizontal_block(HDC hdc,
    void (*drawf)(HDC, int, int, int, int, COLORREF, float),
    int cx, int cy, float k = 1.0f);
void vertical_block(HDC hdc,
    void (*drawf)(HDC, int, int, int, int, COLORREF, float),
    int cx, int cy, float k = 1.0f);
void diagonal_block(HDC hdc,
    void (*drawf)(HDC, int, int, int, int, COLORREF, float),
    int cx, int cy, float k = 1.0f);
void grid_block(HDC hdc,
    void (*drawf)(HDC, int, int, int, int, COLORREF, float), float k = 1.0f);
void grid_by_step_block(HDC hdc,
    void (*drawf)(HDC, int, int, int, int, COLORREF, float), float k = 1.0f);