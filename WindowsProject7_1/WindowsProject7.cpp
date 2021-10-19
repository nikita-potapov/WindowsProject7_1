// WindowsProject7_1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WindowsProject7.h"

#include "Lab7.h"
#include "Lab6.h"
#include "Lab5.h"
#include "Lab4.h"
#include "Lab3.h"
#include "Lab2.h"
#include "Lab1.h"

#define MIN_LAB 0
#define MAX_LAB 6

int numPicture = 0;
int numLab = 0;
int sizeImage = 50;
int random_colors_state = 0;
extern int redColor, hit, missed, targetCx, targetCy, targetSize, scopeX, scopeY, sizeImage;

const int pictures_count[] = { 1, 1, 3, 5, 14, 4, 8 };

void drawMyCode(HDC hdc)
{
    if (numLab == 6) Lab7(hdc, numPicture);
    if (numLab == 5) Lab6(hdc, numPicture);
    if (numLab == 4) Lab5(hdc, numPicture);
    if (numLab == 3) Lab4(hdc, numPicture);
    if (numLab == 2) Lab3(hdc, numPicture);
    if (numLab == 1) Lab2(hdc, numPicture);
    if (numLab == 0) Lab1(hdc, numPicture);
}

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT71, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT71));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT71));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT71);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_NUMPAD5:
            random_colors_state = !random_colors_state;
            if (numLab == 5)
            {
                if (insideTarget(scopeX, scopeY)) {
                    hit++;
                }
                else {
                    missed++;
                }
            }
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_F2:
            numLab++;
            numPicture = 0;
            if (numLab > MAX_LAB) numLab = MAX_LAB;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_F1:
            numLab--;
            numPicture = 0;
            if (numLab < MIN_LAB) numLab = MIN_LAB;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_UP:
            sizeImage += 10;
            if (sizeImage > 100) sizeImage = 100;
            InvalidateRect(hWnd, NULL, TRUE);
        break;

        case VK_DOWN:
            sizeImage -= 10;
            if (sizeImage < 10) sizeImage = 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_LEFT:
            numPicture--;
            if (numPicture < 0) numPicture = 0;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            numPicture++;
            if (numPicture > pictures_count[numLab - MIN_LAB] - 1)
                numPicture = pictures_count[numLab - MIN_LAB] - 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_NUMPAD4:
            if (numLab != 5) break;
            moveToLeft();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_NUMPAD6:
            if (numLab != 5) break;
            moveToRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_NUMPAD8:
            if (numLab != 5) break;
            moveUp();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_NUMPAD2:
            if (numLab != 5) break;
            moveDown();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: Добавьте сюда любой код прорисовки, использующий HDC...

        drawMyCode(hdc);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
