#include "WindowHandler.h"
#include <iostream>

#ifdef _WIN32
WindowHandler::WindowHandler(HINSTANCE _hInstance) {
    hInstance = _hInstance;
    std::cout<<"before window"<<std::endl;
    mainWindow = WindowClass("Main Window", CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, hInstance);
    ShowWindow(mainWindow, SW_SHOWNORMAL);
    std::cout<<"after window"<<std::endl;
}
#endif
WindowID WindowHandler::CreateNewWindow(string windowName, int x, int y, int width, int height, WindowID parent) {
    WindowID temp = parent;
    if(parent == NULL)
        temp = mainWindow;
    #ifdef _WIN32
        WindowClass newWindow(windowName, x, y, width, height, mainWindow, hInstance);
    #endif
    #ifdef __linux
        WindowClass newWindow(windowName, x, y, width, height, parent);
    #endif
    sparseWindowSet.insert(std::pair<WindowID, WindowClass>((WindowID)newWindow, newWindow));
    return (WindowID)newWindow;
}
bool WindowHandler::EventListen() {
    while(true) {
        for(auto i : sparseWindowSet) {
            i.second.EventListen();
        }
    }
}
