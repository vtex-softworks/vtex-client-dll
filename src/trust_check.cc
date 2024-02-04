#include "trust_check.h"
#include "hook.h"
#include "stdafx.h"

/**
 * @brief The trust check domains.
*/
static trust_check_patch trust_check_patches[] =
{
    // PRODUCTION
	{push_roblox_com_address_1, vtex_production_domain},
	{push_roblox_com_address_2, vtex_production_domain},
	{push_roblox_com_address_3, vtex_production_domain},
	{push_roblox_com_address_4, vtex_production_domain},

    // INTRANET
	{push_robloxlabs_com_address_1, vtex_intranet_domain},
	{push_robloxlabs_com_address_2, vtex_intranet_domain},
	{push_robloxlabs_com_address_3, vtex_intranet_domain},
	{push_robloxlabs_com_address_4, vtex_intranet_domain},
	{push_robloxlabs_com_address_5, vtex_intranet_domain}
};

void
patch_trust_check_domains()
{
	for (auto& domain : trust_check_patches)
	{
		BYTE* address = reinterpret_cast<BYTE*>(ASLR_ADDR(domain.address));

		WriteProcessMemory(GetCurrentProcess(), address + 1, &domain.domain, 0x4, NULL);
	}
}

void
remove_trust_check()
{
	void* lpAddr   = reinterpret_cast<void*>(ASLR_ADDR(trust_check_addr));
	void* lpBuffer = reinterpret_cast<void*>(0xEB);	 // short jmp

	WriteProcessMemory(GetCurrentProcess(), lpAddr, lpBuffer, 0x1, NULL);
}