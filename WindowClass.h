#ifdef _WIN32
#ifndef UNICODE
#define UNICODE
#endif
#include <Windows.h>
#endif

#include <string>
#include <vector>

using std::string, std::vector;

extern HINSTANCE hInst;

class WindowClass {
    public:
        WindowClass();
    private:
        static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
        HWND windowHandle;
        MSG windowMessage;
        WNDCLASS winClass;
        int windowWidth;
        int windowHeight;
        int windowX;
        int windowY;
        string windowTitle;
        vector<WindowClass> children;
};