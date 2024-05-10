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
#include <string.h>

#include "test_uconfig_if.h"

PACK(struct uconfig_inst {
    // ----Instance declaration----
    // -------User Implement-------
    bool f1;
    uint8_t f2;
    uint16_t f3;
    uint32_t f4;
    uint64_t f5;
    float f6;
    double f7;
    char f8[6];
    // ----------------------------
    uint32_t magic;
});

bool f1     = false;
uint8_t f2  = 0x55;
uint16_t f3 = 0x1234;
uint32_t f4 = 0x12345678;
uint64_t f5 = 0x123456789ABCDEF0;
float f6    = 6.283185307179586F;
double f7   = 1.777777777777777;
char f8[6]  = {'1', '2', '3', '4', '5', '6'};
uint32_t magic;

const struct uconfig_inst __ext_uconfig_inst_dflt = {
    // -------Default Value--------
    // -------User Implement-------
    .f1 = true,
    .f2 = 0xAA,
    .f3 = 0xAA55,
    .f4 = 0x11223344,
    .f5 = 0x1122334455667788,
    .f6 = 3.141592653589793F,
    .f7 = 1.333333333333333,
    .f8 = {'a', 'b', 'c', 'd', 'e', 'f'},
    // ----------------------------
    .magic = 0x11223344,
};
struct uconfig_inst __ext_uconfig_inst  = {0};
const uint8_t __ext_uconfig_field_map[] = {
    // -------Field offset---------
    // -------User Implement-------
    offsetof(struct uconfig_inst, f1),
    offsetof(struct uconfig_inst, f2),
    offsetof(struct uconfig_inst, f3),
    offsetof(struct uconfig_inst, f4),
    offsetof(struct uconfig_inst, f5),
    offsetof(struct uconfig_inst, f6),
    offsetof(struct uconfig_inst, f7),
    offsetof(struct uconfig_inst, f8),
    // ----------------------------
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
 * @details This function initializes the user configuration interface.
 *
 * @return int: The status code of the initialization.
 *
 * @retval UCONFIG_IF_SUCCESS: Initialization success
 * @retval Other: Initialization failure
 */
int uconfig_if_init(void)
{
    // ---------------Initialize---------------
    // -------------User Implement-------------

    // ----------------------------------------
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
    // --------------Read data from persistent storage-------------
    // ----------------------User Implement------------------------
    switch (field) {
        case 0:
            memcpy(data, &f1, size);
            break;
        case 1:
            memcpy(data, &f2, size);
            break;
        case 2:
            memcpy(data, &f3, size);
            break;
        case 3:
            memcpy(data, &f4, size);
            break;
        case 4:
            memcpy(data, &f5, size);
            break;
        case 5:
            memcpy(data, &f6, size);
            break;
        case 6:
            memcpy(data, &f7, size);
            break;
        case 7:
            memcpy(data, f8, size);
            break;
        case 8:
            memcpy(data, &magic, size);
            break;
        default:
            // no such field
            return 1;
    }
    // ------------------------------------------------------------

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
    // --------------Write data from persistent storage-------------
    // ----------------------User Implement------------------------
    switch (field) {
        case 0:
            memcpy(&f1, data, size);
            break;
        case 1:
            memcpy(&f2, data, size);
            break;
        case 2:
            memcpy(&f3, data, size);
            break;
        case 3:
            memcpy(&f4, data, size);
            break;
        case 4:
            memcpy(&f5, data, size);
            break;
        case 5:
            memcpy(&f6, data, size);
            break;
        case 6:
            memcpy(&f7, data, size);
            break;
        case 7:
            memcpy(f8, data, size);
            break;

        case 8:
            memcpy(&magic, data, size);
            break;

        default:
            return 1;
    }
    // ------------------------------------------------------------

    return UCONFIG_IF_SUCCESS;
}
