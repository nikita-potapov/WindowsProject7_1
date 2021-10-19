#include "Lab4.h"
#include "framework.h"
#include <math.h>

#define M_PI 3.1415926535898
#define NUM_OF_SIDES 8

extern int sizeImage;

void Lab4(HDC hdc, int numPicture)
{
    if (numPicture == 0) drawAll_1(hdc, 100, 100, sizeImage);
    if (numPicture == 1) drawAll_2(hdc, 100, 100, sizeImage);
    if (numPicture == 2) drawAll_3(hdc, 100, 100, sizeImage);
    if (numPicture == 3) drawAll_4(hdc, 100, 100, sizeImage);
    if (numPicture == 4) drawAll_5(hdc, 300, 250, sizeImage);
}




void drawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
}

void getRegularPoints(int cx, int cy, int r, int n, POINT* ppoints, float shift)
{
    if (NULL == ppoints)
        return;
    for (int i = 0; i < n; i++)
    {
        ppoints[i].x = (int)(r * cos(2.0f * M_PI / n * i + shift) + cx);
        ppoints[i].y = (int)(r * sin(2.0f * M_PI / n * i + shift) + cy);
    }
    return;
}

void drawRegularPolygon(HDC hdc, int cx, int cy, int r, int n)
{
    POINT* ppoints = (POINT*)malloc(sizeof(POINT) * n);
    if (NULL == ppoints)
        return;

    getRegularPoints(cx, cy, r, n, ppoints, 0);

    Polygon(hdc, ppoints, n);

    free(ppoints);
}

void image1(HDC hdc, int cx, int cy, int size)
{
    int x1 = cx - size;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy - size;
    int x3 = cx;
    int y3 = cy + size;

    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    drawLine(hdc, x1, y1, x2, y2);
    drawLine(hdc, x2, y2, x3, y3);
    drawLine(hdc, x3, y3, x1, y1);

    DeleteObject(hPen);

}

