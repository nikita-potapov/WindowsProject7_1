#include "Lab3.h"
#include "framework.h"

void Lab3(HDC hdc, int numPicture)
{
    if (numPicture == 0) drawAboutClausTree(hdc);
    if (numPicture == 1) drawAboutElka(hdc);
    if (numPicture == 2) drawAboutKIA(hdc);
}

void drawAboutClausTree(HDC hdc)
{
    stClausTree(hdc, 0, 0, 0.4);
    stClausTree(hdc, 100, 0, 0.4);
    stClausTree(hdc, 100, 100, 0.4);
    stClausTree(hdc, 0, 100, 0.4);
    stClausTree(hdc, 50, 50, 0.4);

    drawHorizontalCount(hdc, stClausTree, 200, 0, 8);
    drawVerticalCount(hdc, stClausTree, 0, 200, 4);
    drawDiagonalCount(hdc, stClausTree, 200, 200, 4);
    drawGrid(hdc, stClausTree, 600, 200, 8, 4, 0.5);
}

void stClausTree(HDC hdc, int x, int y, float k)
{
    HPEN hPen = CreatePen(BS_SOLID, 1, RGB(255, 0, 250));
    SelectObject(hdc, hPen);

    Ellipse(hdc, x + 20 * k, y + 0 * k, x + 40 * k, y + 20 * k);
    Ellipse(hdc, x + 10 * k, y + 20 * k, x + 50 * k, y + 60 * k);
    Ellipse(hdc, x + 0 * k, y + 60 * k, x + 60 * k, y + 120 * k);

    drawLine(hdc, x + 0 * k, y + 40 * k, x + 19 * k, y + 23 * k, hPen);
    drawLine(hdc, x + 43 * k, y + 25 * k, x + 60 * k, y + 38 * k, hPen);
    drawLine(hdc, x + 40 * k, y + 120 * k, x + 70 * k, y + 0 * k, hPen);
    drawLine(hdc, x + 65 * k, y + 20 * k, x + 65 * k, y + 0 * k, hPen);
    drawLine(hdc, x + 65 * k, y + 20 * k, x + 75 * k, y + 0 * k, hPen);
    DeleteObject(hPen);
}

void drawAboutElka(HDC hdc)
{
    drawElka(hdc, 0, 0, 1);
    drawElka(hdc, 100, 0, 1);
    drawElka(hdc, 100, 100, 1);
    drawElka(hdc, 0, 100, 1);
    drawElka(hdc, 50, 50, 1);

    drawHorizontalCount(hdc, drawElka, 200, 0, 8);
    drawVerticalCount(hdc, drawElka, 0, 200, 4);
    drawDiagonalCount(hdc, drawElka, 200, 200, 4);
    drawGrid(hdc, drawElka, 600, 200, 8, 4, 0.8);
}

void drawLine(HDC hdc, int x1, int y1, int x2, int y2, HPEN hPen)
{
    int penExist = 0;
    if (NULL == hPen) {
        HPEN hPen = CreatePen(BS_SOLID, 1, RGB(0, 0, 0));
        SelectObject(hdc, hPen);

        penExist = 1;
    }
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);

    if (1 == penExist)
        DeleteObject(hPen);
}

void drawElka(HDC hdc, int x, int y, float k)
{
    HPEN hPen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));
    SelectObject(hdc, hPen);

    drawLine(hdc, x + 20 * k, y + 0 * k, x + 30 * k, y + 20 * k, hPen);
    drawLine(hdc, x + 30 * k, y + 20 * k, x + 10 * k, y + 20 * k, hPen);
    drawLine(hdc, x + 10 * k, y + 20 * k, x + 20 * k, y + 0 * k, hPen);

    drawLine(hdc, x + 20 * k, y + 10 * k, x + 30 * k, y + 40 * k, hPen);
    drawLine(hdc, x + 30 * k, y + 40 * k, x + 10 * k, y + 40 * k, hPen);
    drawLine(hdc, x + 10 * k, y + 40 * k, x + 20 * k, y + 10 * k, hPen);

    drawLine(hdc, x + 20 * k, y + 30 * k, x + 40 * k, y + 80 * k, hPen);
    drawLine(hdc, x + 40 * k, y + 80 * k, x + 0 * k, y + 80 * k, hPen);
    drawLine(hdc, x + 0 * k, y + 80 * k, x + 20 * k, y + 30 * k, hPen);
    DeleteObject(hPen);
}

