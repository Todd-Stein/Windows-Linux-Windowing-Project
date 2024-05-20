#pragma once
#include "TypeDeclarations.h"
#ifdef _WIN32
#include <Windows.h>
#endif


class WindowIDHash {
public:
    size_t operator() (const WindowID handle) const {
        return reinterpret_cast<size_t>(handle);
    }
};