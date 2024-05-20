#include "WindowHandler.h"

#include <iostream>

#ifdef _WIN32
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ButtonProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#define customloword(val) (val&0x0000ffff)

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    std::cout<<"qwuebfk"<<std::endl;
    unsigned long testVal = 0x89abcdef;
    std::cout<<LOWORD(testVal)<<"\t"<<customloword(testVal)<<std::endl;

    WindowClass newWindow("test", WINDOW_DIMS_UNDEFINED, WINDOW_DIMS_UNDEFINED, WINDOW_DIMS_UNDEFINED, WINDOW_DIMS_UNDEFINED, NULL, hInstance);
    newWindow.CreateButton("test button", 0, 0, 250, 500);
    while(true) {
        newWindow.EventListen();
    }
}

   /*
    const wchar_t CLASS_NAME[] = L"Sample Window Class";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"Window Test", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    
    if(hwnd== NULL)
        return 0;
    ShowWindow(hwnd, nCmdShow);
    HWND button = CreateWindowEx(0, L"Button", L"Ok", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 100, 100, hwnd, NULL, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_WNDPROC), NULL);
    SetWindowLongPtr(button, GWLP_WNDPROC, (LONG_PTR)ButtonProc);

    MSG msg = {};
    while(GetMessage(&msg, NULL, 0, 0)>0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    MSG buttonMSG = {};
    while (GetMessage(&buttonMSG, button, 0, 0) > 0) {
        DispatchMessage(&msg);
    }

    return 0;
    */
/*
LRESULT CALLBACK ButtonProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_COMMAND:
            std::cout<<"click"<<std::endl;
            OutputDebugString(L"Click");
            if(LOWORD(wParam) == BN_CLICKED) {
                DestroyWindow((HWND)lParam);
                return 0;
            }
        default:
            return 0;
    }
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_SIZE: {
        int width = LOWORD(wParam);
        int height = HIWORD(wParam);
        return 0;
    }
    case WM_CLOSE:
        if(MessageBox(hwnd, L"Really Quit?", L"My application", MB_OKCANCEL)==IDOK) {
            DestroyWindow(hwnd);
        }
        else
            return 0;
    case WM_COMMAND:
        OutputDebugString(L"test");
        //if(LOWORD(wParam) == BN_CLICKED) {
        //        DestroyWindow((HWND)lParam);
        //        return 0;
        //}
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
*/
#endif

#ifdef __linux
#include <X11/Xlib.h>

int main() {
    WindowClass newWindow("title", 0, 0, 640, 480, NULL);
    while(true) {
        newWindow.EventListen();
    }
    /*
    Display* disp = XOpenDisplay(NULL);
    int screen = DefaultScreen(disp);
    if(disp == NULL) {
        std::cout<<"Failed to open display"<<std::endl;
        return EXIT_FAILURE;
    }
    std::cout<<"hello"<<std::endl;
    Window win = XCreateSimpleWindow(disp, RootWindow(disp, screen), 0, 0, 640, 480, 0, 0, 0);
    XMapWindow(disp, win);
    XEvent evt;
    //XSetWindowAttributes()
    while(true) {
        XNextEvent(disp, &evt);
        switch (evt.type)
        {
        case Expose:
            XFillRectangle(disp, win, DefaultGC(disp, screen), 20, 20, 20, 10);
            break;
        
        default:
            break;
        }
    }
    */
}
#endif