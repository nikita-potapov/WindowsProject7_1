#include "Lab5.h"
#include "framework.h"

extern int random_colors_state;

void Lab5(HDC hdc, int numPicture)
{
    switch (numPicture)
    {
    case 0:
        star(hdc, 200, 200, 200, 100);
        crown(hdc, 400, 200, 200, 100);
        triangle(hdc, 600, 200, 200, 100);
        MyFigure(hdc, 800, 200, 200, 200);
        MyFigure2(hdc, 10, 10, 200, 200, RGB(0, 0, 0), 0.005f);
        break;

    case 1:
        horizontal_block(hdc, triangle, 0, 0);
        horizontal_block(hdc, crown, 0, 100);
        horizontal_block(hdc, star, 0, 200);
        horizontal_block(hdc, MyFigure, 0, 300);
        horizontal_block(hdc, MyFigure2, 0, 400, 0.015f);
        break;

    case 2:
        vertical_block(hdc, triangle, 0, 0);
        vertical_block(hdc, crown, 100, 0);
        vertical_block(hdc, star, 200, 0);
        vertical_block(hdc, MyFigure, 300, 0);
        vertical_block(hdc, MyFigure2, 500, 0, 0.025f);

        break;

    case 3:
        diagonal_block(hdc, triangle, 0, 0);
        diagonal_block(hdc, crown, 0, 100);
        diagonal_block(hdc, star, 0, 200);
        diagonal_block(hdc, MyFigure, 0, 300);
        diagonal_block(hdc, MyFigure2, 200, 0, 0.015f);
        break;

    case 4:
        grid_block(hdc, triangle);
        break;

    case 5:
        grid_block(hdc, crown);
        break;

    case 6:
        grid_block(hdc, star);
        break;

    case 7:
        grid_block(hdc, MyFigure);
        break;

    case 8:
        grid_block(hdc, MyFigure2, 0.015f);
        break;

    case 9:
        grid_by_step_block(hdc, triangle);
        break;

    case 10:
        grid_by_step_block(hdc, crown);
        break;

    case 11:
        grid_by_step_block(hdc, star);
        break;

    case 12:
        grid_by_step_block(hdc, MyFigure);
        break;

    case 13:
        grid_by_step_block(hdc, MyFigure2, 0.015f);
        break;

    }
}

void star(HDC hdc, int cx, int cy, int sizeX, int sizeY,
    COLORREF color, float k)
{
    POINT p[9] = {
        cx,                           cy - sizeY * k,
        cx + sizeX / 4 * k,           cy - sizeY / 4 * k,
        cx + sizeX * k,               cy,
        cx + sizeX / 4 * k,           cy + sizeY / 4 * k,
        cx ,                          cy + sizeY * k,
        cx - sizeX / 4 * k,           cy + sizeY / 4 * k,
        cx - sizeX * k,               cy,
        cx - sizeX / 4 * k,           cy - sizeY / 4 * k,
        cx,                           cy - sizeY * k,
    };

    Polyline(hdc, p, 9);
}

void triangle(HDC hdc, int cx, int cy, int sizeX, int sizeY,
    COLORREF color, float k)
{

    POINT p[4] = {
        cx - sizeX * k,     cy - sizeY * k,
        cx + sizeX * k,     cy - sizeY * k,
        cx,                 cy + sizeY * k,
        cx - sizeX * k,     cy - sizeY * k,
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 4);
    DeleteObject(hPen);
}

void crown(HDC hdc, int cx, int cy, int sizeX, int sizeY,
    COLORREF color, float k)
{
    POINT p[8] = {
        cx,                           cy - sizeY * k,
        cx + sizeX / 2 * k,           cy,
        cx + sizeX * k,               cy - sizeY * k,
        cx + sizeX * k,               cy + sizeY * k,
        cx - sizeX * k,               cy + sizeY * k,
        cx - sizeX * k,               cy - sizeY * k,
        cx - sizeX / 2 * k,           cy,
        cx,                           cy - sizeY * k,
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 8);
    DeleteObject(hPen);
}

void MyFigure(HDC hdc, int cx, int cy, int sizeX, int sizeY,
    COLORREF color, float k)
{
    POINT p[11] = {
    cx,                       cy + sizeY / 4 * k,
    cx + sizeX * k,           cy + sizeY / 4 * k,
    cx + sizeX * k,           cy + sizeY * 5 / 4 * k,
    cx,                       cy + sizeY * 5 / 4 * k,
    cx,                       cy + sizeY / 4 * k,

    cx + sizeX * 0.5f * k,           cy,
    cx + sizeX * 1.5f * k,    cy,
    cx + sizeX * 1.5f * k,       cy + sizeY * k,
    cx + sizeX * k,           cy + sizeY * 5 / 4 * k,
    cx + sizeX * k,           cy + sizeY / 4 * k,
    cx + sizeX * 1.5f * k,       cy,
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 11);
    DeleteObject(hPen);
}

