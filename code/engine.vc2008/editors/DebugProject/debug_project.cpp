#include <vcl.h>
#pragma hdrstop

#include <d3d9.h>


const char g_szClassName[] = "myWindowClass";

//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE , HINSTANCE, LPTSTR, int)
{
	//MessageBox(NULL, "as", "as", MB_OK);

		WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
    HINSTANCE hInst = nullptr;

	wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = NULL;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInst;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "The title of my window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
        NULL, NULL, hInst, NULL);

    ShowWindow(hwnd, true);
	UpdateWindow(hwnd);

	IDirect3D9* pD3D 					= Direct3DCreate9( D3D_SDK_VERSION );


	D3DPRESENT_PARAMETERS P;        //Структура с помощью которой передаем информацию устройству рендеринга при его создании
	ZeroMemory(&P,sizeof(P));    //Обнуляем


	P.BackBufferWidth		= 200;
	P.BackBufferHeight		= 200;
	P.BackBufferFormat		= D3DFMT_X8R8G8B8;
	P.BackBufferCount		= 1;

	// Multisample
    P.MultiSampleType		= D3DMULTISAMPLE_NONE;
	P.MultiSampleQuality	= 0;

	// Windoze
	P.SwapEffect			= D3DSWAPEFFECT_COPY;
	P.hDeviceWindow			= hwnd;
    P.Windowed				= true;

	// Depth/stencil
	P.EnableAutoDepthStencil= true;
    P.AutoDepthStencilFormat= D3DFMT_D24S8;
	P.Flags					= 0;

	// Refresh rate
	P.PresentationInterval	= D3DPRESENT_INTERVAL_IMMEDIATE;
    P.FullScreen_RefreshRateInHz	= D3DPRESENT_RATE_DEFAULT;

    IDirect3DDevice9*		pDevice = nullptr;
	HRESULT R	= pD3D->CreateDevice(0,
										D3DDEVTYPE_HAL,
										hwnd,
										D3DCREATE_SOFTWARE_VERTEXPROCESSING,
										&P,
										&pDevice );

	switch(R){
		case D3D_OK:
			break;

		case D3DERR_DEVICELOST:
			break;

		case D3DERR_INVALIDCALL:
			break;

		case D3DERR_NOTAVAILABLE:
			break;

		case D3DERR_OUTOFVIDEOMEMORY:
			break;

		default:
			break;
	}
    return 0;
}

