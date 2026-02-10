#define NOMINMAX // 防止 Windows.h 定义 min 和 max 宏，影响 std::min 和 std::max
#include<Windows.h>
#include<iostream>
#include<thread>
#include<v8.h>
#include <libplatform/libplatform.h>
#include"system.h"
#include"js_engine.h"


using namespace v8;
using namespace std;

bool g_unload = false;
bool g_reload = false;
bool g_exit = false;



void HotkeyThread() {

	if (RegisterHotKey(NULL, 1001, NULL, VK_HOME) &&
		RegisterHotKey(NULL, 1002, NULL, VK_END) &&
		RegisterHotKey(NULL, 1003, NULL, VK_F4)
		) {//无法跨线程使用窗口句柄注册热键
		std::cout << "热键注册成功！" << std::endl;
	}
	else {
		std::cout << "热键注册失败！" << std::endl;
	}

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		if (msg.message == WM_HOTKEY && msg.wParam == 1001) {
			std::cout << "HOME 热键触发" << std::endl;
			g_reload = true;
		}
		if (msg.message == WM_HOTKEY && msg.wParam == 1002) {
			std::cout << "END 热键触发" << std::endl;
			g_unload = true;
		}
		if (msg.message == WM_HOTKEY && msg.wParam == 1003) {
			g_exit = true;
			break;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	UnregisterHotKey(NULL, 1001);
	UnregisterHotKey(NULL, 1002);
	UnregisterHotKey(NULL, 1003);
	return;
}

int main()
{
	SetConsoleOutputCP(CP_UTF8); // 设置控制台输出 UTF-8
	System::PrintLn(LEVEL::SUCCESS, "程序开始运行！");

	std::unique_ptr<Platform> platform = platform::NewDefaultPlatform();//不需要手动删除，unique_ptr 会自动释放
	V8::InitializePlatform(platform.get());
	V8::Initialize();

	JsEngine::GetInstance().LoadScript("main.js");

	HANDLE hHotKeyThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HotkeyThread, NULL, 0, NULL);


	while (true) {
		if (g_reload) {
			g_reload = false;
			System::PrintLn(LEVEL::INFO, "Reloading scripts...");
			//ctx->run_file("script.js");
			System::PrintLn(LEVEL::INFO, "Scripts reloaded.");
		}
		if (g_unload) {
			g_unload = false;
			System::PrintLn(LEVEL::INFO, "Scripts unloaded.");
		}
		if (g_exit) {
			break;
		}
		Sleep(3000);
	}

	JsEngine::GetInstance().UnloadAllScripts();

	TerminateThread(hHotKeyThread, 0);
	// 等待线程完成
	WaitForSingleObject(hHotKeyThread, INFINITE);
	// 关闭线程句柄
	CloseHandle(hHotKeyThread);
	System::PrintLn(LEVEL::INFO, "线程已经强制关闭！");


	V8::Dispose();
	V8::DisposePlatform();
	return 0;
}
