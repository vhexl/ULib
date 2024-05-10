/**
 * @file uprotocol_if.c
 * @author vhex (visual86n@outlook.com)
 * @brief This file is uprotocol user interface source file.
 * @version 0.1
 * @date 2024-01-08
 *
 * SPDX-FileCopyrightText: Copyright (c) 2024
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include "uprotocol_if.h"
#include "ULib.h"

// just example implement
static uint32_t __example_cmd_handler(const uint8_t *data, const uint32_t len)
{
    uint8_t resp[2] = {0x11, 0x22};
    uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 2);

    return UPTL_SUCCESS;
}

struct uptl_cmd_handler __ext_cmd_hdl_list[] = {
    // example implement
    {
        .cmd         = 0x00,
        .type        = UPTL_FRAME_REQUEST,
        .can_segment = 1,
        .handler     = __example_cmd_handler,
    },
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

};
int __ext_cmd_hdl_list_len = sizeof(__ext_cmd_hdl_list);

/**
 * @brief Uprotocol send data interface
 *
 * @param data Buffer of data to be sent
 * @param len Length of data to be sent
 *
 * @return Uprotocol error code
 * @retval UCONFIG_IF_SUCCESS: Initialization success
 * @retval Other: send failure
 */
int uptl_if_send(const uint8_t *data, const uint32_t len)
{
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    return UPTL_SUCCESS;
}