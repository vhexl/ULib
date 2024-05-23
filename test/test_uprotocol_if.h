/**
 * @file uprotocol_if.h
 * @author vhex (visual86n@outlook.com)
 * @brief This file is uprotocol user interface header file.
 * @version 0.1
 * @date 2024-01-08
 * 
 * SPDX-FileCopyrightText: Copyright (c) 2024
 * SPDX-License-Identifier: Apache-2.0
 * 
 */

#ifndef __UPROTOCOL_IF_H
#define __UPROTOCOL_IF_H

#include <stdint.h>
#include <stdbool.h>

typedef void (*timeout_handler)(void);

int uptl_if_send(const uint8_t *data, const uint32_t len);

int uptl_if_timeout(timeout_handler hdl);

#endif
