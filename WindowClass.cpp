#include "WindowClass.h"

WindowClass::WindowClass() {
    windowTitle = "Default Window Name";
    windowWidth = CW_USEDEFAULT;
    windowHeight = CW_USEDEFAULT;
    windowX = CW_USEDEFAULT;
    windowY = CW_USEDEFAULT;
    winClass = {};
    winClass.lpszClassName = (const WCHAR *)windowTitle.c_str();
    winClass.hInstance = hInst;
    winClass.lpfnWndProc = WindowProc;
}
LRESULT CALLBACK WindowClass::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    //TODO Create functions for each message
    //Addendum: each function for each window message will collect data that will be exposed to the programmer instead of impemnting functionality directly
    switch(uMsg) {
        case WM_ACTIVATE:
            return 0;
        case WM_ACTIVATEAPP:
            return 0;
        case WM_AFXFIRST:
            return 0;
        case WM_AFXLAST:
            return 0;
        case WM_APP:
            return 0;
        case WM_APPCOMMAND:
            return 0;
    }
    DefWindowProc(hwnd, uMsg, wParam, lParam);
}