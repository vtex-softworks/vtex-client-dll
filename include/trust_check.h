/**
 * @file domains.h
 * @brief Constants for domains.
*/

#pragma once

#include <cstdint>
#include "addresses.h"

/**
 * @brief The production domain.
*/
const char* const vtex_production_domain = "vortexsoftworks.llc";

/**
 * @brief The intranet domain.
*/
const char* const vtex_intranet_domain = "vtex.local";

/**
 * @brief The trust check domain patches.
*/
struct trust_check_patch
{
    /**
     * @brief The address.
    */
	std::int32_t address;

    /**
     * @brief The domain.
    */
	const char* domain;
};

/**
 * @brief Patches the trust check domains.
*/
void patch_trust_check_domains();

/**
 * @brief Removes the trust check all together.
*/
void remove_trust_check();