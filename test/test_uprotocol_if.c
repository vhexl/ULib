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

#include "test.h"

bool uptl_if_send_flag    = true;
bool uptl_if_timeout_flag = true;

enum uptl_ext uptl_ext_flag = 0xFF;

timeout_handler test_timeout_handle;

uint8_t test_buf[TEST_BUF_SIZE] = {0x55};

uint8_t test_0x01_buf[TEST_BUF_SIZE] = {0xAA};
uint32_t test_0x01_idx               = 0;

uint8_t test_0x02_buf[TEST_BUF_SIZE] = {0xEE};
uint32_t test_0x02_idx               = 0;

// 0x00 used variable
uint8_t test_0x00_p1  = 0xAA;
uint16_t test_0x00_p2 = 0x2211;
uint32_t test_0x00_p3 = 0x44332211;
uint64_t test_0x00_p4 = 0x8877665544332211;
float test_0x00_p5    = 1.333333333f;
double test_0x00_p6   = 2.14444444444;
bool test_0x00_p7     = true;
char test_0x00_p8[16] = "123456789abcdef";

static int test_0x00_req(const uint8_t *data, size_t len, enum uptl_ext ext)
{
    // data read
    if (len == 1) {
        // read
        switch (data[0]) {
            case 1: {
                uint8_t resp[2];
                resp[0] = 1;
                memcpy(resp + 1, &test_0x00_p1, 1);
                int ret = uptl_resp_send(0x00, resp, 2);
                return ret;
            }
            case 2: {
                uint8_t resp[3];
                resp[0] = 2;
                memcpy(resp + 1, &test_0x00_p2, 2);
                int ret = uptl_resp_send(0x00, resp, 3);
                return ret;
            }
            case 3: {
                uint8_t resp[5];
                resp[0] = 3;
                memcpy(resp + 1, &test_0x00_p3, 4);
                int ret = uptl_resp_send(0x00, resp, 5);
                return ret;
            }
            case 4: {
                uint8_t resp[9];
                resp[0] = 4;
                memcpy(resp + 1, &test_0x00_p4, 8);
                int ret = uptl_resp_send(0x00, resp, 9);
                return ret;
            }
            case 5: {
                uint8_t resp[5];
                resp[0] = 5;
                memcpy(resp + 1, &test_0x00_p5, 4);
                int ret = uptl_resp_send(0x00, resp, 5);
                return ret;
            }
            case 6: {
                uint8_t resp[9];
                resp[0] = 6;
                memcpy(resp + 1, &test_0x00_p6, 8);
                int ret = uptl_resp_send(0x00, resp, 9);
                return ret;
            }
            case 7: {
                uint8_t resp[1 + sizeof(bool)];
                resp[0] = 7;
                memcpy(resp + 1, &test_0x00_p7, sizeof(bool));
                int ret = uptl_resp_send(0x00, resp, sizeof(bool) + 1);
                return ret;
            }
            case 8: {
                uint8_t resp[17];
                resp[0] = 8;
                memcpy(resp + 1, &test_0x00_p8, 16);
                int ret = uptl_resp_send(0x00, resp, 17);
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
                int ret = uptl_resp_send(0x00, resp, 2);
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
                int ret = uptl_resp_send(0x00, resp, 3);
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
                int ret = uptl_resp_send(0x00, resp, 5);
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
                int ret = uptl_resp_send(0x00, resp, 9);
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
                int ret = uptl_resp_send(0x00, resp, 5);
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
                int ret = uptl_resp_send(0x00, resp, 9);
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
                int ret = uptl_resp_send(0x00, resp, sizeof(bool) + 1);
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
                int ret = uptl_resp_send(0x00, resp, 17);
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

static int test_0x00_resp(const uint8_t *data, size_t len, enum uptl_ext ext)
{
    // check
    if (len > 1) {
        switch (data[0]) {
            case 1:
                if (memcmp(data + 1, &test_0x00_p1, 1) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_ERROR_INTERNAL;
            case 2:
                if (memcmp(data + 1, &test_0x00_p2, 2) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_ERROR_INTERNAL;
            case 3:
                if (memcmp(data + 1, &test_0x00_p3, 4) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_ERROR_INTERNAL;
            case 4:
                if (memcmp(data + 1, &test_0x00_p4, 8) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_ERROR_INTERNAL;
            case 5:
                if (memcmp(data + 1, &test_0x00_p5, 4) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_ERROR_INTERNAL;
            case 6:
                if (memcmp(data + 1, &test_0x00_p6, 8) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_ERROR_INTERNAL;
            case 7:
                if (memcmp(data + 1, &test_0x00_p7, sizeof(bool)) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_ERROR_INTERNAL;
            case 8:
                if (memcmp(data + 1, &test_0x00_p8, 16) == 0) {
                    return UPTL_SUCCESS;
                }
                return UPTL_ERROR_INTERNAL;
            default:
                return UPTL_ERROR_INTERNAL;
        }
    } else {
        return UPTL_ERROR_INTERNAL;
    }

    return UPTL_SUCCESS;
}

static int test_0x01_req(const uint8_t *data, size_t len, enum uptl_ext ext)
{
    if (test_0x01_idx + len > TEST_BUF_SIZE) {
        return UPTL_ERROR_INVAILD_PARAM;
    }

    // write
    memcpy(test_0x01_buf + test_0x01_idx, data, len);
    test_0x01_idx += len;

    if (len < UPTL_BODY_SIZE_MAX) {
        uint32_t resp_len = test_0x01_idx;
        int ret           = uptl_resp_send(0x01, (uint8_t *)&resp_len, 4);
        return ret;
    }

    return UPTL_SUCCESS;
}

static int test_0x01_resp(const uint8_t *data, size_t len, enum uptl_ext ext)
{
    if (len != 4) {
        return UPTL_ERROR_INTERNAL;
    }
    uint32_t resp_len;
    memcpy(&resp_len, data, 4);
    if (resp_len != test_0x01_idx) {
        return UPTL_ERROR_INTERNAL;
    }
    // check data
    for (size_t i = 0; i < len; i++) {
        if (test_0x01_buf[i] != 255 - (i % 256)) {
            return UPTL_ERROR_INTERNAL;
        }
    }

    return UPTL_SUCCESS;
}

static int test_0x02_req(const uint8_t *data, size_t len, enum uptl_ext ext)
{
    for (size_t i = 0; i < TEST_BUF_SIZE; i++) {
        test_0x02_buf[i] = i % 256;
    }
    int ret = uptl_resp_send(0x02, test_0x02_buf, TEST_BUF_SIZE);
    return ret;
}

static int test_0x02_resp(const uint8_t *data, size_t len, enum uptl_ext ext)
{
    if (test_0x01_idx + len > TEST_BUF_SIZE) {
        return UPTL_ERROR_INTERNAL;
    }

    for (size_t i = test_0x02_idx; i < test_0x02_idx + len; i++) {
        if (test_0x02_buf[i] != i) {
            return UPTL_ERROR_INTERNAL;
        }
    }

    test_0x02_idx += len;

    return UPTL_SUCCESS;
}

static int test_0x03_req(const uint8_t *data, size_t len, enum uptl_ext ext)
{
    uptl_ext_flag = ext;
    return UPTL_SUCCESS;
}

static int test_0x03_resp(const uint8_t *data, size_t len, enum uptl_ext ext)
{
    uptl_ext_flag = ext;

    return UPTL_SUCCESS;
}

static int test_0x04_req(const uint8_t *data, size_t len, enum uptl_ext ext)
{
    uptl_ext_flag = ext;

    return UPTL_SUCCESS;
}

static int test_0x04_resp(const uint8_t *data, size_t len, enum uptl_ext ext)
{
    uptl_ext_flag = ext;

    return UPTL_SUCCESS;
}

struct uptl_cmd_handler __ext_cmd_list[] = {
    // example implement
    // {
    //     .cmd         = 0x00,
    //     .type     = UPTL_PKT_REQUEST,
    //     .segment = 1,
    //     .handler     = NULL,
    // },
    // ------CMD Handler List------
    // -------User Implement-------
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_NOSEGMENT, UPTL_PKT_REQUEST, 0x00),
        .handler = test_0x00_req,
    },
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_NOSEGMENT, UPTL_PKT_RESPONSE, 0x00),
        .handler = test_0x00_resp,
    },
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x01),
        .handler = test_0x01_req,
    },
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_NOSEGMENT, UPTL_PKT_RESPONSE, 0x01),
        .handler = test_0x01_resp,
    },
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_NOSEGMENT, UPTL_PKT_REQUEST, 0x02),
        .handler = test_0x02_req,
    },
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_RESPONSE, 0x02),
        .handler = test_0x02_resp,
    },
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_NOSEGMENT, UPTL_PKT_REQUEST, 0x03),
        .handler = test_0x03_req,
    },
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_NOSEGMENT, UPTL_PKT_RESPONSE, 0x03),
        .handler = test_0x03_resp,
    },
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x04),
        .handler = test_0x04_req,
    },
    {
        .head    = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_RESPONSE, 0x04),
        .handler = test_0x04_resp,
    },
    // ----------------------------
};
uint32_t __ext_cmd_list_len = ULIB_ARRAY_MAX(__ext_cmd_list);

int uptl_if_send(const uint8_t *data, size_t len)
{
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------
    if (!uptl_if_send_flag) {
        return UPTL_ERROR_SEND_FAILED;
    }

    memcpy(test_buf, data, len);
    int ret = uptl_process(test_buf, len);
    return ret;
    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------
    // return UPTL_SUCCESS;
}

/**
 * @brief Uprotocol start timeout handle timer
 *
 * @param hdl timeout handler
 * @return Uprotocol error code
 * @retval UPTL_SUCCESS: Start timer success
 * @retval Other: send failure
 */
int uptl_if_timeout(timeout_handler hdl)
{
    // ------------------------------------------------------------------------
    //                          User Implement Start
    // ------------------------------------------------------------------------

    if (!uptl_if_timeout_flag) {
        return UPTL_ERROR_TIMER_START;
    }
    test_timeout_handle = hdl;
    // ------------------------------------------------------------------------
    //                          User Implement End
    // ------------------------------------------------------------------------

    return UPTL_SUCCESS;
}
