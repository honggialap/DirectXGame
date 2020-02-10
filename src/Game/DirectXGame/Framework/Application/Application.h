#include <Windows.h>

class Application
{
	//Singleton
private:
	static Application* __instance;
	Application();
public:
	static Application* GetInstance();
	~Application();


	//Win32 API
private:
	HINSTANCE hInstance;
	HWND hWnd;

public:
	HINSTANCE GetAppInstance() { return hInstance; }
	HWND GetWindow() { return hWnd; }
	
	HWND CreateGameWindow();
	bool HandleMessage();
	static LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	

	//Framework component
public:
	void Initialize(HINSTANCE hInstance);
	void Shutdown();
};

typedef Application* pApplication;