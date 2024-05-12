#include "WindowHandler.h"
#include <iostream>


WindowHandler::WindowHandler() {
    hInstance = NULL;
    mainWindow = WindowClass("Main Window", CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL);
}

WindowHandler::WindowHandler(HINSTANCE _hInstance) {
    hInstance = _hInstance;
    std::cout<<"before window"<<std::endl;
    mainWindow = WindowClass("Main Window", CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, hInstance);
    ShowWindow(mainWindow, SW_SHOWNORMAL);
    std::cout<<"after window"<<std::endl;
}

HWND WindowHandler::CreateNewWindow(string windowName, int x, int y, int width, int height, HWND parent) {
    HWND temp = parent;
    if(parent == NULL)
        temp = mainWindow;
    WindowClass newWindow(windowName, x, y, width, height, mainWindow, hInstance);
    sparseWindowSet.insert(std::pair<HWND, WindowClass>((HWND)newWindow, newWindow));
    return (HWND)newWindow;
}
bool WindowHandler::EventListen() {
    while(true) {
        for(auto i : sparseWindowSet) {
            i.second.EventListen();
        }
    }
}
