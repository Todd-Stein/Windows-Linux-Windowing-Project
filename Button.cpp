#include "Button.h"

Button::Button() : m_buttonID(NULL), m_wasClicked(false), m_callbackFunc(nullptr){};

Button::Button(WindowID parentWindow, string buttonText, int xPos, int yPos, int width, int height) {
    #ifdef __WIN32
    wstring tempWide(buttonText.begin(), buttonText.end());
    buttonHandle = CreateWindowEx(0, L"Button", tempWide.c_str(), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, xPos, yPos, width, height, parentWindow, NULL, (HINSTANCE)GetWindowLongPtr(parentWindow, GWLP_HINSTANCE) ,NULL);
    ShowWindow(buttonHandle, SW_SHOWDEFAULT);
    #endif

    //TODO implement button in linux
}

