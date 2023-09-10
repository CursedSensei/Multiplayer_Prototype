#include "Framework.h"

LRESULT CALLBACK Wndproc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

_Use_decl_annotations_ int WINAPI WinMain(HINSTANCE hInst, HINSTANCE pInst, LPSTR cmdline, int cmdshow) {

	UNREFERENCED_PARAMETER(pInst);
	UNREFERENCED_PARAMETER(cmdline);

	HWND previnst = FindWindow(ClassName, WindowName);
	if (previnst != NULL) {
		SetForegroundWindow(previnst);
		CloseHandle(previnst);
		return 0;
	}

	WNDCLASS wc = { };
	wc.lpszClassName = ClassName;
	wc.lpfnWndProc = Wndproc;
	wc.hInstance = hInst;

	RegisterClass(&wc);

	HWND hMain = CreateWindowExW(
		0,
		ClassName,
		WindowName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInst,
		NULL);

	if (hMain == NULL) {
		return -1;
	}
	
	ShowWindow(hMain, cmdshow);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK Wndproc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}