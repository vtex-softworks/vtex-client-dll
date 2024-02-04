/**
 * @file debug_console.h
 * @brief Debug console.
 * @details This file contains functions for creating a debug console, only present in debug builds.
 */

#pragma once

#ifdef _DEBUG
#include "stdafx.h"

/**
 * @brief Spawns a debug console.
 * @param lpName The name of the console.
 * @details Hack to spawn a console from a DLL.
 */
void spawn_console(LPCSTR lpName);
#endif