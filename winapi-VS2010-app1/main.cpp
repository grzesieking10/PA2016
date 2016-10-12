#include <windows.h>

//funkcja obs³ugi komunikatów okna
LRESULT CALLBACK wnd_proc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp) 
{
    switch(message) 
	{
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
		break;

    default:
        return DefWindowProc(hwnd, message, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) 
{
	//rejestracja klasy okienkowej
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbClsExtra = 0;
    wc.style = 0;
    wc.lpfnWndProc = wnd_proc;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "NAZWA_KLASY";
    RegisterClassEx(&wc);
	
	//tworzenie okna...
	HWND window = CreateWindowEx(0, "NAZWA_KLASY", "Tytu³ okienka", 
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
		NULL, NULL, hInstance, NULL); 
	if(NULL == window) return -1; //...i sprawdzenie, czy siê uda³o
    
	//pêtla obs³ugi komunikatów
	MSG msg;
	while(GetMessage(&msg, 0, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 1;
}
