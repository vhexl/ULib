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

#include <string.h>

#include "uprotocol_if.h"
#include "ULib.h"

#define UPTL_VERIFY_FAIL 0x8001

uint8_t test_buf[8192] = {0x55};

uint8_t test_0x01_buf[8192] = {0xAA};
uint32_t test_0x01_idx      = 0;

uint8_t test_0x02_buf[8192] = {0xEE};
uint32_t test_0x02_idx      = 0;

// 0x00 used variable
uint8_t test_0x00_p1  = 0xAA;
uint16_t test_0x00_p2 = 0x2211;
uint32_t test_0x00_p3 = 0x44332211;
uint64_t test_0x00_p4 = 0x8877665544332211;
float test_0x00_p5    = 1.333333333f;
double test_0x00_p6   = 2.14444444444;
bool test_0x00_p7     = true;
char test_0x00_p8[16] = "123456789abcdef";

static uint32_t test_0x00_req(const uint8_t *data, const uint32_t len)
{
    // data read
    if (len == 1) {
        // read
        switch (data[0]) {
            case 1: {
                uint8_t resp[2];
                resp[0] = 1;
                memcpy(resp + 1, &test_0x00_p1, 1);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 2);
                return ret;
            }
            case 2: {
                uint8_t resp[3];
                resp[0] = 2;
                memcpy(resp + 1, &test_0x00_p2, 2);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 3);
                return ret;
            }
            case 3: {
                uint8_t resp[5];
                resp[0] = 3;
                memcpy(resp + 1, &test_0x00_p3, 4);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 5);
                return ret;
            }
            case 4: {
                uint8_t resp[9];
                resp[0] = 4;
                memcpy(resp + 1, &test_0x00_p4, 8);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 9);
                return ret;
            }
            case 5: {
                uint8_t resp[5];
                resp[0] = 5;
                memcpy(resp + 1, &test_0x00_p5, 4);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 5);
                return ret;
            }
            case 6: {
                uint8_t resp[9];
                resp[0] = 6;
                memcpy(resp + 1, &test_0x00_p6, 8);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 9);
                return ret;
            }
            case 7: {
                uint8_t resp[1 + sizeof(bool)];
                resp[0] = 7;
                memcpy(resp + 1, &test_0x00_p7, sizeof(bool));
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp,
                                         sizeof(bool) + 1);
                return ret;
            }
            case 8: {
                uint8_t resp[17];
                resp[0] = 8;
                memcpy(resp + 1, &test_0x00_p8, 16);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 17);
                return ret;
            }
            default:
                return UPTL_ERROR_INVAILD_PARAM;
        }
    } else if (len > 1) {
        // write
        switch (data[0]) {
            case 1: {
                if (len != 2) {
                    return UPTL_ERROR_INVAILD_PARAM;
                }
                memcpy(&test_0x00_p1, data + 1, 1);
                uint8_t resp[2];
                resp[0] = 1;
                memcpy(resp + 1, &test_0x00_p1, 1);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 2);
                return ret;
            }
            case 2: {
                if (len != 3) {
                    return UPTL_ERROR_INVAILD_PARAM;
                }
                memcpy(&test_0x00_p2, data + 1, 2);
                uint8_t resp[3];
                resp[0] = 2;
                memcpy(resp + 1, &test_0x00_p2, 2);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 3);
                return ret;
            }
            case 3: {
                if (len != 5) {
                    return UPTL_ERROR_INVAILD_PARAM;
                }
                memcpy(&test_0x00_p3, data + 1, 4);
                uint8_t resp[5];
                resp[0] = 3;
                memcpy(resp + 1, &test_0x00_p3, 4);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 5);
                return ret;
            }
            case 4: {
                if (len != 9) {
                    return UPTL_ERROR_INVAILD_PARAM;
                }
                memcpy(&test_0x00_p4, data + 1, 8);
                uint8_t resp[9];
                resp[0] = 4;
                memcpy(resp + 1, &test_0x00_p4, 8);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 9);
                return ret;
            }
            case 5: {
                if (len != 5) {
                    return UPTL_ERROR_INVAILD_PARAM;
                }
                memcpy(&test_0x00_p5, data + 1, 4);
                uint8_t resp[5];
                resp[0] = 5;
                memcpy(resp + 1, &test_0x00_p5, 4);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 5);
                return ret;
            }
            case 6: {
                if (len != 9) {
                    return UPTL_ERROR_INVAILD_PARAM;
                }
                memcpy(&test_0x00_p6, data + 1, 8);
                uint8_t resp[9];
                resp[0] = 6;
                memcpy(resp + 1, &test_0x00_p6, 8);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 9);
                return ret;
            }
            case 7: {
                if (len != 2) {
                    return UPTL_ERROR_INVAILD_PARAM;
                }
                memcpy(&test_0x00_p7, data + 1, 1);
                uint8_t resp[1 + sizeof(bool)];
                resp[0] = 7;
                memcpy(resp + 1, &test_0x00_p7, sizeof(bool));
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp,
                                         sizeof(bool) + 1);
                return ret;
            }
            case 8: {
                if (len != 17) {
                    return UPTL_ERROR_INVAILD_PARAM;
                }
                memcpy(test_0x00_p8, data + 1, 16);
                uint8_t resp[17];
                resp[0] = 8;
                memcpy(resp + 1, &test_0x00_p8, 16);
                uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x00, resp, 17);
                return ret;
            }
            default:
                return UPTL_ERROR_INVAILD_PARAM;
        }
    } else {
        return UPTL_ERROR_INVAILD_PARAM;
    }

    return UPTL_SUCCESS;
}

