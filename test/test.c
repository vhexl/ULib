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
    TEST_ASSERT_EQUAL_UINT32(uconfig_init(), UCONFIG_SUCCESS);

    /* Test read all types */
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(0, (uint8_t *)&t_f1, sizeof(t_f1)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(1, (uint8_t *)&t_f2, sizeof(t_f2)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(2, (uint8_t *)&t_f3, sizeof(t_f3)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(3, (uint8_t *)&t_f4, sizeof(t_f4)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(4, (uint8_t *)&t_f5, sizeof(t_f5)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(5, (uint8_t *)&t_f6, sizeof(t_f6)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(6, (uint8_t *)&t_f7, sizeof(t_f7)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(7, (uint8_t *)t_f8, sizeof(t_f8)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(
        uconfig_read(8, (uint8_t *)&t_magic, sizeof(t_magic)), UCONFIG_SUCCESS);

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

    TEST_ASSERT_EQUAL_UINT32(uconfig_write(0, (uint8_t *)&t_f1, sizeof(t_f1)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_write(1, (uint8_t *)&t_f2, sizeof(t_f2)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_write(2, (uint8_t *)&t_f3, sizeof(t_f3)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_write(3, (uint8_t *)&t_f4, sizeof(t_f4)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_write(4, (uint8_t *)&t_f5, sizeof(t_f5)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_write(5, (uint8_t *)&t_f6, sizeof(t_f6)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_write(6, (uint8_t *)&t_f7, sizeof(t_f7)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_write(7, (uint8_t *)t_f8, sizeof(t_f8)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(
        uconfig_write(8, (uint8_t *)&t_magic, sizeof(t_magic)),
        UCONFIG_SUCCESS);

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
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(0, (uint8_t *)&t_f1, sizeof(t_f1)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(1, (uint8_t *)&t_f2, sizeof(t_f2)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(2, (uint8_t *)&t_f3, sizeof(t_f3)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(3, (uint8_t *)&t_f4, sizeof(t_f4)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(4, (uint8_t *)&t_f5, sizeof(t_f5)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(5, (uint8_t *)&t_f6, sizeof(t_f6)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(6, (uint8_t *)&t_f7, sizeof(t_f7)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(7, (uint8_t *)t_f8, sizeof(t_f8)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(
        uconfig_read(8, (uint8_t *)&t_magic, sizeof(t_magic)), UCONFIG_SUCCESS);

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

    TEST_ASSERT_EQUAL(uconfig_init(), UCONFIG_SUCCESS);

    /* Test read all types */
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(0, (uint8_t *)&t_f1, sizeof(t_f1)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(1, (uint8_t *)&t_f2, sizeof(t_f2)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(2, (uint8_t *)&t_f3, sizeof(t_f3)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(3, (uint8_t *)&t_f4, sizeof(t_f4)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(4, (uint8_t *)&t_f5, sizeof(t_f5)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(5, (uint8_t *)&t_f6, sizeof(t_f6)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(6, (uint8_t *)&t_f7, sizeof(t_f7)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(7, (uint8_t *)t_f8, sizeof(t_f8)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(
        uconfig_read(8, (uint8_t *)&t_magic, sizeof(t_magic)), UCONFIG_SUCCESS);

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
    TEST_ASSERT_EQUAL(uconfig_restore(), UCONFIG_SUCCESS);

    /* Test read all types */
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(0, (uint8_t *)&t_f1, sizeof(t_f1)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(1, (uint8_t *)&t_f2, sizeof(t_f2)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(2, (uint8_t *)&t_f3, sizeof(t_f3)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(3, (uint8_t *)&t_f4, sizeof(t_f4)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(4, (uint8_t *)&t_f5, sizeof(t_f5)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(5, (uint8_t *)&t_f6, sizeof(t_f6)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(6, (uint8_t *)&t_f7, sizeof(t_f7)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(uconfig_read(7, (uint8_t *)t_f8, sizeof(t_f8)),
                             UCONFIG_SUCCESS);
    TEST_ASSERT_EQUAL_UINT32(
        uconfig_read(8, (uint8_t *)&t_magic, sizeof(t_magic)), UCONFIG_SUCCESS);

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
}

void test_uprotocol(void)
{
    uint32_t ret = UPTL_SUCCESS;

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

    uint8_t test_send_0x01_buf[8192] = {0};
    uint8_t test_send_0x02_buf[8192] = {0};

    for (size_t i = 0; i < 8192; i++) {
        test_send_0x02_buf[i] = 255 - (i % 256);
    }

    // test 0x00 read
    for (size_t i = 1; i < 9; i++) {
        test_0x00_tmpl[0] = i % 256;
        ret = uptl_send(UPTL_FRAME_REQUEST, 0x00, test_0x00_tmpl, 1);
        TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);
    }

    // test 0x00 write
    test_0x00_tmpl[0] = 1;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p1, 1);
    ret = uptl_send(UPTL_FRAME_REQUEST, 0x00, test_0x00_tmpl, 2);
    TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 2;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p2, 2);
    ret = uptl_send(UPTL_FRAME_REQUEST, 0x00, test_0x00_tmpl, 3);
    TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 3;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p3, 4);
    ret = uptl_send(UPTL_FRAME_REQUEST, 0x00, test_0x00_tmpl, 5);
    TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 4;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p4, 8);
    ret = uptl_send(UPTL_FRAME_REQUEST, 0x00, test_0x00_tmpl, 9);
    TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 5;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p5, 4);
    ret = uptl_send(UPTL_FRAME_REQUEST, 0x00, test_0x00_tmpl, 5);
    TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 6;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p6, 8);
    ret = uptl_send(UPTL_FRAME_REQUEST, 0x00, test_0x00_tmpl, 9);
    TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 7;
    memcpy(test_0x00_tmpl + 1, &test_0x00_p7, sizeof(bool));
    ret = uptl_send(UPTL_FRAME_REQUEST, 0x00, test_0x00_tmpl, sizeof(bool));
    TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);

    test_0x00_tmpl[0] = 8;
    memcpy(test_0x00_tmpl + 1, test_0x00_p8, 16);
    ret = uptl_send(UPTL_FRAME_REQUEST, 0x00, test_0x00_tmpl, 17);
    TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);

    // test 0x01
    for (size_t i = 0; i < 8192; i++) {
        test_send_0x01_buf[i] = 255 - (i % 256);
    }
    ret = uptl_send(UPTL_FRAME_REQUEST, 0x01, test_send_0x01_buf, 8192);
    TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);

    // test 0x02
    ret = uptl_send(UPTL_FRAME_REQUEST, 0x02, NULL, 0);
    TEST_ASSERT_EQUAL_UINT32(ret, UPTL_SUCCESS);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_uconfig);
    RUN_TEST(test_uprotocol);
    return UNITY_END();
}
