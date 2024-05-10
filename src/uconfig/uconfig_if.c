/**
 * @file uconfig_if.c
 * @author vhex (visual86n@outlook.com)
 * @brief This file is uconfig user interface source file.
 * @version 0.1
 * @date 2024-01-04
 *
 * SPDX-FileCopyrightText: Copyright (c) 2024
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include <stddef.h>

#include "uconfig_if.h"
#include "ULib.h"

PACK(struct uconfig_inst {
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    uint32_t magic;
});

const struct uconfig_inst __ext_uconfig_inst_dflt = {
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    .magic = 0x11223344,
};
struct uconfig_inst __ext_uconfig_inst  = {0};
const uint8_t __ext_uconfig_field_map[] = {
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    offsetof(struct uconfig_inst, magic),
    sizeof(struct uconfig_inst),
};
const uint8_t __ext_uconfig_field_map_max = sizeof(__ext_uconfig_field_map) - 1;
const uint8_t __ext_uconfig_inst_max      = sizeof(struct uconfig_inst);

// ------------------------------------------------------------------------
//                           User Implementation
// ------------------------------------------------------------------------
/**
 * @brief Initialize the user configuration interface.
 *
 * @return int: The status code of the initialization.
 *
 * @retval UCONFIG_IF_SUCCESS: Initialization success
 * @retval Other: Initialization failure
 */
int uconfig_if_init(void)
{
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    return UCONFIG_IF_SUCCESS;
}

/**
 * @brief Deinitialize the user configuration interface.
 *
 * @return int: The status code of the Deinitialization.
 *
 * @retval UCONFIG_IF_SUCCESS: Deinitialization success
 * @retval Other: Denitialization failure
 */
int uconfig_if_deinit(void)
{
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    return UCONFIG_IF_SUCCESS;
}

/**
 * @brief Read data from persistent storage
 *
 * @note This function need user implement
 *
 * @param field The field to be read
 * @param data Pointer to the data buffer
 * @param size Size of the data buffer
 *
 * @return int: uconfig error code
 *
 * @retval UCONFIG_IF_SUCCESS: if the data was successfully written
 * @retval Other: interface return error
 */
int uconfig_if_read(const uint32_t field, uint8_t *data, const uint32_t size)
{
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    return UCONFIG_IF_SUCCESS;
}

/**
 * @brief Write data from persistent storage
 *
 * @note This function need user implement
 *
 * @param field The field to write data to
 * @param data Pointer to the data to be written
 * @param size Size of the data
 *
 * @return int: uconfig error code
 *
 * @retval UCONFIG_IF_SUCCESS: if the data was successfully written
 * @retval Other: interface return error
 */
int uconfig_if_write(const uint32_t field, const uint8_t *data,
                     const uint32_t size)
{
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    return UCONFIG_IF_SUCCESS;
}
