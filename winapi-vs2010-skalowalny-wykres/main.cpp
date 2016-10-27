#include <windows.h>
#include <cmath>

double minx = -14, maxx = +14, miny = -2, maxy = +2;

void paint(HDC hdc, double ux, double uy, int w, int h) 
{
	int sx = (ux - minx) * w/(maxx-minx);
	int sy = (-uy - miny) * h/(maxy-miny);
	SetPixel(hdc, sx, sy, RGB(0,0,255));
	//LineTo(hdc, sx, sy);
}

void draw(HDC hdc, int w, int h)
{
	double step = (maxx - minx) / w;
	for(double x = minx; x<maxx; x += step)
	{
		double y = sin(x);
		paint(hdc, x, y, w, h);
	}
}

LRESULT CALLBACK wnd_proc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp) 
{
	switch(message) 
	{
	case WM_SIZE:
	case WM_SIZING:
		InvalidateRect(hwnd, NULL, TRUE);
		UpdateWindow(hwnd);
		break;

	case WM_PAINT:
		{
		static RECT r;
		GetClientRect(hwnd, &r);

		static PAINTSTRUCT ps;
		BeginPaint(hwnd, &ps);
		draw(ps.hdc, r.right-r.left, r.bottom - r.top);
		EndPaint(hwnd, &ps);
		}
		break;

    case WM_DESTROY: 
		PostQuitMessage(0); 
		break;

    default: 
		return DefWindowProc(hwnd, message, wp, lp);
    }
    return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {

    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbClsExtra = 0;
    wc.style = 0;
    wc.lpfnWndProc = wnd_proc;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //IDI_SHIELD
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "KLASA_PA";

    RegisterClassEx(&wc);
	
	HWND window = CreateWindowEx(0, "KLASA_PA", "Programowanko aplikacyjne", 
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 10, 10, 900, 300, NULL, NULL, hInstance, NULL);
    
	if(!window) return -1;
    
	MSG msg;
	while( GetMessage( &msg, 0, 0, 0 ) ) {
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	
	return 1;
}
