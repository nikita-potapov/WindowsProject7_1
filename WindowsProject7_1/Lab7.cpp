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
	if (numPicture == 8) Image3(hdc);
}


void OlympicEmblem(HDC hdc)
{
	SelectObject(hdc, GetStockObject(NULL_BRUSH));
	// ¬ерхний р¤д
	HPEN BluehPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
	SelectObject(hdc, BluehPen);
	Ellipse(hdc, 20, 40, 60, 80);

	HPEN BlackhPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	SelectObject(hdc, BlackhPen);
	Ellipse(hdc, 70, 40, 110, 80);

	HPEN RedhPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	SelectObject(hdc, RedhPen);
	Ellipse(hdc, 120, 40, 160, 80);

	// Ќижний р¤д
	HPEN YellowhPen = CreatePen(PS_SOLID, 5, RGB(255, 255, 0));
	SelectObject(hdc, YellowhPen);
	Ellipse(hdc, 45, 60, 85, 100);

	HPEN GreenhPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	SelectObject(hdc, GreenhPen);
	Ellipse(hdc, 95, 60, 135, 100);

	//Arc(
	//	HDC hdc, // идентификатор контекста отображени¤ 
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
	//	HDC hdc, // идентификатор контекста отображени¤ 
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
	GetRegularPolygonCords(200, 200, 30, SIDES_COUNT, 0, ppoints);

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

void Image3(HDC hdc)
{
	/*
		MoveToEx - LineTo
		Ellipse
		Rectangle
		Вывод текста
		+ Рекурсия 
		Arc
		Chord
		Pie
	*/

	DrawRekursiveRegularPolygon(hdc, 100, 100, 6, 0, 100);
	DrawMikkiMouse(hdc, 400, 20, 1.0f);

}


void DrawMikkiMouse(HDC hdc, int x, int y, float k)
{
	HBRUSH hBrushBlack = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH hBrushWhite = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH hBrushRed = CreateSolidBrush(RGB(255, 0, 0));
	HPEN hPenBlack1 = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN hPenBlack2 = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, hBrushBlack);

	Ellipse(hdc, x + 20 * k, y + 21 * k, x + 121 * k, y + 118 * k);
	Ellipse(hdc, x + 199 * k, y + 6 * k, x + 303 * k, y + 94 * k);
	Ellipse(hdc, x + 86 * k, y + 55 * k, x + 253 * k, y + 210 * k);

	SelectObject(hdc, hBrushWhite);

	SelectObject(hdc, GetStockObject(NULL_PEN));

	Ellipse(hdc, x + 113 * k, y + 69 * k, x + 172 * k, y + 175 * k);
	Ellipse(hdc, x + 166 * k, y + 62 * k, x + 225 * k, y + 177 * k);

	Ellipse(hdc, x + 105 * k, y + 126 * k, x + 176 * k, y + 190 * k);

	Ellipse(hdc, x + 166 * k, y + 131 * k, x + 232 * k, y + 190 * k);

	Ellipse(hdc, x + 115 * k, y + 131 * k, x + 225 * k, y + 200 * k);

	SelectObject(hdc, hPenBlack2);

	Arc(hdc, x + 126 * k, y + 81 * k, x + 152 * k, y + 119 * k,
			x + 188 * k, y + 29 * k, x + 17 * k, y + 12 * k);

	Arc(hdc, x + 184 * k, y + 77 * k, x + 213 * k, y + 128 * k,
		x + 246 * k, y + 45 * k, x + 142 * k, y + 26 * k);

	SelectObject(hdc, hBrushBlack);


	Ellipse(hdc, x + 145 * k, y + 120 * k, x + 200 * k, y + 190 * k);

	SelectObject(hdc, hBrushWhite);

	SelectObject(hdc, GetStockObject(NULL_PEN));

	Ellipse(hdc, x + 130 * k, y + 115 * k, x + 215 * k, y + 180 * k);

	SelectObject(hdc, hPenBlack1);



	Arc(hdc, x + 130 * k, y + 115 * k, x + 215 * k, y + 180 * k,
			x + 50 * k, y + 214 * k, x + 260 * k, y + 188 * k);


	SelectObject(hdc, hPenBlack1);

	DrawLine(hdc, x + 141 * k, y + 161 * k, x + 131 * k, y + 171 * k);
	DrawLine(hdc, x + 200 * k, y + 161 * k, x + 212* k, y + 167 * k);


	SelectObject(hdc, hBrushWhite);

	Ellipse(hdc, x + 160 * k, y + 183 * k, x + 185 * k, y + 189 * k);
	DrawLine(hdc, x + 170 * k, y + 181 * k, x + 177 * k, y + 187 * k);


	Ellipse(hdc, x + 140 * k, y + 105 * k, x + 167 * k, y + 152 * k);
	Ellipse(hdc, x + 170 * k, y + 105 * k, x + 197 * k, y + 152 * k);

	SelectObject(hdc, hBrushBlack);

	Ellipse(hdc, x + 145 * k, y + 125 * k, x + 165 * k, y + 150 * k);
	Ellipse(hdc, x + 172 * k, y + 125 * k, x + 190 * k, y + 150 * k);

	SelectObject(hdc, hBrushWhite);
	SelectObject(hdc, GetStockObject(NULL_PEN));

	Ellipse(hdc, x + 150 * k, y + 130 * k, x + 155 * k, y + 135 * k);
	Ellipse(hdc, x + 177 * k, y + 130 * k, x + 182 * k, y + 135 * k);

	SelectObject(hdc, hPenBlack1);

	Ellipse(hdc, x + 143 * k, y + 140 * k, x + 198 * k, y + 168 * k);

	SelectObject(hdc, GetStockObject(NULL_PEN));

	Ellipse(hdc, x + 140 * k, y + 144 * k, x + 200 * k, y + 170 * k);

	Arc(hdc, x + 143 * k, y + 140 * k, x + 198 * k, y + 168 * k,
		x + 218 * k, y + 146 * k, x + 128 * k, y + 149 * k);

	SelectObject(hdc, hBrushBlack);

	Ellipse(hdc, x + 150 * k, y + 145 * k, x + 190 * k, y + 165 * k);

	SelectObject(hdc, hBrushWhite);

	Ellipse(hdc, x + 162 * k, y + 147 * k, x + 175 * k, y + 155 * k);

	DeleteObject(hBrushBlack);
	DeleteObject(hBrushWhite);
	DeleteObject(hBrushRed);

}


void GetRegularPolygonCords(int cx, int cy, int r, int n, double shift, POINT* ppoints)
{
	for (int i = 0; i < n; i++)
	{
		ppoints[i].x = r * cos(2 * pi / n * i + shift) + cx;
		ppoints[i].y = r * sin(2 * pi / n * i + shift) + cy;
	}
}


void DrawRegularPolygon(HDC hdc, int cx, int cy, int r, int n, double shift)
{
	HPEN hPen  = CreatePen(PS_SOLID, 2, RGB(0,0,0));
	SelectObject(hdc, hPen);
	
	POINT* ppoints = (POINT*)malloc(n * sizeof(POINT));
	GetRegularPolygonCords(cx, cy, r, n, shift, ppoints);
	Polygon(hdc, ppoints, n);
	free(ppoints);
	DeleteObject(hPen);
}


void DrawRekursiveRegularPolygon(HDC hdc, int cx, int cy, int n, double shift, int size)
{
	DrawRegularPolygon(hdc, cx, cy, size, n, shift);
	if (size < 5) return;
	DrawRekursiveRegularPolygon(hdc, cx, cy, n, shift + pi / n / 2, size - 2);
}


void DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}