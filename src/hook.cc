#include "hook.h"

BYTE* hooking::pHookStorage = nullptr;
DWORD hooking::dwOld		= 0;

void
hooking::add_jmp(BYTE* pAddr, const void* func, std::size_t size)
{
	if (size < 5)
		return;

	::VirtualProtect(pAddr, size, PAGE_EXECUTE_READWRITE, &dwOld);
	auto relative_address = (reinterpret_cast<std::uintptr_t>(func) - reinterpret_cast<std::uintptr_t>(pAddr)) - 0x5;

	*pAddr = 0xE9;

	*reinterpret_cast<std::uintptr_t*>(pAddr + 1) = relative_address;
	::VirtualProtect(pAddr, size, dwOld, &dwOld);
}

void
hooking::remove_jmp(BYTE* pAddr, std::size_t size)
{
	if (size < 5)
		return;

	::VirtualProtect(pAddr, size, PAGE_EXECUTE_READWRITE, &dwOld);
	std::memcpy(pAddr, pHookStorage, size);
	::VirtualProtect(pAddr, size, dwOld, &dwOld);
}

void
hooking::store_bytes(BYTE* pAddr, int size)
{
	pHookStorage = new BYTE[size];
	std::memcpy(pHookStorage, pAddr, size);
}

void
hooking::detour_function(BYTE* pAddr, const void* func, std::size_t size, ::hooking::detour_mode m)
{
	if (m == ::hooking::detour_mode::create)
		add_jmp(pAddr, func, size);
	else
		remove_jmp(pAddr, size);
}