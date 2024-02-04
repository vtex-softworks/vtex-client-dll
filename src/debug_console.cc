#include "debug_console.h"

#ifdef _DEBUG
void
spawn_console(LPCSTR lpTitle)
{
	DWORD dwOld;
	void* freeConsole = reinterpret_cast<void*>(&FreeConsole);

	::VirtualProtect(freeConsole, 1, PAGE_EXECUTE_READWRITE, &dwOld);
	std::memset(freeConsole, 0xC3, 1);
	::VirtualProtect(freeConsole, 1, dwOld, &dwOld);

	::AllocConsole();
	::SetConsoleTitleA(lpTitle);

	freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);

	HWND ConsoleHandle = GetConsoleWindow();
	::SetWindowPos(ConsoleHandle, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
	::ShowWindow(ConsoleHandle, SW_NORMAL);
}
#endif