static uint32_t test_0x00_resp(const uint8_t *data, const uint32_t len)
{
    // check
    if (len > 1) {
        switch (data[0]) {
            case 1:
                if (memcmp(data + 1, &test_0x00_p1, 1) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_VERIFY_FAIL;
            case 2:
                if (memcmp(data + 1, &test_0x00_p2, 2) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_VERIFY_FAIL;
            case 3:
                if (memcmp(data + 1, &test_0x00_p3, 4) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_VERIFY_FAIL;
            case 4:
                if (memcmp(data + 1, &test_0x00_p4, 8) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_VERIFY_FAIL;
            case 5:
                if (memcmp(data + 1, &test_0x00_p5, 4) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_VERIFY_FAIL;
            case 6:
                if (memcmp(data + 1, &test_0x00_p6, 8) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_VERIFY_FAIL;
            case 7:
                if (memcmp(data + 1, &test_0x00_p7, sizeof(bool)) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_VERIFY_FAIL;
            case 8:
                if (memcmp(data + 1, &test_0x00_p8, 16) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_VERIFY_FAIL;
            default:
                return UPTL_VERIFY_FAIL;
        }
    } else {
        return UPTL_VERIFY_FAIL;
    }

    return UPTL_SUCCESS;
}

static uint32_t test_0x01_req(const uint8_t *data, const uint32_t len)
{
    if (test_0x01_idx + len > 8192) {
        return UPTL_ERROR_INVAILD_PARAM;
    }
    // write
    memcpy(test_0x01_buf + test_0x01_idx, data, len);
    test_0x01_idx += len;
    uint32_t resp_len = test_0x01_idx;
    uint32_t ret =
        uptl_send(UPTL_FRAME_RESPONSE, 0x01, (uint8_t *)&resp_len, 4);
    return ret;
}

static uint32_t test_0x01_resp(const uint8_t *data, const uint32_t len)
{
    if (len != 4) {
        return UPTL_VERIFY_FAIL;
    }
    uint32_t resp_len;
    memcpy(&resp_len, data, 4);
    if (resp_len != test_0x01_idx) {
        return UPTL_VERIFY_FAIL;
    }
    // check data
    for (size_t i = 0; i < len; i++) {
        if (test_0x01_buf[i] != 255 - (i % 256)) {
            return UPTL_VERIFY_FAIL;
        }
    }

    return UPTL_SUCCESS;
}

static uint32_t test_0x02_req(const uint8_t *data, const uint32_t len)
{
    for (size_t i = 0; i < 8192; i++) {
        test_0x02_buf[i] = i % 256;
    }
    uint32_t ret = uptl_send(UPTL_FRAME_RESPONSE, 0x02, test_0x02_buf, 8192);
    return ret;
}

static uint32_t test_0x02_resp(const uint8_t *data, const uint32_t len)
{
    if (test_0x01_idx + len > 8192) {
        return UPTL_VERIFY_FAIL;
    }

    for (size_t i = test_0x02_idx; i < test_0x02_idx + len; i++) {
        if (test_0x02_buf[i] != i) {
            return UPTL_VERIFY_FAIL;
        }
    }

    test_0x02_idx += len;

    return UPTL_SUCCESS;
}

struct uptl_cmd_handler __ext_cmd_hdl_list[] = {
    // example implement
    // {
    //     .cmd         = 0x00,
    //     .type     = UPTL_FRAME_REQUEST,
    //     .can_segment = 1,
    //     .handler     = NULL,
    // },
    // ------CMD Handler List------
    // -------User Implement-------
    {
        .cmd         = 0x00,
        .type        = UPTL_FRAME_REQUEST,
        .can_segment = 0,
        .handler     = test_0x00_req,
    },
    {
        .cmd         = 0x00,
        .type        = UPTL_FRAME_RESPONSE,
        .can_segment = 0,
        .handler     = test_0x00_resp,
    },
    {
        .cmd         = 0x01,
        .type        = UPTL_FRAME_REQUEST,
        .can_segment = 1,
        .handler     = test_0x01_req,
    },
    {
        .cmd         = 0x01,
        .type        = UPTL_FRAME_RESPONSE,
        .can_segment = 1,
        .handler     = test_0x01_resp,
    },
    {
        .cmd         = 0x02,
        .type        = UPTL_FRAME_REQUEST,
        .can_segment = 0,
        .handler     = test_0x02_req,
    },
    {
        .cmd         = 0x02,
        .type        = UPTL_FRAME_RESPONSE,
        .can_segment = 1,
        .handler     = test_0x02_resp,
    },
    // ----------------------------
};
uint32_t __ext_cmd_hdl_list_len = sizeof(__ext_cmd_hdl_list);

int uptl_if_send(const uint8_t *data, const uint32_t len)
{
    // ------UPTL Send Interface------
    // --------User Implement---------
    memcpy(test_buf, data, len);
    return uptl_process(test_buf, len);
    // -------------------------------
    // return UPTL_SUCCESS;
}
