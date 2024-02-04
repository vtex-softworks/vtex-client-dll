#include "debug_console.h"
#include "signature_check.h"
#include "trust_check.h"

/**
 * @brief Entry point.
 * @return 0
 */
const bool trust_check_enabled = true;

/**
 * @brief Entry point.
 * @return 0
 */
int
main()
{
#ifdef _DEBUG
    spawn_console("Debug Console");
#endif

    if (trust_check_enabled)
        patch_trust_check_domains();
    else
        remove_trust_check();

    remove_signature_check();

    return 0;
}