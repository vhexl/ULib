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
static int __example_cmd_handler(const uint8_t *data, size_t len,
                                 enum uptl_ext ext)
{
    uint8_t resp[2] = {0x11, 0x22};
    uptl_send(UPTL_PKT_RESP, 0x00, resp, 2);

    switch (ext) {
        case UPTL_EXT_NOSEG:
            break;
        case UPTL_EXT_SEG_START:
            break;
        case UPTL_EXT_SEG_CONTINUE:
            break;
        case UPTL_EXT_SEG_END:
            break;
        default:
            break;
    }

    return UPTL_SUCCESS;
}

const struct uptl_cmd_handler __ext_cmd_list[] = {
    // example implement
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_NOSEG, UPTL_PKT_REQ, 0x00),
        .handler = __example_cmd_handler,
    },
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

};
const size_t __ext_cmd_list_len = ULIB_ARRAY_MAX(__ext_cmd_list);

/**
 * @brief Uprotocol send data interface
 *
 * @param data Buffer of data to be sent
 * @param len Length of data to be sent
 *
 * @return Uprotocol error code
 * @retval UPTL_SUCCESS: Initialization success
 * @retval Other: send failure
 */
int uptl_if_send(const uint8_t *data, size_t len)
{
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    return UPTL_SUCCESS;
}

/**
 * @brief Uprotocol start timeout handle timer
 *
 * @param hdl timeout handler
 * @return Uprotocol error code
 * @retval UPTL_SUCCESS: Start timer success
 * @retval Other: send failure
 */
int uptl_if_timeout_restart(timeout_handler hdl)
{
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    return UPTL_SUCCESS;
}
