#include "signature_check.h"
#include "addresses.h"
#include "hook.h"
#include "stdafx.h"

namespace
{
	void detour() {}
}

void
remove_signature_check()
{
	BYTE* address = reinterpret_cast<BYTE*>(ASLR_ADDR(signature_check_addr));

	::hooking::store_bytes(address, 0x5);  // store the bytes
	::hooking::detour_function(address, reinterpret_cast<void*>(::detour), 0x5, ::hooking::detour_mode::create);
}