void RecursiveImage_1_1(HDC hdc, int cx, int cy, int size)
{
    image1(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_1_1(hdc, cx - size, cy - size, size / 2);
}

void RecursiveImage_1_2(HDC hdc, int cx, int cy, int size)
{
    image1(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_1_2(hdc, cx - size, cy - size, size / 2);
    RecursiveImage_1_2(hdc, cx + size, cy - size, size / 2);
}

void RecursiveImage_1_3(HDC hdc, int cx, int cy, int size)
{
    image1(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_1_3(hdc, cx - size, cy - size, size / 2);
    RecursiveImage_1_3(hdc, cx, cy + size, size / 2);
}

void RecursiveImage_1_4(HDC hdc, int cx, int cy, int size)
{
    image1(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_1_4(hdc, cx - size, cy - size, size / 2);
    RecursiveImage_1_4(hdc, cx + size, cy - size, size / 2);
    RecursiveImage_1_4(hdc, cx, cy + size, size / 2);
}

void RecursiveImage_1_5(HDC hdc, int cx, int cy, int size)
{
    image1(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_1_5(hdc, cx, cy - size, size / 2);
}

void RecursiveImage_1_6(HDC hdc, int cx, int cy, int size)
{
    image1(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_1_6(hdc, cx + size, cy, size / 2);
}

void RecursiveImage_1_7(HDC hdc, int cx, int cy, int size)
{
    image1(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_1_7(hdc, cx, cy - size, size / 2);
    RecursiveImage_1_7(hdc, cx - size, cy, size / 2);
    RecursiveImage_1_7(hdc, cx + size, cy, size / 2);
}



void image2(HDC hdc, int cx, int cy, int size)
{
    int x1 = cx - size / 2;
    int y1 = cy - size;
    int x2 = cx + size / 2;
    int y2 = cy - size;
    int x3 = cx - size;
    int y3 = cy + size;
    int x4 = cx + size;
    int y4 = cy + size;

    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    drawLine(hdc, x1, y1, x2, y2);
    drawLine(hdc, x2, y2, x3, y3);
    drawLine(hdc, x3, y3, x4, y4);
    drawLine(hdc, x4, y4, x1, y1);

    DeleteObject(hPen);

}

void RecursiveImage_2_1(HDC hdc, int cx, int cy, int size)
{
    image2(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_2_1(hdc, cx - size, cy + size, size / 2);
}

void RecursiveImage_2_2(HDC hdc, int cx, int cy, int size)
{
    image2(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_2_2(hdc, cx - size / 2, cy - size, size / 2);
    RecursiveImage_2_2(hdc, cx + size / 2, cy - size, size / 2);
}

void RecursiveImage_2_3(HDC hdc, int cx, int cy, int size)
{
    image2(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_2_3(hdc, cx - size, cy + size, size / 2);
    RecursiveImage_2_3(hdc, cx + size, cy + size, size / 2);
}

void RecursiveImage_2_4(HDC hdc, int cx, int cy, int size)
{
    image2(hdc, cx, cy, size);
    if (size < 20)
        return;

    RecursiveImage_2_4(hdc, cx - size, cy + size, size / 2);
    RecursiveImage_2_4(hdc, cx + size, cy + size, size / 2);
    RecursiveImage_2_4(hdc, cx - size / 2, cy - size, size / 2);
    RecursiveImage_2_4(hdc, cx + size / 2, cy - size, size / 2);
}

void RecursiveImage_2_5(HDC hdc, int cx, int cy, int size)
{
    image2(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_2_5(hdc, cx - size, cy, size / 2);
}

void RecursiveImage_2_6(HDC hdc, int cx, int cy, int size)
{
    image2(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_2_6(hdc, cx + size, cy, size / 2);
}

void RecursiveImage_2_7(HDC hdc, int cx, int cy, int size)
{
    image2(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_2_7(hdc, cx - size, cy, size / 2);
    RecursiveImage_2_7(hdc, cx + size, cy, size / 2);
}


void image3(HDC hdc, int cx, int cy, int size)
{
    int x1 = cx;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy;
    int x3 = cx;
    int y3 = cy + size;
    int x4 = cx - size;
    int y4 = cy;

    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    drawLine(hdc, x1, y1, x2, y2);
    drawLine(hdc, x2, y2, x3, y3);
    drawLine(hdc, x3, y3, x4, y4);
    drawLine(hdc, x4, y4, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage_3_1(HDC hdc, int cx, int cy, int size)
{
    image3(hdc, cx, cy, size);
    if (size < 20)
        return;
    RecursiveImage_3_1(hdc, cx + size, cy, size / 2);
}

void RecursiveImage_3_2(HDC hdc, int cx, int cy, int size)
{
    image3(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_3_2(hdc, cx + size, cy, size / 2);
    RecursiveImage_3_2(hdc, cx - size, cy, size / 2);
}

void RecursiveImage_3_3(HDC hdc, int cx, int cy, int size)
{
    image3(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_3_3(hdc, cx + size, cy, size / 2);
    RecursiveImage_3_3(hdc, cx - size, cy, size / 2);
    RecursiveImage_3_3(hdc, cx, cy + size, size / 2);
}

void RecursiveImage_3_4(HDC hdc, int cx, int cy, int size)
{
    image3(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_3_4(hdc, cx + size, cy, size / 2);
    RecursiveImage_3_4(hdc, cx - size, cy, size / 2);
    RecursiveImage_3_4(hdc, cx, cy - size, size / 2);
}

void RecursiveImage_3_5(HDC hdc, int cx, int cy, int size)
{
    image3(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_3_5(hdc, cx + size, cy, size / 2);
    RecursiveImage_3_5(hdc, cx - size, cy, size / 2);
    RecursiveImage_3_5(hdc, cx, cy + size, size / 2);
    RecursiveImage_3_5(hdc, cx, cy - size, size / 2);
}

void RecursiveImage_3_6(HDC hdc, int cx, int cy, int size)
{
    image3(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_3_6(hdc, cx + size, cy + size, size / 2);
    RecursiveImage_3_6(hdc, cx - size, cy - size, size / 2);
}

void RecursiveImage_3_7(HDC hdc, int cx, int cy, int size)
{
    image3(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_3_7(hdc, cx - size, cy + size, size / 2);
    RecursiveImage_3_7(hdc, cx + size, cy + size, size / 2);

}

void RecursiveImage_3_8(HDC hdc, int cx, int cy, int size)
{
    image3(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_3_8(hdc, cx + size, cy - size, size / 2);
    RecursiveImage_3_8(hdc, cx - size, cy + size, size / 2);

}

void RecursiveImage_3_9(HDC hdc, int cx, int cy, int size)
{
    image3(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_3_9(hdc, cx + size, cy - size, size / 2);
    RecursiveImage_3_9(hdc, cx - size, cy - size, size / 2);

}


void image4(HDC hdc, int cx, int cy, int size)
{
    int x1 = cx;
    int y1 = cy - size;
    int x2 = cx + size / 4;
    int y2 = cy - size / 4;
    int x3 = cx + size;
    int y3 = cy;
    int x4 = cx + size / 4;
    int y4 = cy + size / 4;
    int x5 = cx;
    int y5 = cy + size;
    int x6 = cx - size / 4;
    int y6 = cy + size / 4;
    int x7 = cx - size;
    int y7 = cy;
    int x8 = cx - size / 4;
    int y8 = cy - size / 4;

    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    drawLine(hdc, x1, y1, x2, y2);
    drawLine(hdc, x2, y2, x3, y3);
    drawLine(hdc, x3, y3, x4, y4);
    drawLine(hdc, x4, y4, x5, y5);
    drawLine(hdc, x5, y5, x6, y6);
    drawLine(hdc, x6, y6, x7, y7);
    drawLine(hdc, x7, y7, x8, y8);
    drawLine(hdc, x8, y8, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage_4_1(HDC hdc, int cx, int cy, int size)
{
    image4(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_4_1(hdc, cx + size, cy, size / 2);
}

void RecursiveImage_4_2(HDC hdc, int cx, int cy, int size)
{
    image4(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_4_2(hdc, cx + size, cy, size / 2);
    RecursiveImage_4_2(hdc, cx - size, cy, size / 2);
}

void RecursiveImage_4_3(HDC hdc, int cx, int cy, int size)
{
    image4(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_4_3(hdc, cx, cy + size, size / 2);
    RecursiveImage_4_3(hdc, cx, cy - size, size / 2);
}

void RecursiveImage_4_4(HDC hdc, int cx, int cy, int size)
{
    image4(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_4_4(hdc, cx, cy + size, size / 2);
    RecursiveImage_4_4(hdc, cx, cy - size, size / 2);
    RecursiveImage_4_4(hdc, cx - size, cy, size / 2);
}

void RecursiveImage_4_5(HDC hdc, int cx, int cy, int size)
{
    image4(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_4_5(hdc, cx, cy, size / 1.5);
}

void RecursiveImage_4_6(HDC hdc, int cx, int cy, int size)
{
    image4(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_4_6(hdc, cx + size, cy + size, size / 2);
    RecursiveImage_4_6(hdc, cx - size, cy - size, size / 2);
    RecursiveImage_4_6(hdc, cx + size, cy - size, size / 2);
    RecursiveImage_4_6(hdc, cx - size, cy + size, size / 2);
}

void RecursiveImage_4_7(HDC hdc, int cx, int cy, int size)
{
    image4(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_4_7(hdc, cx + size, cy + size, size / 2);
    RecursiveImage_4_7(hdc, cx - size, cy - size, size / 2);
}

void RecursiveImage_4_8(HDC hdc, int cx, int cy, int size)
{
    image4(hdc, cx, cy, size);
    if (size < 10)
        return;
    RecursiveImage_4_8(hdc, cx - size, cy + size, size / 2);
    RecursiveImage_4_8(hdc, cx + size, cy - size, size / 2);
    //RecursiveImage_4_8(hdc, cx - size, cy - size, size / 2);
}


void image5(HDC hdc, int cx, int cy, int size)
{
    drawRegularPolygon(hdc, cx, cy, size, NUM_OF_SIDES);
}

void RecursiveImage_5_1(HDC hdc, int cx, int cy, int size)
{
    image5(hdc, cx, cy, size);
    if (size < 20)
        return;

    POINT* ppoints = (POINT*)malloc(sizeof(POINT) * NUM_OF_SIDES);
    if (NULL == ppoints)
        return;

    getRegularPoints(cx, cy, size, NUM_OF_SIDES, ppoints, 0);
    for (int i = 0; i < NUM_OF_SIDES; i++)
    {
        RecursiveImage_5_1(hdc, ppoints[i].x, ppoints[i].y, size / 3);
    }

    free(ppoints);
}


void drawAll_1(HDC hdc, int x, int y, int size)
{
    RecursiveImage_1_1(hdc, x, y, size);
    RecursiveImage_1_2(hdc, x + 200, y, size);
    RecursiveImage_1_3(hdc, x + 400, y, size);
    RecursiveImage_1_4(hdc, x + 600, y, size);
    RecursiveImage_1_5(hdc, x + 800, y, size);
    RecursiveImage_1_6(hdc, x, y + 200, size);
    RecursiveImage_1_7(hdc, x + 300, y + 200, size);
}

void drawAll_2(HDC hdc, int x, int y, int size)
{
    RecursiveImage_2_1(hdc, x, y, size);
    RecursiveImage_2_2(hdc, x + 200, y, size);
    RecursiveImage_2_3(hdc, x + 400, y, size);
    RecursiveImage_2_4(hdc, x + 600, y, size);
    RecursiveImage_2_5(hdc, x + 800, y, size);
    RecursiveImage_2_6(hdc, x, y + 200, size);
    RecursiveImage_2_7(hdc, x + 300, y + 200, size);
}

void drawAll_3(HDC hdc, int x, int y, int size)
{
    RecursiveImage_3_1(hdc, x, y, size);
    RecursiveImage_3_2(hdc, x + 200, y, size);
    RecursiveImage_3_3(hdc, x + 400, y, size);
    RecursiveImage_3_4(hdc, x + 600, y, size);
    RecursiveImage_3_5(hdc, x + 800, y, size);
    RecursiveImage_3_6(hdc, x, y + 200, size);
    RecursiveImage_3_7(hdc, x + 300, y + 200, size);
    RecursiveImage_3_8(hdc, x + 500, y + 200, size);
    RecursiveImage_3_9(hdc, x + 750, y + 200, size);
}

void drawAll_4(HDC hdc, int x, int y, int size)
{
    RecursiveImage_4_1(hdc, x, y, size);
    RecursiveImage_4_2(hdc, x + 200, y, size);
    RecursiveImage_4_3(hdc, x + 400, y, size);
    RecursiveImage_4_4(hdc, x + 600, y, size);
    RecursiveImage_4_5(hdc, x + 600, y + 200, size);
    RecursiveImage_4_6(hdc, x, y + 200, size);
    RecursiveImage_4_7(hdc, x + 200, y + 200, size);
    RecursiveImage_4_8(hdc, x + 400, y + 200, size);
}

void drawAll_5(HDC hdc, int x, int y, int size)
{
    RecursiveImage_5_1(hdc, x, y, size + 100);
}