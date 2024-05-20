#pragma once
#include "TypeDeclarations.h"
#include "Button.h"
#include "HashFunction.h"

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::string, std::vector, std::wstring, std::unordered_map;

class WindowClass {
    public:
        WindowClass();
        ButtonID CreateButton(string, int, int, int, int);
        Button* GetButtonByID(ButtonID);
        #ifdef _WIN32
        WindowClass(string, int, int, int, int, WindowID, HINSTANCE);
        #endif
        void EventListen();
        #ifdef _WIN32
        void SetHinstance(HINSTANCE hInst) {m_hinst = hInst;}
        operator HWND() {return m_winID;}
        #endif
        #ifdef __linux
        WindowClass(string, int, int, int, int, WindowID);
        operator Window() {return m_winID;}
        #endif
    private:
    #ifdef _WIN32
        static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
        MSG m_windowMessage;
        WNDCLASS m_winClass;
        HINSTANCE m_hinst;
    #endif
    #ifdef __linux
        Display* m_disp;
        int m_scr;
        XEvent m_evt;
    #endif
    WindowID m_winID;
    int m_windowWidth;
    int m_windowHeight;
    int m_windowX;
    int m_windowY;
    string m_windowTitle;
    vector<WindowClass> m_children;
    unordered_map<ButtonID, Button, WindowIDHash> m_sparseButtonSet;      
};