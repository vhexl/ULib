/**
 * @file test.c
 * @author vhex (visual86n@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-12-30
 *
 * SPDX-FileCopyrightText: Copyright (c) 2024
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include <string.h>

#include <unity.h>

#include "ULib.h"

#include "test.h"

/* Is run before every test, put unit init calls here. */
void setUp(void)
{
}

/* Is run after every test, put unit clean-up calls here. */
void tearDown(void)
{
}

void test_uconfig(void)
{
    extern bool test_init_if_flag;
    extern bool test_read_if_flag;
    extern bool test_write_if_flag;

    extern bool f1;
    extern uint8_t f2;
    extern uint16_t f3;
    extern uint32_t f4;
    extern uint64_t f5;
    extern float f6;
    extern double f7;
    extern char f8[6];
    extern uint32_t magic;

    bool t_f1;
    uint8_t t_f2;
    uint16_t t_f3;
    uint32_t t_f4;
    uint64_t t_f5;
    float t_f6;
    double t_f7;
    char t_f8[6];
    uint32_t t_magic;

    // ---------------------------------------------------------------------------------------
    //                            Initialization and Read Test
    // ---------------------------------------------------------------------------------------
    TEST_ASSERT_EQUAL(ucfg_init(), UCFG_SUCCESS);

    /* Test read all types */
    TEST_ASSERT_EQUAL(ucfg_read(0, (uint8_t *)&t_f1, sizeof(t_f1)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(1, (uint8_t *)&t_f2, sizeof(t_f2)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(2, (uint8_t *)&t_f3, sizeof(t_f3)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(3, (uint8_t *)&t_f4, sizeof(t_f4)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(4, (uint8_t *)&t_f5, sizeof(t_f5)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(5, (uint8_t *)&t_f6, sizeof(t_f6)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(6, (uint8_t *)&t_f7, sizeof(t_f7)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(7, (uint8_t *)t_f8, sizeof(t_f8)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(8, (uint8_t *)&t_magic, sizeof(t_magic)),
                      UCFG_SUCCESS);

    /* Check all read values */
    TEST_ASSERT_EQUAL_UINT32(t_f1, f1);
    TEST_ASSERT_EQUAL_UINT8(t_f2, f2);
    TEST_ASSERT_EQUAL_UINT16(t_f3, f3);
    TEST_ASSERT_EQUAL_UINT32(t_f4, f4);
    TEST_ASSERT_EQUAL_UINT64(t_f5, f5);
    TEST_ASSERT_EQUAL_FLOAT(t_f6, f6);
    TEST_ASSERT_EQUAL_DOUBLE(t_f7, f7);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(t_f8, f8, sizeof(t_f8));
    TEST_ASSERT_EQUAL_UINT32(t_magic, magic);

    // ---------------------------------------------------------------------------------------
    //                                      Write Test
    // ---------------------------------------------------------------------------------------

    /* Test write all types */
    t_f1    = true;
    t_f2    = 0x33;
    t_f3    = 0x1122;
    t_f4    = 0x11223344;
    t_f5    = 0x1122334455667788;
    t_f6    = 36.32768F;
    t_f7    = 999999.123456789;
    t_f8[0] = '!';
    t_f8[1] = '@';
    t_f8[2] = '#';
    t_f8[3] = '$';
    t_f8[4] = '%';
    t_f8[5] = '^';
    t_magic;

    TEST_ASSERT_EQUAL(ucfg_write(0, (uint8_t *)&t_f1, sizeof(t_f1)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_write(1, (uint8_t *)&t_f2, sizeof(t_f2)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_write(2, (uint8_t *)&t_f3, sizeof(t_f3)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_write(3, (uint8_t *)&t_f4, sizeof(t_f4)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_write(4, (uint8_t *)&t_f5, sizeof(t_f5)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_write(5, (uint8_t *)&t_f6, sizeof(t_f6)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_write(6, (uint8_t *)&t_f7, sizeof(t_f7)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_write(7, (uint8_t *)t_f8, sizeof(t_f8)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_write(8, (uint8_t *)&t_magic, sizeof(t_magic)),
                      UCFG_SUCCESS);

    /* Check all read values */
    TEST_ASSERT_EQUAL_UINT32(t_f1, f1);
    TEST_ASSERT_EQUAL_UINT8(t_f2, f2);
    TEST_ASSERT_EQUAL_UINT16(t_f3, f3);
    TEST_ASSERT_EQUAL_UINT32(t_f4, f4);
    TEST_ASSERT_EQUAL_UINT64(t_f5, f5);
    TEST_ASSERT_EQUAL_FLOAT(t_f6, f6);
    TEST_ASSERT_EQUAL_DOUBLE(t_f7, f7);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(t_f8, f8, sizeof(t_f8));
    TEST_ASSERT_EQUAL_UINT32(t_magic, magic);

    // ---------------------------------------------------------------------------------------
    //                                      Reread Test
    // ---------------------------------------------------------------------------------------
    /* NOTO: Only last test is pass this test is pass */
    /* Test read all types */
    TEST_ASSERT_EQUAL(ucfg_read(0, (uint8_t *)&t_f1, sizeof(t_f1)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(1, (uint8_t *)&t_f2, sizeof(t_f2)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(2, (uint8_t *)&t_f3, sizeof(t_f3)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(3, (uint8_t *)&t_f4, sizeof(t_f4)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(4, (uint8_t *)&t_f5, sizeof(t_f5)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(5, (uint8_t *)&t_f6, sizeof(t_f6)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(6, (uint8_t *)&t_f7, sizeof(t_f7)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(7, (uint8_t *)t_f8, sizeof(t_f8)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(8, (uint8_t *)&t_magic, sizeof(t_magic)),
                      UCFG_SUCCESS);

    /* Check all read values */
    TEST_ASSERT_EQUAL_UINT32(t_f1, f1);
    TEST_ASSERT_EQUAL_UINT8(t_f2, f2);
    TEST_ASSERT_EQUAL_UINT16(t_f3, f3);
    TEST_ASSERT_EQUAL_UINT32(t_f4, f4);
    TEST_ASSERT_EQUAL_UINT64(t_f5, f5);
    TEST_ASSERT_EQUAL_FLOAT(t_f6, f6);
    TEST_ASSERT_EQUAL_DOUBLE(t_f7, f7);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(t_f8, f8, sizeof(t_f8));
    TEST_ASSERT_EQUAL_UINT32(t_magic, magic);

    // ---------------------------------------------------------------------------------------
    //                                      Reinit Test
    // ---------------------------------------------------------------------------------------

    t_f1    = true;
    t_f2    = 0xAA;
    t_f3    = 0xAA55;
    t_f4    = 0x11223344;
    t_f5    = 0x1122334455667788;
    t_f6    = 3.141592653589793F;
    t_f7    = 1.333333333333333;
    t_f8[0] = 'a';
    t_f8[1] = 'b';
    t_f8[2] = 'c';
    t_f8[3] = 'd';
    t_f8[4] = 'e';
    t_f8[5] = 'f';
    t_magic = 0x11223344;

    TEST_ASSERT_EQUAL(ucfg_init(), UCFG_SUCCESS);

    /* Test read all types */
    TEST_ASSERT_EQUAL(ucfg_read(0, (uint8_t *)&t_f1, sizeof(t_f1)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(1, (uint8_t *)&t_f2, sizeof(t_f2)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(2, (uint8_t *)&t_f3, sizeof(t_f3)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(3, (uint8_t *)&t_f4, sizeof(t_f4)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(4, (uint8_t *)&t_f5, sizeof(t_f5)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(5, (uint8_t *)&t_f6, sizeof(t_f6)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(6, (uint8_t *)&t_f7, sizeof(t_f7)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(7, (uint8_t *)t_f8, sizeof(t_f8)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(8, (uint8_t *)&t_magic, sizeof(t_magic)),
                      UCFG_SUCCESS);

    /* Check all read values */
    TEST_ASSERT_EQUAL_UINT32(t_f1, f1);
    TEST_ASSERT_EQUAL_UINT8(t_f2, f2);
    TEST_ASSERT_EQUAL_UINT16(t_f3, f3);
    TEST_ASSERT_EQUAL_UINT32(t_f4, f4);
    TEST_ASSERT_EQUAL_UINT64(t_f5, f5);
    TEST_ASSERT_EQUAL_FLOAT(t_f6, f6);
    TEST_ASSERT_EQUAL_DOUBLE(t_f7, f7);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(t_f8, f8, sizeof(t_f8));
    TEST_ASSERT_EQUAL_UINT32(t_magic, magic);

    // ---------------------------------------------------------------------------------------
    //                                      Restore Test
    // ---------------------------------------------------------------------------------------
    TEST_ASSERT_EQUAL(ucfg_restore(), UCFG_SUCCESS);

    /* Test read all types */
    TEST_ASSERT_EQUAL(ucfg_read(0, (uint8_t *)&t_f1, sizeof(t_f1)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(1, (uint8_t *)&t_f2, sizeof(t_f2)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(2, (uint8_t *)&t_f3, sizeof(t_f3)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(3, (uint8_t *)&t_f4, sizeof(t_f4)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(4, (uint8_t *)&t_f5, sizeof(t_f5)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(5, (uint8_t *)&t_f6, sizeof(t_f6)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(6, (uint8_t *)&t_f7, sizeof(t_f7)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(7, (uint8_t *)t_f8, sizeof(t_f8)),
                      UCFG_SUCCESS);
    TEST_ASSERT_EQUAL(ucfg_read(8, (uint8_t *)&t_magic, sizeof(t_magic)),
                      UCFG_SUCCESS);

    /* Check all read values */
    TEST_ASSERT_EQUAL_UINT32(t_f1, f1);
    TEST_ASSERT_EQUAL_UINT8(t_f2, f2);
    TEST_ASSERT_EQUAL_UINT16(t_f3, f3);
    TEST_ASSERT_EQUAL_UINT32(t_f4, f4);
    TEST_ASSERT_EQUAL_UINT64(t_f5, f5);
    TEST_ASSERT_EQUAL_FLOAT(t_f6, f6);
    TEST_ASSERT_EQUAL_DOUBLE(t_f7, f7);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(t_f8, f8, sizeof(t_f8));
    TEST_ASSERT_EQUAL_UINT32(t_magic, magic);

    TEST_ASSERT_EQUAL(ucfg_deinit(), UCFG_SUCCESS);

    // ---------------------------------------------------------------------------------------
    //                                 Error handle Test
    // ---------------------------------------------------------------------------------------
    TEST_ASSERT_EQUAL(ucfg_read(99, NULL, 0), UCFG_ERROR_INVALID_FIELD);
    TEST_ASSERT_EQUAL(ucfg_read(0, NULL, 0), UCFG_ERROR_SIZE_MISMATCH);

    TEST_ASSERT_EQUAL(ucfg_write(99, NULL, 0), UCFG_ERROR_INVALID_FIELD);
    TEST_ASSERT_EQUAL(ucfg_write(0, NULL, 0), UCFG_ERROR_SIZE_MISMATCH);

    test_write_if_flag = false;
    TEST_ASSERT_EQUAL(ucfg_restore(), UCFG_ERROR_INTERNAL);
    test_write_if_flag = true;

    test_init_if_flag = false;
    TEST_ASSERT_EQUAL(ucfg_init(), UCFG_ERROR_INTERNAL);
    test_init_if_flag = true;

    test_read_if_flag = false;
    TEST_ASSERT_EQUAL(ucfg_init(), UCFG_ERROR_INTERNAL);
    test_read_if_flag = true;
}

void test_uprotocol(void)
{
    typedef void (*timeout_handler)(void);
    extern timeout_handler test_timeout_handle;
    extern bool uptl_if_send_flag;
    extern bool uptl_if_timeout_flag;

    extern enum uptl_ext uptl_ext_flag;

    extern uint32_t test_0x01_idx;
    extern uint32_t test_0x02_idx;

    int ret = UPTL_SUCCESS;
    // ---------------------------------------------------------------------------------------
    //                                  Base function test
    // ---------------------------------------------------------------------------------------
    uint8_t test_0x00_tmpl[18];

    // 0x00 used variable
    uint8_t test_0x00_p1  = 0x55;
    uint16_t test_0x00_p2 = 0x1122;
    uint32_t test_0x00_p3 = 0x11223344;
    uint64_t test_0x00_p4 = 0x1122334455667788;
    float test_0x00_p5    = 3.14159f;
    double test_0x00_p6   = 1.777777777;
    bool test_0x00_p7     = false;
    char test_0x00_p8[16] = "123456789abcdef";

    uint8_t test_send_0x01_buf[TEST_BUF_SIZE] = {0};
    uint8_t test_send_0x02_buf[TEST_BUF_SIZE] = {0};

    for (size_t i = 0; i < TEST_BUF_SIZE; i++) {
        test_send_0x02_buf[i] = 255 - (i % 256);
    }

    // test 0x00 read
    for (size_t i = 1; i < 9; i++) {
        test_0x00_tmpl[0] = i % 256;
        ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 1);
        TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);
    }

    // test 0x00 write
    test_0x00_tmpl[0] = 1;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p1, 1);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 2);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 2;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p2, 2);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 3);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 3;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p3, 4);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 5);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 4;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p4, 8);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 9);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 5;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p5, 4);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 5);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 6;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p6, 8);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 9);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 7;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p7, sizeof(bool));
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, sizeof(bool));
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 8;
    memcpy(test_0x00_tmpl + 1, test_0x00_p8, 16);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 17);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    // test 0x01
    for (size_t i = 0; i < TEST_BUF_SIZE; i++) {
        test_send_0x01_buf[i] = 255 - (i % 256);
    }
    ret = uptl_send(UPTL_PKT_REQUEST, 0x01, test_send_0x01_buf, TEST_BUF_SIZE);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    // test 0x02
    ret = uptl_send(UPTL_PKT_REQUEST, 0x02, NULL, 0);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    for (size_t i = 0; i < TEST_BUF_SIZE; i++) {
        if (test_send_0x01_buf[i] != 255 - (i % 256)) {
            TEST_FAIL();
        }
    }

    // ---------------------------------------------------------------------------------------
    //                                 Error handle test
    // ---------------------------------------------------------------------------------------
    test_0x01_idx = 0;
    test_0x02_idx = 0;

    // failed test
    size_t pkt_len_max = sizeof(struct uptl_pkt) + UPTL_PAYLOAD_SIZE_MAX;
    // segment test
    struct uptl_pkt *test_pkt = (struct uptl_pkt *)(test_send_0x01_buf);

    ret = uptl_send(UPTL_PKT_REQUEST, 0x09, test_0x00_tmpl, 1);
    TEST_ASSERT_EQUAL(ret, UPTL_ERROR_NOT_FOUND);

    uptl_if_send_flag = false; // set failed retrun
    ret               = uptl_send(UPTL_PKT_REQUEST, 0x09, test_0x00_tmpl, 1);
    TEST_ASSERT_EQUAL(ret, UPTL_ERROR_SEND_FAILED);
    uptl_if_send_flag = true; // set success retrun

    test_pkt->head = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x00);
    ret            = uptl_process((uint8_t *)test_pkt, 256);
    TEST_ASSERT_EQUAL(ret, UPTL_ERROR_SEGMENT);

    test_pkt->head = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x01);
    ret            = uptl_process((uint8_t *)test_pkt, 256);
    TEST_ASSERT_EQUAL(ret, UPTL_ERROR_SEGMENT_INAILD);

    // use uptl cache test
    for (size_t i = 0; i < 5; i++) {
        test_pkt->head =
            UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x01);
        ret = uptl_process((uint8_t *)test_pkt, pkt_len_max);
        TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);
    }
    test_pkt->head = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x01);
    ret            = uptl_process((uint8_t *)test_pkt, 256);
    TEST_ASSERT_EQUAL(ret, UPTL_ERROR_SEGMENT_END);
    for (size_t i = 0; i < 5; i++) {
        test_pkt->head =
            UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x01);
        ret = uptl_process((uint8_t *)test_pkt, pkt_len_max);
        TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);
    }
    test_pkt->head = UPTL_HEAD_SET(UPTL_PKT_NOSEGMENT, UPTL_PKT_REQUEST, 0x01);
    ret            = uptl_process((uint8_t *)test_pkt, 256);
    TEST_ASSERT_EQUAL(ret, UPTL_ERROR_INTERNAL);

    test_pkt->head = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x01);
    uptl_if_timeout_flag = false; // set failed retrun
    ret                  = uptl_process((uint8_t *)test_pkt, pkt_len_max);
    TEST_ASSERT_EQUAL(ret, UPTL_ERROR_TIMER_START);

    uptl_if_timeout_flag = true; // set success return
    for (size_t i = 0; i < 5; i++) {
        test_pkt->head =
            UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x01);
        ret = uptl_process((uint8_t *)test_pkt, pkt_len_max);
        TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);
    }
    test_pkt->head = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x02);
    ret            = uptl_process((uint8_t *)test_pkt, 256);
    TEST_ASSERT_EQUAL(ret, UPTL_ERROR_SEGMENT_END);

    test_0x01_idx = 0;
    for (size_t i = 0; i < 5; i++) {
        test_pkt->head =
            UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x01);
        ret = uptl_process((uint8_t *)test_pkt, pkt_len_max);
        TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);
    }
    test_timeout_handle(); // call timeout handle

    for (size_t i = 0; i < 5; i++) {
        test_pkt->head =
            UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x01);
        ret = uptl_process((uint8_t *)test_pkt, pkt_len_max);
        TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);
    }

    test_0x01_idx = 0;
    memset(test_send_0x01_buf, 0, TEST_BUF_SIZE);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x01, test_send_0x01_buf, TEST_BUF_SIZE);
    TEST_ASSERT_EQUAL(ret, UPTL_ERROR_INTERNAL);

    // ---------------------------------------------------------------------------------------
    //                                Rerun base function test
    // ---------------------------------------------------------------------------------------
    test_0x01_idx = 0;
    test_0x02_idx = 0;
    // test 0x00 read
    for (size_t i = 1; i < 9; i++) {
        test_0x00_tmpl[0] = i % 256;
        ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 1);
        TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);
    }

    // test 0x00 write
    test_0x00_tmpl[0] = 1;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p1, 1);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 2);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 2;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p2, 2);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 3);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 3;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p3, 4);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 5);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 4;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p4, 8);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 9);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 5;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p5, 4);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 5);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 6;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p6, 8);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 9);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 7;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p7, sizeof(bool));
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, sizeof(bool));
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 8;
    memcpy(test_0x00_tmpl + 1, test_0x00_p8, 16);
    ret = uptl_send(UPTL_PKT_REQUEST, 0x00, test_0x00_tmpl, 17);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    // test 0x01
    for (size_t i = 0; i < TEST_BUF_SIZE; i++) {
        test_send_0x01_buf[i] = 255 - (i % 256);
    }
    ret = uptl_send(UPTL_PKT_REQUEST, 0x01, test_send_0x01_buf, TEST_BUF_SIZE);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    // test 0x02
    ret = uptl_send(UPTL_PKT_REQUEST, 0x02, NULL, 0);
    TEST_ASSERT_EQUAL(ret, UPTL_SUCCESS);

    for (size_t i = 0; i < TEST_BUF_SIZE; i++) {
        if (test_send_0x01_buf[i] != 255 - (i % 256)) {
            TEST_FAIL();
        }
    }

    // ---------------------------------------------------------------------------------------
    //                                Extra test
    // ---------------------------------------------------------------------------------------
    // 0x03 request test
    ret = uptl_send(UPTL_PKT_REQUEST, 0x03, test_send_0x01_buf, 1);
    TEST_ASSERT_EQUAL(uptl_ext_flag, UPTL_EXT_NOSEG);
    // 0x03 response test
    ret = uptl_send(UPTL_PKT_RESPONSE, 0x03, test_send_0x01_buf, 1);
    TEST_ASSERT_EQUAL(uptl_ext_flag, UPTL_EXT_NOSEG);

    // 0x04 request test
    test_pkt->head = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x04);
    ret            = uptl_process((uint8_t *)test_pkt, pkt_len_max);
    TEST_ASSERT_EQUAL(uptl_ext_flag, UPTL_EXT_SEG_START);
    for (size_t i = 0; i < 5; i++) {
        test_pkt->head =
            UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_REQUEST, 0x04);
        ret = uptl_process((uint8_t *)test_pkt, pkt_len_max);
        TEST_ASSERT_EQUAL(uptl_ext_flag, UPTL_EXT_SEG_CONTINUE);
    }
    test_pkt->head = UPTL_HEAD_SET(UPTL_PKT_NOSEGMENT, UPTL_PKT_REQUEST, 0x04);
    ret            = uptl_process((uint8_t *)test_pkt, pkt_len_max);
    TEST_ASSERT_EQUAL(uptl_ext_flag, UPTL_EXT_SEG_END);

    ret = uptl_send(UPTL_PKT_REQUEST, 0x04, test_send_0x01_buf, 1);
    TEST_ASSERT_EQUAL(uptl_ext_flag, UPTL_EXT_NOSEG);

    // 0x04 response test
    test_pkt->head = UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_RESPONSE, 0x04);
    ret            = uptl_process((uint8_t *)test_pkt, pkt_len_max);
    TEST_ASSERT_EQUAL(uptl_ext_flag, UPTL_EXT_SEG_START);
    for (size_t i = 0; i < 5; i++) {
        test_pkt->head =
            UPTL_HEAD_SET(UPTL_PKT_SEGMENT, UPTL_PKT_RESPONSE, 0x04);
        ret = uptl_process((uint8_t *)test_pkt, pkt_len_max);
        TEST_ASSERT_EQUAL(uptl_ext_flag, UPTL_EXT_SEG_CONTINUE);
    }
    test_pkt->head = UPTL_HEAD_SET(UPTL_PKT_NOSEGMENT, UPTL_PKT_RESPONSE, 0x04);
    ret            = uptl_process((uint8_t *)test_pkt, pkt_len_max);
    TEST_ASSERT_EQUAL(uptl_ext_flag, UPTL_EXT_SEG_END);

    ret = uptl_send(UPTL_PKT_RESPONSE, 0x04, test_send_0x01_buf, 1);
    TEST_ASSERT_EQUAL(uptl_ext_flag, UPTL_EXT_NOSEG);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_uconfig);
    RUN_TEST(test_uprotocol);
    return UNITY_END();
}
