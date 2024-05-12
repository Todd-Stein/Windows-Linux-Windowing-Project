#include "Button.h"

Button::Button() : buttonHandle(NULL), wasClicked(false), callbackFunc(nullptr){};

Button::Button(HWND parentWindow, string buttonText, int xPos, int yPos, int width, int height, void* _callbackFunc(void)) {
    buttonHandle = CreateWindowEx(0, L"Button", (LPCWSTR)buttonText.c_str(), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, xPos, yPos, width, height, parentWindow, NULL, (HINSTANCE)GetWindowLongPtr(parentWindow, GWLP_HINSTANCE), ButtonFunc);
    callbackFunc = _callbackFunc;
}

LRESULT CALLBACK Button::ButtonFunc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_COMMAND:
            if(HIWORD(wParam) == BM_CLICK) {
                wasClicked = true;
                if(callbackFunc!=nullptr) {
                    callbackFunc();
                }
            }
    }
}