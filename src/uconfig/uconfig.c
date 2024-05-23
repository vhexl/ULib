/**
 * @file uconfig.c
 * @author vhex (visual86n@outlook.com)
 * @brief This is util config source file.
 * @version 0.1
 * @date 2023-12-30
 *
 * SPDX-FileCopyrightText: Copyright (c) 2024
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include "stdio.h"
#include "string.h"
#include "stddef.h"

#include "uconfig.h"
#include "uconfig_if.h"

// ------------------------------------------------------------------------
//                          External Variables
// ------------------------------------------------------------------------
extern const struct uconfig_inst __ext_uconfig_inst_dflt;
extern struct uconfig_inst __ext_uconfig_inst;
extern const uint8_t __ext_uconfig_field_map[];
extern const uint8_t __ext_uconfig_field_map_max;
extern const uint8_t __ext_uconfig_inst_max;

// ------------------------------------------------------------------------
//                          Private Variables
// ------------------------------------------------------------------------

// ------------------------------------------------------------------------
//                             Private Macro
// ------------------------------------------------------------------------

#define UCFG_FIELD_SIZE(field)                                                 \
    ((uint32_t)(__ext_uconfig_field_map[field + 1] -                           \
                __ext_uconfig_field_map[field]))

#define UCFG_FIELD_IDX(field)                                                  \
    (((uint8_t *)(&__ext_uconfig_inst)) + __ext_uconfig_field_map[field])

// ------------------------------------------------------------------------
//                           Public Functions
// ------------------------------------------------------------------------

/**
 * @brief Read data from a specific field in the configuration.
 *
 * This function reads the data from the specified field in the configuration
 * and stores it in the provided data buffer.
 *
 * @param field The index of the field to read from.
 * @param data Pointer to the buffer where the data will be stored.
 * @param size The size of the data to be read.
 *
 * @return int uconfig error code
 *
 * @retval UCFG_SUCCESS: if the operation was successful
 * @retval UCFG_ERROR_INVALID_FIELD: if the field index is invalid
 * @retval UCFG_ERROR_SIZE_MISMATCH: if the size does not match the expected
 * size for the field.
 */
int ucfg_read(const uint32_t field, uint8_t *data, const uint32_t size)
{
    // Check if field index is valid
    if (field >= __ext_uconfig_field_map_max) {
        return UCFG_ERROR_INVALID_FIELD;
    }

    // Check if size matches expected size for the field
    if (size != UCFG_FIELD_SIZE(field)) {
        return UCFG_ERROR_SIZE_MISMATCH;
    }

    // Read from memory and store in data buffer
    memcpy(data, UCFG_FIELD_IDX(field), size);

    UCFG_LOG("UCFG Read: ");
    UCFG_FIELD_PRINT(field, data, size);

    return UCFG_SUCCESS;
}

/**
 * @brief Writes configuration data to memory and persistent storage.
 *
 * This function writes the specified configuration data to both memory and
 * persistent storage. The field and size parameters determine the specific
 * configuration data to be written.
 *
 * @param field The field identifier for the configuration data to be written.
 * @param data Pointer to the configuration data to be written.
 * @param size Size of the configuration data to be written.
 *
 * @return int uconfig error code
 *
 * @retval UCFG_SUCCESS: if the write operation is successful
 * @retval UCFG_ERROR_INVALID_FIELD: if the field identifier is invalid,
 * @retval UCFG_ERROR_SIZE_MISMATCH: if the size of the data does not match
 *         the expected size for the specified field.
 *
 * @retval Other: interface return error
 */
int ucfg_write(const uint32_t field, const uint8_t *data, const uint32_t size)
{
    // Check if field identifier is valid
    if (field >= __ext_uconfig_field_map_max) {
        return UCFG_ERROR_INVALID_FIELD;
    }

    // Check if size matches the expected size for the specified field
    if (size != UCFG_FIELD_SIZE(field)) {
        return UCFG_ERROR_SIZE_MISMATCH;
    }

    UCFG_LOG("UCFG Write: ");
    UCFG_FIELD_PRINT(field, data, size);

    // Write the configuration data to persistent storage
    int ret = uconfig_if_write(field, data, size);
    if (ret != UCFG_SUCCESS) {
        return ret;
    }

    // Write the configuration data to memory
    memcpy(UCFG_FIELD_IDX(field), data, size);

    return UCFG_SUCCESS;
}

/**
 * @brief Restores the uconfig instance to default values.
 *
 * This function copies the default uconfig instance to the current instance,
 * and then writes the values from the current instance to their respective
 * positions in the default instance.
 *
 * @return int uconfig error code
 *
 * @retval UCFG_SUCCESS: The restoration was successful.
 * @retval Other: If an error occurred during the restoration process.
 */
int ucfg_restore(void)
{
    memcpy(&__ext_uconfig_inst, &__ext_uconfig_inst_dflt,
           __ext_uconfig_inst_max);

    for (size_t i = 0; i < __ext_uconfig_field_map_max; i++) {
        int ret = ucfg_write(i, UCFG_FIELD_IDX(i), UCFG_FIELD_SIZE(i));
        if (ret != UCFG_SUCCESS) {
            return ret;
        }
    }

    return UCFG_SUCCESS;
}

/**
 * @brief Initializes and read the uconfig module.
 *
 * @return int uconfig error code
 *
 * @retval UCFG_SUCCESS: Initialization successful.
 * @retval Other: Initialization failed.
 */
int ucfg_init(void)
{
    int ret = uconfig_if_init();
    if (ret != UCFG_SUCCESS) {
        return ret;
    }

    for (size_t i = 0; i < __ext_uconfig_field_map_max; i++) {
        ret = uconfig_if_read(i, UCFG_FIELD_IDX(i), UCFG_FIELD_SIZE(i));
        if (ret != UCFG_SUCCESS) {
            return ret;
        }

        UCFG_FIELD_PRINT(i, UCFG_FIELD_IDX(i), UCFG_FIELD_SIZE(i));
    }

    return UCFG_SUCCESS;
}

/**
 * @brief Deinitializes the uconfig module.
 *
 * @return int From uconfig_if_deinit error code
 */
int ucfg_deinit(void)
{
    return uconfig_if_deinit();
}
