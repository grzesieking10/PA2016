#include <windows.h>
#include "resource.h"

HINSTANCE hInstance;

char tekst[128] = "dowolna treœæ";
int liczba = 112;
BOOL checkbox = TRUE;
int radio = 1; //opcje, bêd¹ numerowane od 0 do 2

BOOL CALLBACK DialogProc1(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	BOOL translated;
	static const int radio_id[] = { IDC_RADIO1, IDC_RADIO2, IDC_RADIO3 };
	int id;

	switch(msg)
	{
	case WM_INITDIALOG: 
		SetDlgItemInt(hwnd, IDC_EDIT_NUM, liczba, TRUE);
		SetDlgItemText(hwnd, IDC_EDIT_TXT, tekst);
		CheckDlgButton(hwnd, IDC_CHECK1, checkbox ? BST_CHECKED : BST_UNCHECKED);
		for(id=0; id<sizeof(radio_id)/sizeof(radio_id[0]); id++)
			CheckDlgButton(hwnd, radio_id[id], id==radio ? BST_CHECKED : BST_UNCHECKED);
		return TRUE; //system ustawi focus na pierwszy element
	break;
 
	case WM_COMMAND: 
		switch(wp)
		{
		case IDOK: 
			GetDlgItemText(hwnd, IDC_EDIT_TXT, tekst, sizeof(tekst)-1);
			liczba = GetDlgItemInt(hwnd, IDC_EDIT_NUM, &translated, TRUE);
			checkbox = IsDlgButtonChecked(hwnd, IDC_CHECK1);
			for(id=0; id<sizeof(radio_id)/sizeof(radio_id[0]); id++)
				if(IsDlgButtonChecked(hwnd, radio_id[id]))
					radio = id;
			EndDialog(hwnd, IDOK); 
			return TRUE; 
		case IDCANCEL: 
			EndDialog(hwnd, IDCANCEL); 
			return TRUE; 
		}
		break;
	}
	return FALSE;
}




static char tmp[1000];

LRESULT CALLBACK wnd_proc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp) {
    switch(message) {
		case WM_COMMAND:
			switch(wp)
			{
			case ID_KASA:
				DialogBox(hInstance, //instancja
					MAKEINTRESOURCE(IDD_DIALOG2), //identyfikator zasobu
					hwnd, //uchwyt okna-rodzica
					DialogProc1); 
				break;
			case ID_POKAZDIALOG:
				DialogBox(hInstance, //instancja
					MAKEINTRESOURCE(IDD_DIALOG1), //identyfikator zasobu
					hwnd, //uchwyt okna-rodzica
					DialogProc1); 
				wsprintf(tmp, "tekst=%s, liczba=%d, radio=%d, check=%d", tekst, liczba, radio, checkbox);
				SetWindowText(hwnd, tmp);
			}
			break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
    default:
        return DefWindowProc(hwnd, message, wp, lp);
    }
    return 0;
}






int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
	::hInstance = hInstance;
    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbClsExtra = 0;
    wc.style = 0;
    wc.lpfnWndProc = wnd_proc;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));		 
    wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));	  
    wc.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1)); 
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
    wc.lpszClassName = "NAZWA_KLASY";

    RegisterClassEx(&wc);
	
	HWND window = CreateWindowEx(0, "NAZWA_KLASY", 
		"Tytu³", 
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
		NULL, NULL, hInstance, NULL);
    
	if(!window) return -1;
    
	MSG msg;
	while( GetMessage( &msg, 0, 0, 0 ) ) {
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	
	return 1;
}