void drawHorizontalCount(HDC hdc, void (*drawf)(HDC, int, int, float), int x, int y, int count)
{
    for (int i = 0; i < count; i++)
    {
        drawf(hdc, x + 50 * i, y, 1);
    }
}

void drawVerticalCount(HDC hdc, void (*drawf)(HDC, int, int, float), int x, int y, int count)
{
    for (int i = 0; i < count; i++)
    {
        drawf(hdc, x, y + 90 * i, 1);
    }
}

void drawDiagonalCount(HDC hdc, void (*drawf)(HDC, int, int, float), int x, int y, int count)
{
    for (int i = 0; i < count; i++)
    {
        drawf(hdc, x + 50 * i, y + 90 * i, 1);
    }
}

void drawGrid(HDC hdc, void (*drawf)(HDC, int, int, float), int x, int y, int wCount, int hCount, float k)
{
    for (int i = 0; i < hCount; i++)
    {
        for (int j = 0; j < wCount; j++)
        {
            drawf(hdc, x + j * 50 * k, y + i * 90 * k, k);
        }
    }
}

void drawTheKIALogo(HDC hdc, int x, int y, float k)
{
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
    SelectObject(hdc, hPen);
    HBRUSH hBrushWhite = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrushWhite);
    HBRUSH hBrushRed = CreateSolidBrush(RGB(255, 0, 0));

    Ellipse(hdc, x + 0, y + 0, x + 110 * k, y + 54 * k);
    SelectObject(hdc, hBrushRed);

    POINT letter_cords[11];
    letter_cords[0] = { 23,14 };
    letter_cords[1] = { 29,14 };
    letter_cords[2] = { 29,22 };
    letter_cords[3] = { 37,14 };
    letter_cords[4] = { 43,14 };
    letter_cords[5] = { 36,26 };
    letter_cords[6] = { 45,39 };
    letter_cords[7] = { 39,39 };
    letter_cords[8] = { 29,29 };
    letter_cords[9] = { 29,39 };
    letter_cords[10] = { 23,39 };

    for (int i = 0; i < 11; i++)
    {
        int x_cord = letter_cords[i].x;
        int y_cord = letter_cords[i].y;
        x_cord *= k;
        x_cord += x;

        y_cord *= k;
        y_cord += y;

        letter_cords[i] = { x_cord, y_cord };
    }

    Polygon(hdc, letter_cords, 11);

    Rectangle(hdc, x + 51 * k, y + 14 * k, x + 57 * k, y + 39 * k);

    letter_cords[0] = { 73,14 };
    letter_cords[1] = { 79,14 };
    letter_cords[2] = { 88,39 };
    letter_cords[3] = { 83,39 };
    letter_cords[4] = { 76,22 };
    letter_cords[5] = { 69,39 };
    letter_cords[6] = { 64,39 };


    for (int i = 0; i < 7; i++)
    {
        int x_cord = letter_cords[i].x;
        int y_cord = letter_cords[i].y;
        x_cord *= k;
        x_cord += x;

        y_cord *= k;
        y_cord += y;

        letter_cords[i] = { x_cord, y_cord };
    }

    Polygon(hdc, letter_cords, 7);
}

void drawAboutKIA(HDC hdc)
{
    drawTheKIALogo(hdc, 0, 0, 0.4);
    drawTheKIALogo(hdc, 100, 0, 0.4);
    drawTheKIALogo(hdc, 100, 100, 0.4);
    drawTheKIALogo(hdc, 0, 100, 0.4);
    drawTheKIALogo(hdc, 50, 50, 0.4);

    drawHorizontalCount(hdc, drawTheKIALogo, 200, 0, 8);
    drawVerticalCount(hdc, drawTheKIALogo, 0, 200, 4);
    drawDiagonalCount(hdc, drawTheKIALogo, 200, 200, 4);
    drawGrid(hdc, drawTheKIALogo, 600, 200, 8, 4, 0.5);
}