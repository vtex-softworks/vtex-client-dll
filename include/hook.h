/**
 * hook.h
 */

#pragma once

#include <stdafx.h>

#define ASLR_ADDR(addr) (addr - 0x400000 + reinterpret_cast<std::uintptr_t>(GetModuleHandleA(NULL)))

/**
 * @brief Hooking class.
 */
class hooking
{
private:
	static BYTE* pHookStorage;
	static DWORD dwOld;

	static void add_jmp(BYTE* pAddr, const void* func, std::size_t size);
	static void remove_jmp(BYTE* pAddr, std::size_t size);

public:

    /**
     * @brief Detour mode.
     */
	enum class detour_mode : std::uint32_t
	{
        /**
         * Create a detour.
         */
		create = 1,

        /**
         * Remove a detour.
         */
		remove = 0
	};

    /**
     * @brief Store bytes.
     * @param pAddr Pointer to the address.
     * @param size Size of the bytes.
     */
	static void store_bytes(BYTE* pAddr, int size);

    /**
     * @brief Detour function.
     * @param pAddr Pointer to the address.
     * @param func Function to detour.
     * @param size Size of the bytes.
     * @param m Detour mode.
     */
	static void detour_function(BYTE* pAddr, const void* func, std::size_t size, ::hooking::detour_mode m);
};