#include "WindowClass.h"

WindowClass::WindowClass() {
    #ifdef _WIN32
        m_winID = 0;
        m_windowMessage = {};
        m_winClass = {};
    #endif
    m_windowWidth = 0;
    m_windowHeight = 0;
    m_windowX = 0;
    m_windowY = 0;
    m_windowTitle = "";
}
#ifdef _WIN32
WindowClass::WindowClass(string _windowTitle, int x, int y, int width, int height, WindowID parent, HINSTANCE hInst) {
    m_winClass = {};
    m_windowTitle = _windowTitle;
    m_windowX = x;
    m_windowY = y;
    m_windowWidth = width;
    m_windowHeight = height;
    wstring tempWideName(m_windowTitle.begin(), m_windowTitle.end());
    //MultiByteToWideChar(CP_THREAD_ACP, MB_COMPOSITE, windowTitle.c_str(), sizeof(char)*windowTitle.size(), tempWideName, 0);
    m_winClass.lpszClassName = tempWideName.c_str();
    m_winClass.hInstance = hInst;
    //winClass.lpszClassName = (LPCWSTR)windowTitle.c_str();
    m_winClass.lpfnWndProc = WindowProc;

    RegisterClass(&m_winClass);

    m_winID = CreateWindowEx(0, tempWideName.c_str(), tempWideName.c_str(), WS_OVERLAPPEDWINDOW, m_windowX, m_windowY, m_windowWidth, m_windowHeight, parent, NULL, hInst, 0);
    ShowWindow(m_winID, SW_SHOWDEFAULT);
}
#endif
#ifdef __linux 
WindowClass::WindowClass(string windowTitle, int x, int y, int width, int height, WindowID parent) {
    m_disp = XOpenDisplay(NULL);
    m_scr = XDefaultScreen(m_disp);
    if(m_disp == NULL) {
        std::cout<<"Couldn't initialize display."<<std::endl;
        exit(EXIT_FAILURE);
    }
    Window win = XCreateSimpleWindow(m_disp, RootWindow(m_disp, m_scr), x, y, width, height, 0, 0, 0);
    XMapWindow(m_disp, win);

}
#endif
ButtonID WindowClass::CreateButton(string buttonName, int x, int y, int width, int height) {
    Button *newButton = new Button(m_winID, buttonName, x, y, width, height);
    m_sparseButtonSet.insert(std::pair<ButtonID, Button>((ButtonID)*newButton, *newButton));
    return (ButtonID)*newButton;
}

Button* WindowClass::GetButtonByID(ButtonID id) {
    return &m_sparseButtonSet[id];
}

void WindowClass::EventListen() {
    #ifdef _WIN32
    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    #endif
    #ifdef __linux
        while(true) {
            XNextEvent(m_disp, &m_evt);
        }
    #endif
}
#ifdef __WIN32
LRESULT CALLBACK WindowClass::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    //TODO Create functions for each message
    //Addendum: each function for each window message will collect data that will be exposed to the programmer instead of impemnting functionality directly
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_SIZE: {
        int width = LOWORD(wParam);
        int height = HIWORD(wParam);
        return 0;
    }
    case WM_CLOSE:
        if(MessageBox(hwnd, L"Really Quit?", L"My application", MB_OKCANCEL)==IDOK) {
            DestroyWindow(hwnd);
        }
        else
            return 0;
    case WM_COMMAND:
        OutputDebugString(L"test");
        //if(LOWORD(wParam) == BN_CLICKED) {
        //        DestroyWindow((HWND)lParam);
        //        return 0;
        //}
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
#endif