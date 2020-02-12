#include<Windows.h>
#include<iostream>
#include<string>
#include<sstream>
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		
		break;
	case WM_KEYUP:
	
		break;
	case WM_CHAR://字符键被按下时产生的消息
		//{
		//	static std::wstring title;
		//	title.push_back((char)wParam);
		//	SetWindowText(hWnd, title.c_str());
		//}
		break;
	case WM_LBUTTONDOWN:
		{
			const POINTS pt = MAKEPOINTS(lParam);
			std::wostringstream oss;
			oss << '(' << pt.x << ',' <<pt.y<< ")";
			SetWindowText(hWnd, oss.str().c_str());
		}
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	const auto pClassName = L"h3dWindowClass";
	//注册windowcalss
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = nullptr;
	wc.hCursor = nullptr;
	wc.hIcon = nullptr;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = pClassName;
	wc.lpszMenuName = nullptr;
	wc.style = CS_OWNDC;
	RegisterClassEx(&wc);

	//注册windowInstance
	HWND hWnd = CreateWindowExW(
		0, pClassName,
		L"d3dGameWindow",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200,
		800, 600,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);
	ShowWindow(hWnd, SW_SHOW);

	//message 处理

	MSG msg;
	BOOL gResult;
	while ((gResult =GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}


	//程序结束时返回信息
	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}