#include <windows.h>
#include <cstdint>

#define WM_INIT		(WM_USER  + 1000)
int32_t x = 10, y = 10, vx = 5, vy = 7, dx = 40, dy = 40;

void on_paint(HWND hwnd) 
{
	static PAINTSTRUCT ps;
	BeginPaint(hwnd, &ps);
	HPEN hpen = CreatePen(PS_SOLID, 3, RGB(255,0,0)); //todo: zoptymalizowaæ!
	HBRUSH hbrush = CreateSolidBrush(RGB(0,255,0));
	SelectObject(ps.hdc, hpen);
	SelectObject(ps.hdc, hbrush);
	Rectangle(ps.hdc, x, y, x+dx, y+dy);
	SelectObject(ps.hdc, GetStockObject(NULL_PEN));
	SelectObject(ps.hdc, GetStockObject(NULL_BRUSH));
	DeleteObject(hpen);
	DeleteObject(hbrush);
	EndPaint(hwnd, &ps);
}

void on_timer(HWND hwnd)
{
	static RECT r;
	GetClientRect(hwnd, &r);
	if(x+vx+dx > (r.right-r.left) || x+vx < 0) 
		vx = -vx;
	if(y+vy+dx > (r.bottom-r.top) || y+vy < 0) 
		vy = -vy;
	x += vx;
	y += vy;
	InvalidateRect(hwnd, NULL, TRUE); 
	UpdateWindow(hwnd);
}

void on_init(HWND hwnd)
{
	SetTimer(hwnd, 1, 50, NULL);
}

void on_close(HWND hwnd)
{
	KillTimer(hwnd, 1);
	DestroyWindow(hwnd); 			
}


LRESULT CALLBACK wnd_proc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp) 
{
	switch(message) 
	{
		case WM_INIT: //komunikat zdefiniowany przez u¿ytkownika!
			on_init(hwnd);
			break;

		case WM_PAINT:
			on_paint(hwnd);
			break;
		
		case WM_TIMER: 
			switch(wp) 
			{
				case 1: 
					on_timer(hwnd);
					break;
			}
			break;

		case WM_CLOSE: 
			on_close(hwnd);
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
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "NAZWA_KLASY";
    RegisterClassEx(&wc);
	
	HWND window = CreateWindowEx(0, "NAZWA_KLASY", "Tytu³", 
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
		NULL, NULL, hInstance, NULL);    
	if(!window) return -1;
    
	PostMessage(window, WM_INIT, 0, 0); //nasz w³asny komunikat wysy³any do okna po jego utworzeniu

	MSG msg;
	while(GetMessage(&msg, 0, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 1;
}
