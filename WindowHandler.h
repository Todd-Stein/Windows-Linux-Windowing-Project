#pragma once

#include "Button.h"
#include "WindowClass.h"

#include <unordered_map>
#include "HashFunction.h"

using std::unordered_map;

class  WindowHandler
{
private:
    WindowClass mainWindow;
    
    unordered_map<WindowID, WindowClass, WindowIDHash> sparseWindowSet;
    static WindowHandler* handler;
    #ifdef _WIN32
    HINSTANCE hInstance;
    #endif
public:
    WindowHandler();
    #ifdef _WIN32
    WindowHandler(HINSTANCE);
    #endif
    ~ WindowHandler();
    WindowID GetMainWindow() {return (WindowID)mainWindow;}
    WindowID CreateNewWindow(string, int, int, int, int, WindowID);
    #ifdef _WIN32
    static WindowHandler* Instance(HINSTANCE hInst) {
        if(handler==nullptr) {
            handler = new WindowHandler(hInst);
        }
        return handler;
    }
    #endif
        static WindowHandler* Instance() {
        if(handler==nullptr) {
            handler = new WindowHandler();
        }
        return handler;
    }
    bool EventListen();
};