void MyFigure2(HDC hdc, int cx, int cy, int sizeX, int sizeY,
    COLORREF color, float k)
{
    float dx, dy;

    dx = sizeX / 10;
    dy = sizeY / 10;

    POINT p[20] = {
        cx,                     cy + 177 * dy * k,
        cx + 303 * dx * k,      cy,
        cx + 303 * dx * k,      cy + 517 * dy * k,
        cx + 1154 * dx * k,     cy,
        cx + 1670 * dx * k,     cy,
        cx + 1670 * dx * k,     cy + 612 * dy * k,
        cx + 2606 * dx * k,     cy,
        cx + 2879 * dx * k,     cy,
        cx + 2879 * dx * k,     cy + 495 * dy * k,
        cx + 2577 * dx * k,     cy + 680 * dy * k,
        cx + 2576 * dx * k,     cy + 214 * dy * k,
        cx + 1879 * dx * k,     cy + 661 * dy * k,
        cx + 1372 * dx * k,     cy + 661 * dy * k,
        cx + 1372 * dx * k,     cy + 57 * dy * k,
        cx + 917 * dx * k,      cy + 329 * dy * k,
        cx + 1249 * dx * k,     cy + 661 * dy * k,
        cx + 915 * dx * k,      cy + 661 * dy * k,
        cx + 709 * dx * k,      cy + 454 * dy * k,
        cx + 358 * dx * k,      cy + 661 * dy * k,
        cx,                     cy + 661 * dy * k
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polygon(hdc, p, 20);
    DeleteObject(hPen);
}

void horizontal_block(HDC hdc,
    void (*drawf)(HDC, int, int, int, int, COLORREF, float),
    int cx, int cy, float k)
{
    int x = 50 + cx;
    int sizeX = 25;

    int y = 50 + cy;
    int sizeY = 10;

    int r = 0;
    int g = 0;
    int b = 0;

    int choice = rand() % 3;

    while (x < 900)
    {
        drawf(hdc, x, y, sizeX, sizeY, RGB(r, g, b), k);
        x += 100;
        sizeX += 5;

        if (random_colors_state == 1)
        {
            if (choice == 0)
                r += 30;
            if (choice == 1)
                g += 30;
            if (choice == 2)
                b += 30;
        }
        else
            g += 30;
    }
}

void vertical_block(HDC hdc,
    void (*drawf)(HDC, int, int, int, int, COLORREF, float),
    int cx, int cy, float k)
{
    int x = 50 + cx;
    int sizeX = 10;

    int y = 50 + cy;
    int sizeY = 10;

    int r = 0;
    int g = 0;
    int b = 0;

    int choice = rand() % 3;

    while (y < 400)
    {
        drawf(hdc, x, y, sizeX, sizeY, RGB(r, g, b), k);
        y += 100;
        sizeY += 5;
        if (random_colors_state == 1)
        {
            if (choice == 0)
                r += 30;
            if (choice == 1)
                g += 30;
            if (choice == 2)
                b += 30;
        }
        else
            r += 30;
    }
}

void diagonal_block(HDC hdc,
    void (*drawf)(HDC, int, int, int, int, COLORREF, float),
    int cx, int cy, float k)
{
    int x = 50 + cx;
    int sizeX = 10;

    int y = 50 + cy;
    int sizeY = 10;

    int r = 0;
    int g = 0;
    int b = 0;

    int choice = rand() % 2;

    while (y < 500)
    {
        drawf(hdc, x, y, sizeX, sizeY, RGB(r, g, b), k);


        int choice = rand() % 2;
        x += 100;
        sizeX += 5;
        if (random_colors_state == 1)
        {
            if (choice == 0)
                r += 30;
            if (choice == 1)
                g += 30;
        }
        else
            g += 30;

        y += 50;
        sizeY += 5;
        if (random_colors_state == 1)
        {

            if (choice == 0)
                r += 30;
            if (choice == 1)
                b += 30;
        }
        else
            r += 30;
    }
}

void grid_block(HDC hdc,
    void (*drawf)(HDC, int, int, int, int, COLORREF, float), float k)
{
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int g = 0;
    int b = 0;

    int choice = rand() % 2;

    while (y < 400)
    {
        int x = 50;
        int sizeX = 25;
        g = 0;

        while (x < 900)
        {
            drawf(hdc, x, y, sizeX, sizeY, RGB(r, g, b), k);
            x += 100;
            sizeX += 5;
            if (random_colors_state == 1)
            {
                if (choice == 0)
                    r += 30;
                if (choice == 1)
                    g += 30;
            }
            else
                g += 30;
        }

        y += 100;
        sizeY += 10;
        if (random_colors_state == 1)
        {
            if (choice == 0)
                r += 80;
            if (choice == 1)
                b += 80;
        }
        else
            r += 80;
    }
}

void grid_by_step_block(HDC hdc,
    void (*drawf)(HDC, int, int, int, int, COLORREF, float), float k)
{
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int g = 0;
    int b = 0;

    while (y < 400)
    {
        int x = 50;
        int sizeX = 25;
        g = 0;

        int choice = rand() % 2;

        while (x < 900)
        {
            drawf(hdc, x, y, sizeX, sizeY, RGB(r, g, b), k);
            x += 100;
            sizeX += 5;
            if (random_colors_state == 1)
            {

                if (choice == 0)
                    r += 30;
                if (choice == 1)
                    g += 30;
            }
            else
                g += 30;

            Sleep(20);
        }

        y += 100;
        sizeY += 10;
        if (random_colors_state == 1)
        {
            if (choice == 0)
                r += 80;
            if (choice == 2)
                b += 80;
        }
        else
            g += 80;
    }
}
