#include "main.h"
#include "proxy.h"
#include "stdafx.h"

#include <mutex>

/**
 * @brief DllMain entry point.
 * @param hModule Handle to the DLL module.
 * @param ul_reason_for_call Reason for calling the DLL.
 * @param lpReserved Reserved parameter.
 * @return True if the function succeeded, false otherwise.
 */
BOOL APIENTRY
DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID)
{
	static std::once_flag initFlag;
	static std::once_flag cleanupFlag;

	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			std::call_once(initFlag, [&]() {
				CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(main), NULL, NULL, NULL);

				proxy::load_actual_library();
			});

			break;

		case DLL_PROCESS_DETACH:
			std::call_once(cleanupFlag, [&]() { proxy::unload_actual_library(); });
			break;

		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		default:
			break;
	}

	return TRUE;
}