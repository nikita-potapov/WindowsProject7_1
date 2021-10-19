#include "Lab6.h"
#include "framework.h"
#include <stdio.h>

#define SIZE_IMAGE 50

int redColor = 0;
int hit = 0;
int missed = 0;
int targetCx = 200;
int targetCy = 200;
int targetSize = 100;
extern int sizeImage;

int scopeX = 100;
int scopeY = 100;

void Lab6(HDC hdc, int numPicture)
{
    switch (numPicture)
    {
    case 0:
        showScore(hdc);
        drawFrame(hdc);
        break;
    case 1:
        RecursiveCircle(hdc, 200, 160, sizeImage);
        break;
    case 2:
        RecursiveCross(hdc, 200, 160, sizeImage);
        break;
    case 3:
        RecursiveTriangle(hdc, 200, 160, sizeImage);
        break;
    }
}


void drawFrame(HDC hdc)
{
    DrawTarget(hdc); // цель
    DrawSight(hdc); // прицел

}


void showScore(HDC hdc)
{
    HFONT hFont = CreateFont(20,
        0, 0, 0, 0, 0, 0, 0,
        DEFAULT_CHARSET,
        0, 0, 0, 0,
        L"Courier New"
    );
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(redColor, 0, 128));

    TCHAR  string1[] = _T("Попал:");
    TextOut(hdc, 10, 10, string1, _tcslen(string1));

    TCHAR  string2[] = _T("Промазал:");
    TextOut(hdc, 400, 10, string2, _tcslen(string2));

    char sHit[5]; // локальная переменная sHit
    TCHAR  tsHit[5];
    sprintf_s(sHit, "%d", hit); // использование глобальной переменной hit
    OemToChar(sHit, tsHit);
    TextOut(hdc, 100, 10, tsHit, _tcslen(tsHit));

    char sMissed[5];
    TCHAR  tsMissed[5];
    sprintf_s(sMissed, "%d", missed);
    OemToChar(sMissed, tsMissed);
    TextOut(hdc, 520, 10, tsMissed, _tcslen(tsMissed));

}


void DrawTarget(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(redColor, 255, 0));
    SelectObject(hdc, hPen);

    RecursiveRectagle(hdc, targetCx, targetCy, targetSize);

    DeleteObject(hPen);
}


void RecursiveRectagle(HDC hdc, int cx, int cy, int size) {
    Rectangle(hdc, cx - size, cy - size, cx + size, cy + size);

    if (size < 5) {
        return;
    }

    RecursiveRectagle(hdc, cx - size * 0.45, cy - size * 0.45, size / 2.5);
    RecursiveRectagle(hdc, cx + size * 0.45, cy - size * 0.45, size / 2.5);
    RecursiveRectagle(hdc, cx - size * 0.45, cy + size * 0.45, size / 2.5);
    RecursiveRectagle(hdc, cx + size * 0.45, cy + size * 0.45, size / 2.5);
}


void DrawSight(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(redColor, 0, 0));
    SelectObject(hdc, hPen);

    Ellipse(hdc, scopeX - 40, scopeY - 40, scopeX + 40, scopeY + 40);
    Ellipse(hdc, scopeX - 30, scopeY - 30, scopeX + 30, scopeY + 30);
    Ellipse(hdc, scopeX - 20, scopeY - 20, scopeX + 20, scopeY + 20);

    MoveToEx(hdc, scopeX - 50, scopeY, NULL);
    LineTo(hdc, scopeX + 50, scopeY);

    MoveToEx(hdc, scopeX, scopeY - 50, NULL);
    LineTo(hdc, scopeX, scopeY + 50);
    DeleteObject(hPen);
}


void moveDown() {
    scopeY += 10;
}


void moveToLeft() {
    scopeX -= 10;
}


void moveUp() {
    scopeY -= 10;
}


void moveToRight() {
    scopeX += 10;
}


int insideTarget(int x, int y) {
    if (x < targetCx - targetSize)
        return 0;
    if (x > targetCx + targetSize)
        return 0;
    if (y < targetCy - targetSize)
        return 0;
    if (y > targetCy + targetSize)
        return 0;
    return 1;
}


void Cross(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(redColor, 255, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx - size, cy, NULL);
    LineTo(hdc, cx + size, cy);
    MoveToEx(hdc, cx, cy - size, NULL);
    LineTo(hdc, cx, cy + size);
    DeleteObject(hPen);
}


void RecursiveCross(HDC hdc, int cx, int cy, int size) {
    Cross(hdc, cx, cy, size); // Cross() см лаб раб  11
    if (size < 10) {
        return;
    }
    RecursiveCross(hdc, cx - size, cy, size / 2);
    RecursiveCross(hdc, cx, cy - size, size / 2);
    RecursiveCross(hdc, cx + size, cy, size / 2);
}


void Triangle(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(redColor, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, cx, cy - size, NULL);
    LineTo(hdc, cx + size, cy + size);
    LineTo(hdc, cx - size, cy + size);
    LineTo(hdc, cx, cy - size);

    DeleteObject(hPen);
}


void RecursiveTriangle(HDC hdc, int cx, int cy, int size) {
    Triangle(hdc, cx, cy, size); // Triangle() см лаб раб  11
    if (size < 10) {
        return;
    }
    RecursiveTriangle(hdc, cx, cy - size, size / 2);
    RecursiveTriangle(hdc, cx + size, cy + size, size / 2);
    RecursiveTriangle(hdc, cx - size, cy + size, size / 2);
}


void Circle(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(redColor, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, cx - size, cy - size, cx + size, cy + size);

    DeleteObject(hPen);
}


void RecursiveCircle(HDC hdc, int cx, int cy, int size) {
    Circle(hdc, cx, cy, size);
    if (size < 10) {
        return;
    }
    RecursiveCircle(hdc, cx, cy - size, size / 2);
    RecursiveCircle(hdc, cx + size, cy, size / 2);
    RecursiveCircle(hdc, cx, cy + size, size / 2);
    RecursiveCircle(hdc, cx - size, cy, size / 2);
}