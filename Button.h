#pragma once
#include "TypeDeclarations.h"
#ifdef _WIN32
#include <Windows.h>
#endif
#include <string>

using std::string, std::wstring;
class Button {
public:
    Button();
    Button(WindowID, string, int, int, int, int);
    operator ButtonID() {return m_buttonID;}
    bool GetWasClicked() {return m_wasClicked;}
    /*
    #ifdef _WIN32
        operator HWND() {return (HWND)buttonHandle;}
    #endif
    #ifdef __linux
        operator size_t() {return (size_t)m_buttonID;}
    #endif
    */
private:
    ButtonID m_buttonID;
    bool m_wasClicked;
    void* m_callbackFunc;
};