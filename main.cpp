#include "GeoEmu.h"
#include "Log.h"
#include <string>
#include <sstream>

#include ""

#define MAX_LOADSTRING 100

// Global Variables:

HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
                     {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CYGEO, szWindowClass, MAX_LOADSTRING);

    if (!MyRegisterClass(hInstance))
    {
        return FALSE;
    }

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GEO));
    MSG msg;
    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int) msg.wParam;

    // Geo Emulator
    GeoEmulator GeoEmulator;

    // Load DISC ROM
    std::string romFile = "path_to_your_rom.bin";
    if (!GeoEmulator.loadRom(romFile)) {
        std::stringstream ss;
        ss << "Failed to load ROM: " << romFile;
        Log::error(ss.str());
        return 1;
    }

    // Start emulation
    GeoEmulator.run();

    return 0;
}
