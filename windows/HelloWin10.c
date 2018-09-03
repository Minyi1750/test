#include<Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstantance,
	PSTR szCmdLine, int iCmdShow) {

	MessageBox(NULL, TEXT("Hello world, windows 10!"), TEXT("HellogMsg"), 0);

	return 0;
}