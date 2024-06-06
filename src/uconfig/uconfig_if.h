/**
 * @file uconfig_if.h
 * @author vhex (visual86n@outlook.com)
 * @brief This file is uconfig user interface header file.
 * @version 0.1
 * @date 2024-01-04
 *
 * SPDX-FileCopyrightText: Copyright (c) 2024
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef __UCFG_IF_H
#define __UCFG_IF_H

#include <stdint.h>
#include <stdbool.h>

enum uconfig_if_ret {
    UCFG_IF_SUCCESS = 0,
};

int uconfig_if_init(void);

int uconfig_if_deinit(void);

int uconfig_if_read(size_t field, uint8_t *data, size_t size);

int uconfig_if_write(size_t field, const uint8_t *data, size_t size);

#endif
