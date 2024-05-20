#pragma once

#ifdef _WIN32
#include <Windows.h>
typedef HWND WindowID;
typedef HWND ButtonID
#ifndef UNICODE
#define UNICODE
#endif
#define WINDOW_DIMS_UNDEFINED CW_USEDEFAULT
#endif
#ifdef __linux
#include <X11/Xlib.h>
typedef Window WindowID;
//TODO find out how to do buttons in X11 (placeholder type to avoid errors)
typedef size_t ButtonID;
#endif

//ensuring compadibility bc i'm petty
//don't know why this one wouldn't be defined though, just wanted to include it just bc
#ifndef EXIT_FALIURE
#define EXIT_FALIURE 1
#endif