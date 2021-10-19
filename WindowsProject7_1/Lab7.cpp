#include "WindowsProject7.h"
#include "Lab7.h"
#include <math.h>

#define STAR_1_COUNT 5
#define STAR_2_COUNT 5
#define STAR_3_COUNT 5
#define MAX_STAR_SIZE 100
#define SIDES_COUNT 11

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500

const double pi = 3.1415926535898;

void Lab7(HDC hdc, int numPicture)
{
	if (numPicture == 0) OlympicEmblem(hdc);
	if (numPicture == 1) AlarmClock(hdc);
	if (numPicture == 2) DrawCloud(hdc);
	if (numPicture == 3) Star1(hdc, 200, 200, 50);
	if (numPicture == 4) Star2(hdc, 200, 200, 50);
	if (numPicture == 5) Star3(hdc, 200, 200, 50);
	if (numPicture == 6) Image1(hdc);
	if (numPicture == 7) Image2(hdc);
}


void OlympicEmblem(HDC hdc)
{
	SelectObject(hdc, GetStockObject(NULL_BRUSH));
	// ђерхний р§д
	HPEN BluehPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
	SelectObject(hdc, BluehPen);
	Ellipse(hdc, 20, 40, 60, 80);

	HPEN BlackhPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	SelectObject(hdc, BlackhPen);
	Ellipse(hdc, 70, 40, 110, 80);

	HPEN RedhPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	SelectObject(hdc, RedhPen);
	Ellipse(hdc, 120, 40, 160, 80);

	// Нижний р§д
	HPEN YellowhPen = CreatePen(PS_SOLID, 5, RGB(255, 255, 0));
	SelectObject(hdc, YellowhPen);
	Ellipse(hdc, 45, 60, 85, 100);

	HPEN GreenhPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	SelectObject(hdc, GreenhPen);
	Ellipse(hdc, 95, 60, 135, 100);

	//Arc(
	//	HDC hdc, // идентификатор контекста отображени§ 
	//	int nxLeft, int nyTop, // верхий левый угол 
	//	int nxRight, int nyBottom, // правый нижний угол 
	//	int nxStart, int nyStart, // начало дуги 
	//	int nxEnd, int nyEnd); // конец дуги 

	SelectObject(hdc, BluehPen);
	Arc(hdc, 20, 40, 60, 80, 60, 80, 60, 40);

	SelectObject(hdc, BlackhPen);
	Arc(hdc, 70, 40, 110, 80, 110, 80, 110, 40);
	Arc(hdc, 70, 40, 110, 80, 80, 80, 85, 80);

	SelectObject(hdc, RedhPen);
	Arc(hdc, 120, 40, 160, 80, 120, 80, 120, 40);
}

void AlarmClock(HDC hdc)
{
	//Arc(
	//	HDC hdc, // идентификатор контекста отображени§ 
	//	int nxLeft, int nyTop, // верхий левый угол 
	//	int nxRight, int nyBottom, // правый нижний угол 
	//	int nxStart, int nyStart, // начало дуги 
	//	int nxEnd, int nyEnd); // конец дуги 

	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(hdc, hPen);

	Chord(hdc, 180, 30,
		220, 70,
		215, 25,
		175, 55);

	Chord(hdc, 220, 30,
		260, 70,
		270, 55,
		230, 35);


	hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	SelectObject(hdc, hPen);

	MoveToEx(hdc, 240, 105, NULL);
	LineTo(hdc, 250, 120);

	MoveToEx(hdc, 200, 105, NULL);
	LineTo(hdc, 190, 120);

	hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, hPen);

	Ellipse(hdc, 180, 40, 260, 120);

	MoveToEx(hdc, 220, 80, NULL);
	LineTo(hdc, 200, 60);

	MoveToEx(hdc, 220, 80, NULL);
	LineTo(hdc, 240, 80);



	DeleteObject(hPen);

}

void DrawCloud(HDC hdc)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 145));
	SelectObject(hdc, hBrush);

	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 145));
	SelectObject(hdc, hPen);

	Ellipse(hdc, 20, 160, 80, 180);
	Ellipse(hdc, 60, 150, 120, 180);
	Ellipse(hdc, 120, 150, 200, 180);
	Ellipse(hdc, 120, 160, 180, 200);
	Ellipse(hdc, 40, 160, 160, 200);

	DeleteObject(hBrush);
}

