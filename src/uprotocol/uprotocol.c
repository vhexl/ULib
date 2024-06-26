/**
 * @file uprotocol.c
 * @author vhex (visual86n@outlook.com)
 * @brief This file is uprotocol source file.
 * @version 0.1
 * @date 2024-01-04
 *
 * SPDX-FileCopyrightText: Copyright (c) 2024
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include "stdio.h"
#include "string.h"

#include "uprotocol.h"
#include "uprotocol_if.h"

// ------------------------------------------------------------------------
//                          External Variables
// ------------------------------------------------------------------------
extern const struct uptl_cmd_handler __ext_cmd_list[];
extern const size_t __ext_cmd_list_len;

// ------------------------------------------------------------------------
//                          Private Variables
// ------------------------------------------------------------------------
static uint8_t __uptl_static_buf[UPTL_BUF_SIZE];
static struct uptl_cache __pkt_cache = {0};

// ------------------------------------------------------------------------
//                             Private Macro
// ------------------------------------------------------------------------

// ------------------------------------------------------------------------
//                           Private Functions
// ------------------------------------------------------------------------

static void __uptl_timeout_handler(void)
{
    __pkt_cache.head = 0;
    __pkt_cache.hdl  = NULL;
    UPTL_LOGE("Timeout...");
}

static int __uptl_send(enum uptl_pkt_type type, uint8_t cmd,
                       const uint8_t *data, size_t len)
{
    struct uptl_pkt *pkt   = (struct uptl_pkt *)__uptl_static_buf;
    const size_t head_size = UPTL_HEAD_SIZE;
    size_t body_size       = 0;

    while (len > 0) {
        // function recursion `__uptl_static_buf` may be modified.
        if (len > UPTL_BODY_SIZE_MAX) {
            pkt->head = UPTL_HEAD_SET(UPTL_PKT_SEG, type, cmd);
            body_size = UPTL_BODY_SIZE_MAX;
            len -= UPTL_BODY_SIZE_MAX;
        } else {
            pkt->head = UPTL_HEAD_SET(UPTL_PKT_NOSEG, type, cmd);
            body_size = len;
            len       = 0;
        }

        memcpy(pkt->body, data, body_size);

        int ret = uptl_if_send((const uint8_t *)pkt, head_size + body_size);
        if (ret != UPTL_SUCCESS) {
            UPTL_LOGE("Send failed, %d bytes remaining", len);
            return ret;
        }

        data += body_size;
    }

    return UPTL_SUCCESS;
}

static int __uptl_match(const struct uptl_pkt *pkt, size_t body_len)
{
    const bool is_seg = (bool)UPTL_PKT_SEG_GET(pkt->head);

    for (size_t i = 0; i < __ext_cmd_list_len; i++) {
        // match cmd code and type
        if ((__ext_cmd_list[i].head ^ pkt->head) & (~UPTL_PKT_SEG_MASK)) {
            continue;
        }
        // check segment
        if (!UPTL_PKT_SEG_GET(__ext_cmd_list[i].head) && is_seg) {
            return UPTL_ERROR_SEGMENT; // Unexpected segment
        } else {
            if (is_seg && body_len != UPTL_BODY_SIZE_MAX) {
                return UPTL_ERROR_SEGMENT_INAILD;
            }
            if (__pkt_cache.hdl == NULL && is_seg) {
                __pkt_cache.head = pkt->head;
                __pkt_cache.hdl  = __ext_cmd_list[i].handler;

                return __ext_cmd_list[i].handler(pkt->body, body_len,
                                                 UPTL_EXT_SEG_START);
            }
        }
        // all prerequisite match
        return __ext_cmd_list[i].handler(pkt->body, body_len, UPTL_EXT_NOSEG);
    }

    return UPTL_ERROR_NOT_FOUND;
}

// ------------------------------------------------------------------------
//                           Public Functions
// ------------------------------------------------------------------------

/**
 * @brief UProtocol request send
 *
 * @param cmd The command for the package.
 * @param data The data to be sent.
 * @param len The length of the data.
 *
 * @return int uprotocol error code.
 *
 * @retval UPTL_SUCCESS: Send success
 */
extern inline int uptl_req_send(uint8_t cmd, const uint8_t *data, size_t len)
{
    UPTL_PARAM_ASSERT(data != NULL && len > 0 || len == 0);
    return __uptl_send(UPTL_PKT_REQ, cmd, data, len);
}

/**
 * @brief UProtocol request send
 *
 * @param cmd The command for the package.
 * @param data The data to be sent.
 * @param len The length of the data.
 *
 * @return int uprotocol error code.
 *
 * @retval UPTL_SUCCESS: Send success
 */
extern inline int uptl_resp_send(uint8_t cmd, const uint8_t *data, size_t len)
{
    UPTL_PARAM_ASSERT(data != NULL && len > 0 || len == 0);
    return __uptl_send(UPTL_PKT_RESP, cmd, data, len);
}

/**
 * @brief UProtocol request send
 *
 * @param pkt The pkt to be sent.
 * @param len The length of the data.
 *
 * @return int uprotocol error code.
 *
 * @retval UPTL_SUCCESS: Send success
 */
extern inline int uptl_custom_send(struct uptl_pkt *pkt, size_t body_len)
{
    UPTL_PARAM_ASSERT(pkt != NULL);
    return uptl_if_send((const uint8_t *)pkt, body_len);
}

/**
 * @brief Process the UPTL package
 *
 * This function processes the UPTL (uprotocol) package received.
 * It performs various checks and operations based on the contents of the
 * package.
 *
 * @param data Pointer to the UPTL package data
 * @param len Length of the UPTL package data
 * @return int The return value depends on the processing result
 *
 * @retval UPTL_SUCCESS if the package is processed successfully
 * @retval UPTL_ERR_PACK_LEN if the package length is invalid
 */
int uptl_process(const uint8_t *data, size_t len)
{
    UPTL_PARAM_ASSERT(data != NULL && len > 0);

    const struct uptl_pkt *pkt = (const struct uptl_pkt *)data;
    const size_t body_len      = len - UPTL_HEAD_SIZE;

    int ret = uptl_if_timeout_restart(__uptl_timeout_handler);
    if (ret != UPTL_SUCCESS) {
        return ret;
    }

    // check cache
    if (__pkt_cache.hdl != NULL) {
        const uint8_t comp = __pkt_cache.head ^ pkt->head;
        if (comp & (~UPTL_PKT_SEG_MASK)) {
            __pkt_cache.head = 0;
            __pkt_cache.hdl  = NULL;
            return UPTL_ERROR_SEGMENT_END;
        } else {
            const cmd_handler hdl = __pkt_cache.hdl;
            if (comp) {
                __pkt_cache.head = 0;
                __pkt_cache.hdl  = NULL;
                return hdl(pkt->body, body_len, UPTL_EXT_SEG_END);
            } else {
                // contine segment
                return hdl(pkt->body, body_len, UPTL_EXT_SEG_CONTINUE);
            }
        }
    }

    return __uptl_match(pkt, body_len);
}
