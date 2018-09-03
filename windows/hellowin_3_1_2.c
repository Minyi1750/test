#include<Windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lparam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstantance,
	PSTR szCmdLine, int iCmdShow) {

	static TCHAR szAppname[] = TEXT("HelloWin");

	HWND hwnd;
	MSG msg;

	WNDCLASS wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppname;

	if (!RegisterClass(&wndclass)) {
		MessageBox(NULL, TEXT("This program requireswindows nt!"),
			szAppname, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppname,
		TEXT("The hello Program"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lparam) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	
	switch (message)
	{

	//case WM_CREATE:
	//	PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//	return 0;



	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rect);

		DrawText(hdc, TEXT("Hellow , win10"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);

		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}
	return DefWindowProc(hwnd, message, wParam, lparam);
}