void Star1(HDC hdc, int cx, int cy, int size)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hBrush);

	POINT p[9] = {
		cx, cy - size,
		cx + size / 4, cy - size / 4,
		cx + size, cy,
		cx + size / 4, cy + size / 4,
		cx, cy + size,
		cx - size / 4, cy + size / 4,
		cx - size, cy,
		cx - size / 4, cy - size / 4,
		cx, cy - size
	};

	Polygon(hdc, p, 8);
}

void Star2(HDC hdc, int cx, int cy, int size)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, hBrush);

	POINT p[8] = {
		cx, cy - size,
		cx + size / 4, cy - size / 4,
		cx + size, cy,
		cx + size / 4, cy + size / 4,
		cx, cy + size,
		cx - size / 4, cy + size / 4,
		cx - size, cy,
		cx - size / 4, cy - size / 4,
	};

	Polygon(hdc, p, 8);
	DeleteObject(hBrush);
}

void Star3(HDC hdc, int cx, int cy, int size)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 142, 0));
	SelectObject(hdc, hBrush);

	POINT p[8] = {
		cx, cy - size,
		cx + size / 4, cy - size / 4,
		cx + size, cy,
		cx + size / 4, cy + size / 4,
		cx, cy + size,
		cx - size / 4, cy + size / 4,
		cx - size, cy,
		cx - size / 4, cy - size / 4,
	};

	Polygon(hdc, p, 8);

	DeleteObject(hBrush);
}

void Image1(HDC hdc)
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 139));
	FillRect(hdc, &rect, hBrush);

	int x, y, size;

	for (int i = 0; i < STAR_1_COUNT; i++)
	{
		x = rand() % (SCREEN_WIDTH - MAX_STAR_SIZE * 2) + MAX_STAR_SIZE;
		y = rand() % (SCREEN_HEIGHT - MAX_STAR_SIZE * 2) + MAX_STAR_SIZE;

		size = rand() % MAX_STAR_SIZE;

		Star1(hdc, x, y, size);
	}

	for (int i = 0; i < STAR_2_COUNT; i++)
	{
		x = rand() % (SCREEN_WIDTH - MAX_STAR_SIZE * 2) + MAX_STAR_SIZE;
		y = rand() % (SCREEN_HEIGHT - MAX_STAR_SIZE * 2) + MAX_STAR_SIZE;

		size = rand() % MAX_STAR_SIZE;

		Star2(hdc, x, y, size);
	}

	for (int i = 0; i < STAR_3_COUNT; i++)
	{
		x = rand() % (SCREEN_WIDTH - MAX_STAR_SIZE * 2) + MAX_STAR_SIZE;
		y = rand() % (SCREEN_HEIGHT - MAX_STAR_SIZE * 2) + MAX_STAR_SIZE;

		size = rand() % MAX_STAR_SIZE;

		Star3(hdc, x, y, size);
	}
}

void Image2(HDC hdc)
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 139));
	FillRect(hdc, &rect, hBrush);



	POINT* ppoints = (POINT*)malloc(sizeof(POINT) * SIDES_COUNT);
	GetRegularPolygonCords(200, 200, 30, SIDES_COUNT, ppoints);

	for (int i = 0; i < SIDES_COUNT; i++)
	{
		Star1(hdc, ppoints[i].x, ppoints[i].y, 10);
	}
	for (int i = 0; i < SIDES_COUNT; i++)
	{
		Star3(hdc, ppoints[i].x + 70, ppoints[i].y, 10);
	}
	for (int i = 0; i < SIDES_COUNT; i++)
	{
		Star2(hdc, ppoints[i].x + 140, ppoints[i].y, 10);
	}
	for (int i = 0; i < SIDES_COUNT; i++)
	{
		Star2(hdc, ppoints[i].x + 35, ppoints[i].y + 60, 10);
	}
	for (int i = 0; i < SIDES_COUNT; i++)
	{
		Star1(hdc, ppoints[i].x + 105, ppoints[i].y + 60, 10);
	}

	free(ppoints);
}

void GetRegularPolygonCords(int cx, int cy, int r, int n, POINT* ppoints)
{
	for (int i = 0; i < n; i++)
	{
		ppoints[i].x = r * cos(2 * pi / n * i) + cx;
		ppoints[i].y = r * sin(2 * pi / n * i) + cy;
	}
}