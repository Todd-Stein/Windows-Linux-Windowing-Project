#include "Button.h"
#include "WindowClass.h"

#include <unordered_map>

using std::unordered_map;

class HwndHash {
public:
    size_t operator() (const HWND handle) const {
        return reinterpret_cast<size_t>(handle);
    }
};

class  WindowHandler
{
private:
    WindowClass mainWindow;
    HINSTANCE hInstance;
    unordered_map<HWND, WindowClass, HwndHash> sparseWindowSet;
    static WindowHandler* handler;
public:
    WindowHandler();
     WindowHandler(HINSTANCE);
    ~ WindowHandler();
    HWND GetMainWindow() {return (HWND)mainWindow;}
    HWND CreateNewWindow(string, int, int, int, int, HWND);
    static WindowHandler* Instance(HINSTANCE hInst) {
        if(handler==nullptr) {
            handler = new WindowHandler(hInst);
        }
        return handler;
    }
    bool EventListen();
};

