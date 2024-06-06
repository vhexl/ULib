/**
 * @file uconfig.h
 * @author vhex (visual86n@outlook.com)
 * @brief This is util config header file.
 * @version 0.1
 * @date 2023-12-30
 *
 * SPDX-FileCopyrightText: Copyright (c) 2024
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef __UCONFIG_H
#define __UCONFIG_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define UCFG_DEBUG 0

#if UCFG_DEBUG == 1
// Enable debug
#define UCFG_PARAM_ASSERT(exp)                                                 \
    if (!(exp)) {                                                              \
        while (1)                                                              \
            ;                                                                  \
    }
#define UCFG_LOGE(fmt, ...) printf("[error] " fmt, ##__VA_ARGS__)
#define UCFG_LOGI(fmt, ...) printf("[info] " fmt, ##__VA_ARGS__)
#define UCFG_FIELD_PRINT(field, val, sz)                                       \
    do {                                                                       \
        printf("Field [%d]: ", field);                                         \
        for (unsigned int idx = 0; idx < sz; idx++)                            \
            printf("0x%02X ", *((val) + idx));                                 \
        printf("\n");                                                          \
    } while (0)

#else
// Disable debug
#define UCFG_PARAM_ASSERT(exp)
#define UCFG_LOG(fmt, ...)
#define UCFG_FIELD_PRINT(field, val, sz)
#endif

enum ucfg_ret {
    UCFG_SUCCESS = 0,
    UCFG_ERROR_INVALID_FIELD,
    UCFG_ERROR_SIZE_MISMATCH,
    // handle error
    UCFG_ERROR_INVAILD_PARAM,
    UCFG_ERROR_INTERNAL,
};

int ucfg_read(size_t field, uint8_t *data, size_t size);

int ucfg_write(size_t field, const uint8_t *data, size_t size);

int ucfg_restore(void);

int ucfg_init(void);

int ucfg_deinit(void);

#endif
