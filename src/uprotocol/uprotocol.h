/**
 * @file uprotocol.h
 * @author vhex (visual86n@outlook.com)
 * @brief This file is uprotocol header file.
 * @version 0.1
 * @date 2023-12-30
 *
 * SPDX-FileCopyrightText: Copyright (c) 2024
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef __UPROTOCOL_H
#define __UPROTOCOL_H

#include <stdint.h>
#include <stdbool.h>

#define UPROTOCOL_STATIC_BUF_SIZE 1024

#if UPROTOCOL_STATIC_BUF_SIZE < 1
#error "UPROTOCOL_STATIC_BUF_SIZE must be greater than 1"
#endif

#define UPROTOCOL_DEBUG 0

#if UPROTOCOL_DEBUG == 1
/* Enable debug */
#define UPROTOCOL_PARAM_ASSERT(exp) \
    if (!(exp)) {                   \
        while (1)                   \
            ;                       \
    }
#define UPROTOCOL_LOG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define UPROTOCOL_FIELD_PRINT(field, val, sz)       \
    do {                                            \
        printf("Field [%d]: ", field);              \
        for (unsigned int idx = 0; idx < sz; idx++) \
            printf("0x%02X ", *((val) + idx));      \
        printf("\n");                               \
    } while (0)

#else
/* Disable debug */
#define UPROTOCOL_PARAM_ASSERT(exp)
#define UPROTOCOL_LOG(fmt, ...)
#define UPROTOCOL_FIELD_PRINT(field, val, sz)
#endif

typedef uint32_t (*cmd_handler)(const uint8_t *data, const uint32_t len);

struct uptl_cmd_handler {
    uint8_t can_segment : 1; // acceptance segment 0: cannot , 1: can
    uint8_t type : 2;        // 0: request, 1: response
    uint8_t cmd : 5;         // limit 31
    cmd_handler handler;     // cmd handle function pointer
};

struct uptl_frame {
    uint8_t is_segment : 1; // 0: is end, 1: followed by data
    uint8_t type : 2;       // 0: request, 1: response
    uint8_t cmd : 5;        // cmd code
    uint8_t payload[];      // params or data
};

enum uptl_frame_type {
    UPTL_FRAME_REQUEST = 0,
    UPTL_FRAME_RESPONSE,
};

enum uptl_ret {
    UPTL_SUCCESS = 0,
    UPTL_ERROR_FRAME_LEN,
    UPTL_ERROR_FRAME_SEQ,
    UPTL_ERROR_CMD_HDL_SEGMENT,
    UPTL_ERROR_CMD_HDL_NOT_FOUND,
    // handle error
    UPTL_ERROR_INVAILD_PARAM,
    UPTL_ERROR_INTERNAL,
};

int uptl_send(const enum uptl_frame_type type, const uint8_t cmd, const uint8_t *data, uint32_t len);

int uptl_process(const uint8_t *data, uint32_t len);

#endif
