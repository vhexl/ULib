/**
 * @file ULib.h
 * @author vhex (visual86n@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-12-30
 *
 * SPDX-FileCopyrightText: Copyright (c) 2024
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef __ULIB_H
#define __ULIB_H

#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#include "uconfig/uconfig.h"
#include "uprotocol/uprotocol.h"

#define ULIB_SWAP(a, b) \
    do {                \
        *(a) ^= *(b);   \
        *(b) ^= *(a);   \
        *(a) ^= *(b);   \
    } while (0);

#define ULIB_MIN(a, b)       ((a) < (b) ? (a) : (b))

#define ULIB_MAX(a, b)       ((a) > (b) ? (a) : (b))

#define ULIB_U16_TO_U8ARR(x) (((x) >> 0x08) & 0xFF), \
                             (((x) >> 0x00) & 0xFF)

#define ULIB_U32_TO_U8ARR(x) (((x) >> 0x18) & 0xFF), \
                             (((x) >> 0x10) & 0xFF), \
                             (((x) >> 0x08) & 0xFF), \
                             (((x) >> 0x00) & 0xFF)

#define ULIB_ARRAY_MAX(list_name) (sizeof(list_name) / sizeof(list_name[0]))

#if defined __GNUC__
#define PACK(__Declaration__) __Declaration__ __attribute__((__packed__))
#elif defined _MSC_VER
#define PACK(__Declaration__) __pragma(pack(push, 1)) __Declaration__ __pragma(pack(pop))
#elif defined __ARMCC_VERSION
#define PACK(__Declaration__) __packed __Declaration__
#endif

#endif
