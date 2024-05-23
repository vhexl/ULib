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

#define UPTL_BUF_SIZE         512
#define UPTL_PAYLOAD_SIZE_MAX (UPTL_BUF_SIZE - sizeof(struct uptl_pkt))

#if UPTL_BUF_SIZE < 1
#error "UPTL_BUF_SIZE must be greater than 1"
#endif

#define UPTL_DEBUG 0

#if UPTL_DEBUG == 1
/* Enable debug */
#define UPTL_PARAM_ASSERT(exp)                                                 \
    if (!(exp)) {                                                              \
        while (1)                                                              \
            ;                                                                  \
    }
#define UPTL_LOGE(fmt, ...) printf("[error] " fmt, ##__VA_ARGS__)
#define UPTL_LOGI(fmt, ...) printf("[info] " fmt, ##__VA_ARGS__)
#define UPTL_FIELD_PRINT(field, val, sz)                                       \
    do {                                                                       \
        printf("Field [%d]: ", field);                                         \
        for (unsigned int idx = 0; idx < sz; idx++)                            \
            printf("0x%02X ", *((val) + idx));                                 \
        printf("\n");                                                          \
    } while (0)

#else
/* Disable debug */
#define UPTL_PARAM_ASSERT(exp)
#define UPTL_LOGE(fmt, ...)
#define UPTL_LOGI(fmt, ...)
#define UPTL_FIELD_PRINT(field, val, sz)
#endif

#define UPTL_PKT_SEG_MASK       0x80
#define UPTL_PKT_TYPE_MASK      0x40
#define UPTL_PKT_CMD_MASK       0x3F

#define UPTL_PKT_SEG_CHANGE(h, v)  ((h) = (v | (h & (~UPTL_PKT_SEG_MASK))))
#define UPTL_PKT_TYPE_CHANGE(h, v) ((h) = (v | (h & (~UPTL_PKT_TYPE_MASK))))
#define UPTL_PKT_CMD_CHANGE(h, v)  ((h) = (v | (h & (~UPTL_PKT_CMD_MASK))))

#define UPTL_PKT_SEG_SET(h)   ((h) |= UPTL_PKT_SEG_MASK)
#define UPTL_PKT_TYPE_SET(h)  ((h) |= UPTL_PKT_TYPE_MASK)
#define UPTL_PKT_CMD_SET(h)   ((h) |= UPTL_PKT_CMD_MASK)

#define UPTL_PKT_SEG_RESET(h)   ((h) &= ~UPTL_PKT_SEG_MASK)
#define UPTL_PKT_TYPE_RESET(h)  ((h) &= ~UPTL_PKT_TYPE_MASK)
#define UPTL_PKT_CMD_RESET(h)   ((h) &= ~UPTL_PKT_CMD_MASK)

#define UPTL_PKT_SEG_GET(h)     ((h) & UPTL_PKT_SEG_MASK)
#define UPTL_PKT_TYPE_GET(h)    ((h) & UPTL_PKT_TYPE_MASK)
#define UPTL_PKT_CMD_GET(h)     ((h) & UPTL_PKT_CMD_MASK)

#define UPTL_PKT_SEG_IS(h)      ((h) & UPTL_PKT_SEG_MASK)
#define UPTL_PKT_TYPE_IS(h)     ((h) & UPTL_PKT_TYPE_MASK)

#define UPTL_HEAD_SET(seg, type, cmd)                                          \
    ((seg & UPTL_PKT_SEG_MASK) | (type & UPTL_PKT_TYPE_MASK) |                 \
     (cmd & UPTL_PKT_CMD_MASK))

#define UPTL_PKT_CMD_INVAILD (0xFF)

typedef int (*cmd_handler)(const uint8_t *data, const uint32_t len);

// struct __pkt_head {
//     uint8_t segment : 1; // 0: is end, 1: followed by data
//     uint8_t type : 1;    // 0: request, 1: response
//     uint8_t cmd : 5;     // cmd code
// };

struct uptl_cmd_handler {
    uint8_t head;
    cmd_handler handler; // cmd handle function pointer
};

struct uptl_pkt {
    uint8_t head;
    uint8_t body[]; // params or data
};

struct uptl_cache {
    uint8_t head;
    cmd_handler hdl;
};

enum uptl_pkt_type {
    UPTL_PKT_REQUEST  = 0,
    UPTL_PKT_RESPONSE = UPTL_PKT_TYPE_MASK,
};

enum uptl_pkt_seg {
    UPTL_PKT_NOSEGMENT = 0,
    UPTL_PKT_SEGMENT   = UPTL_PKT_SEG_MASK,
};

enum uptl_ret {
    UPTL_SUCCESS = 0,
    UPTL_ERROR_SEND_FAILED,
    UPTL_ERROR_PKT_LEN,
    UPTL_ERROR_SEGMENT,
    UPTL_ERROR_SEGMENT_END,
    UPTL_ERROR_SEGMENT_INAILD,
    UPTL_ERROR_NOT_FOUND,
    UPTL_ERROR_TIMER_START,
    // handle error
    UPTL_ERROR_INVAILD_PARAM,
    UPTL_ERROR_INTERNAL,
};

int uptl_send(const enum uptl_pkt_type type, const uint8_t cmd,
              const uint8_t *data, uint32_t len);

int uptl_process(const uint8_t *data, uint32_t len);

#endif
