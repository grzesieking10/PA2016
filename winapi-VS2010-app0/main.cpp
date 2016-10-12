#include <Windows.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	int result = MessageBox(HWND_DESKTOP, "Hello, world!", "", 0);
	return result;
}
