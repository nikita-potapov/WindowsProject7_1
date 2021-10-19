#include "Lab1.h"
#include "framework.h"
#include <math.h>

void Lab1(HDC hdc, int numPicture)
{
    MoveToEx(hdc, 150, 350, NULL);
    // Крыша
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);
    // Дом
    LineTo(hdc, 400, 525);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 150, 350);
    LineTo(hdc, 400, 350);

    HBRUSH hBrush;
    hBrush = CreateSolidBrush(RGB(178, 34, 34));
    SelectObject(hdc, hBrush);
    RECT rect2 = { 400, 350, 150, 525 };
    FillRect(hdc, &rect2, hBrush);

    hBrush = CreateSolidBrush(RGB(112, 128, 144));
    SelectObject(hdc, hBrush);
    POINT cords[3];
    cords[0] = { 150, 350 };
    cords[1] = { 275, 250 };
    cords[2] = { 400, 350 };

    Polygon(hdc, cords, 3);

    // Окно
    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 225, 400);

    hBrush = CreateSolidBrush(RGB(229, 231, 139));
    SelectObject(hdc, hBrush);
    POINT windowCords[4];
    windowCords[0] = { 225, 400 };
    windowCords[1] = { 325, 400 };
    windowCords[2] = { 325, 475 };
    windowCords[3] = { 225, 475 };

    Polygon(hdc, windowCords, 4);

    // Рама
    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);
    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);

    // Ёлочка
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 525, 375, NULL);
    LineTo(hdc, 550, 400);
    LineTo(hdc, 500, 400);
    LineTo(hdc, 525, 375);

    MoveToEx(hdc, 525, 400, NULL);
    LineTo(hdc, 575, 450);
    LineTo(hdc, 475, 450);
    LineTo(hdc, 525, 400);

    MoveToEx(hdc, 525, 450, NULL);
    LineTo(hdc, 600, 525);
    LineTo(hdc, 450, 525);
    LineTo(hdc, 525, 450);

    hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    // Кипарис
    drawTree(hdc, 1050, 525);

    hPen = CreatePen(PS_SOLID, 8, RGB(255, 255, 0));
    SelectObject(hdc, hPen);

    hBrush = CreateHatchBrush(HS_CROSS, RGB(255, 255, 0));
    SelectObject(hdc, hBrush);

    // Солнце
    Ellipse(hdc, 20, 50, 100, 130);

    // Облако
    drawCloud(hdc, 400, 70);

    // ТВ антенна
    hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    // Мачта
    MoveToEx(hdc, 338, 300, NULL);
    LineTo(hdc, 338, 200);
    // Бум
    MoveToEx(hdc, 250, 235, NULL);
    LineTo(hdc, 400, 175);
    // Директор
    MoveToEx(hdc, 360, 170, NULL);
    LineTo(hdc, 440, 180);
    // Вибратор
    MoveToEx(hdc, 270, 190, NULL);
    LineTo(hdc, 435, 210);
    // Рефлектор
    MoveToEx(hdc, 110, 212, NULL);
    LineTo(hdc, 420, 262);

    // Гараж
    hPen = CreatePen(PS_SOLID, 3, RGB(128, 128, 128));
    SelectObject(hdc, hPen);

    hBrush = CreateSolidBrush(RGB(66, 145, 255));
    SelectObject(hdc, hBrush);

    RECT rect;
    rect = { 650, 350, 775, 515 };
    FillRect(hdc, &rect, hBrush);

    hBrush = CreateSolidBrush(RGB(173, 255, 47));
    SelectObject(hdc, hBrush);

    rect = { 775, 350, 900, 515 };
    FillRect(hdc, &rect, hBrush);

    hBrush = CreateSolidBrush(RGB(245, 245, 220));
    SelectObject(hdc, hBrush);

    rect = { 650, 300, 900, 350 };
    FillRect(hdc, &rect, hBrush);


    hBrush = CreateHatchBrush(HS_HORIZONTAL, RGB(200, 200, 200));
    SelectObject(hdc, hBrush);

    drawLineWithCircles(hdc, 20, 650, 300, 650, 530);
    drawLineWithCircles(hdc, 20, 900, 300, 900, 530);
    drawLineWithCircles(hdc, 20, 650, 300, 928, 300);

    MoveToEx(hdc, 775, 350, NULL);
    LineTo(hdc, 775, 512);

    MoveToEx(hdc, 650, 350, NULL);
    LineTo(hdc, 900, 350);

    MoveToEx(hdc, 765, 420, NULL);
    LineTo(hdc, 765, 455);

    MoveToEx(hdc, 785, 420, NULL);
    LineTo(hdc, 785, 455);

    MoveToEx(hdc, 650, 513, NULL);
    LineTo(hdc, 900, 513);

    drawTheKIALogo(hdc, 800, 25, 2.25f);

    DeleteObject(hPen);
    DeleteObject(hBrush);
}

void drawTree(HDC hdc, int x, int y)
{
    // Дерево (Кипарис)
    // Ствол дерева
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 10, RGB(155, 103, 60));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x, y, NULL);
    LineTo(hdc, x, y - 225);

    // Крона дерева
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
    SelectObject(hdc, hPen);

    for (int row = 1; row <= 5; row++)
        for (int col = 0; col < row; col++)
            drawEllipseTree(hdc, x - (row % 2 ? row / 2 + 0.5 : row / 2) * 25 + col * 25, y - 450 + row * 50);
}

void drawEllipseTree(HDC hdc, int x, int y)
{
    // Часть дерева
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, RGB(0, 128, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, x, y, x + 25, y + 100);
}

void drawEllipseCloud(HDC hdc, int x, int y)
{
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);
    HBRUSH hBrush;
    hBrush = CreateSolidBrush(RGB(0, 0, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x, y, x + 200, y + 90);

}

void drawCloud(HDC hdc, int x, int y)
{
    drawEllipseCloud(hdc, x, y);
    drawEllipseCloud(hdc, x + 80, y - 30);
    drawEllipseCloud(hdc, x + 140, y - 15);
    drawEllipseCloud(hdc, x + 200, y + 20);
    drawEllipseCloud(hdc, x + 70, y + 30);
}

void drawLineWithCircles(HDC hdc, int count, int x1, int y1, int x2, int y2)
{
    float dist;
    dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    float radius;
    radius = dist / (count * 2);
    for (int i = 0; i < count; i++)
    {
        drawCircleByCenter(hdc, abs(x1 - x2) / count * i + x1, abs(y1 - y2) / count * i + y1, radius);
    }
}

void drawCircleByCenter(HDC hdc, int x, int y, int r)
{
    Ellipse(hdc, x - r, y - r, x + r, y + r);
}