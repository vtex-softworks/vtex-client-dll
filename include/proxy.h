// Purpose: Loads the proxy library and unloads it.

#pragma once

namespace proxy
{
    /**
     * @brief Load the proxy library.
     */
	void load_actual_library();

    /**
     * @brief Unload the proxy library.
     */
	void unload_actual_library();
}