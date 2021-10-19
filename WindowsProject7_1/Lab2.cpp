#include "Lab2.h"
#include "framework.h"

void Lab2(HDC hdc, int numPicture)
{
    drawPictures(hdc, 10, 10);
}



void draw1(HDC hdc, int x, int y)
{
    int x1 = x + 0, y1 = y + 50;
    int x2 = x + 150, y2 = y + 50;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        y1 -= 5;
        y2 += 10;
        i++;
    } while (i < 10);

}

void draw2(HDC hdc, int x, int y)
{
    int x1 = x + 50, y1 = y + 5;
    int x2 = x + 50, y2 = y + 155;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 -= 10;
        y1 += 9;
        x2 += 10;
        y2 -= 9;
        i++;
    } while (i < 12);
}

void draw3(HDC hdc, int x, int y)
{
    int x1 = x + 0, y1 = y + 150;
    int x2 = x + 130, y2 = y + 150;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 -= 0;
        y1 -= 5;
        x2 -= 5;
        y2 -= 0;
        i++;
    } while (i < 27);
}

void draw4(HDC hdc, int x, int y)
{
    int x1 = x + 70, y1 = y + 5;
    int x2 = x + 70, y2 = y + 155;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 -= 8;
        y1 += 8;
        x2 += 0;
        y2 -= 7;
        i++;
    } while (i < 16);
}

void draw5(HDC hdc, int x, int y)
{
    int x1 = x + 50, y1 = y + 155;
    int x2 = x + 80, y2 = y + 155;
    int i = 0;
    do {
        if (i != 0)
        {
            MoveToEx(hdc, x1, y1, NULL);
            LineTo(hdc, x2, y2);
        }
        x1 -= 12;
        y1 += 0;
        x2 += 0;
        y2 -= 10;
        i++;
    } while (i < 16);
}

void draw6(HDC hdc, int x, int y)
{
    int x1 = x + 50, y1 = y + 5;
    int x2 = x + 50, y2 = y + 155;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 7;
        y1 += 0;
        x2 -= 7;
        y2 -= 0;
        i++;
    } while (i < 16);
}

void draw7(HDC hdc, int x, int y)
{
    int x1 = x + 10, y1 = y + 5;
    int x2 = x + 10, y2 = y + 155;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 9;
        y1 += 0;
        x2 += 0;
        y2 -= 7;
        i++;
    } while (i < 16);
}

void draw8(HDC hdc, int x, int y)
{
    int x1 = x + 0, y1 = y + 1;
    int x2 = x + 0, y2 = y + 160;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 10;
        y1 += 10;
        x2 += 10;
        y2 -= 10;
        i++;
    } while (i < 17);
}

void draw9(HDC hdc, int x, int y)
{
    int x1 = x + 70, y1 = y + 150;
    int x2 = x + 110, y2 = y + 150;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 7;
        y1 += 8;
        x2 += 0;
        y2 -= 9;
        i++;
    } while (i < 10);

    x1 = x + 70, y1 = y + 150;
    x2 = x + 110, y2 = y + 150;
    i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 -= 10;
        y1 -= 8;
        x2 += 0;
        y2 += 9;
        i++;
    } while (i < 12);
}

void draw10(HDC hdc, int x, int y)
{
    int x1 = x + 50, y1 = y + 80;
    int x2 = x + 50, y2 = y + 130;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 -= 2;
        x2 += 5;
        y2 += 2;
        i++;
    } while (i < 25);
}

void draw11(HDC hdc, int x, int y)
{
    int x1 = x + 50, y1 = y + 130;
    int x2 = x + 150, y2 = y + 50;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 -= 2;
        x2 += 5;
        y2 += 2;
        i++;
    } while (i < 16);
}

void drawPictures(HDC hdc, int x, int y)
{
    draw1(hdc, x + 5, y);
    draw2(hdc, x + 220, y);
    draw3(hdc, x + 400, y);
    draw4(hdc, x + 580, y);
    draw5(hdc, x + 800, y);
    draw6(hdc, x + 950, y);
    draw7(hdc, x, y + 170);
    draw8(hdc, x + 160, y + 170);
    draw9(hdc, x + 390, y + 100);
    draw10(hdc, x + 500, y + 170);
    draw11(hdc, x + 650, y + 170);
}