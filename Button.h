#ifdef _WIN32
#define UNICODE
#include <Windows.h>
#endif
#include <string>

using std::string;
class Button {
public:
    Button();
    Button(HWND, string, int, int, int, int, void*(void));
    bool GetWasClicked() {return wasClicked;}
private:
    HWND buttonHandle;
    static LRESULT CALLBACK ButtonFunc(HWND, UINT, WPARAM, LPARAM);
    bool wasClicked;
    void* callbackFunc;
};