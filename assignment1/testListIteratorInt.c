//
// Created by 牟瑞 on 2018-12-19.
//

#include "/usr/local/include/check.h"
#include "listIteratorInt.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * 测试添加的方法
 * @param _i
 */
START_TEST(test_add)
    {
        // test
        int val, result;
        int *vp1;

        int params[9] = {20, 12, 15, 5, 14, 10, 5, 9, 3};

        // value
        IteratorInt it1 = IteratorIntNew();

        for (int i = 0; i < 9; i++) {
            result = add(it1, params[i]);
                    fail_unless(result == 1, "error, add(it1, %d) != 1", params[i]);

            // 判断没有next的操作
            result = hasNext(it1);
                    fail_unless(result == 0, "error, hasNext(it1) != 0");

            // 判断是否存在Previous的数据
            result = hasPrevious(it1);
                    fail_unless(result == 1, "error, hasPrevious(it1) != 1");

            vp1 = next(it1);
                    fail_unless(vp1 == NULL, "error, next(it1) != NULL");

            vp1 = previous(it1);
                    fail_unless(*vp1 == params[i], "error, previous(it1) != %d", params[i]);

            vp1 = next(it1);
                    fail_unless(*vp1 == params[i], "error, next(it1) != %d", params[i]);
        }
    }
END_TEST

/**
 * 测试添加的方法
 * @param _i
 */
START_TEST(test_iterator_init_null)
    {
        // test
        int val, result;
        int *vp1;
        // value
        IteratorInt it1 = NULL;

        // 判断添加
        result = add(it1, 1);
        fail_unless(result == 0, "error, add(it1, 1) != 0");

        // 判断没有next的操作
        result = hasNext(it1);
        fail_unless(result == 0, "error, hasNext(it1) != 0");

        // 判断是否存在Previous的数据
        result = hasPrevious(it1);
        fail_unless(result == 0, "error, hasPrevious(it1) != 0");

        vp1 = next(it1);
        fail_unless(vp1 == NULL, "error, next(it1) != NULL");

        vp1 = previous(it1);
        fail_unless(vp1 == NULL, "error, previous(it1) != NULL");

        vp1 = next(it1);
        fail_unless(vp1 == NULL, "error, next(it1) != NULL");

        vp1 = findPrevious(it1,1);
        fail_unless(vp1 == NULL, "error, findPrevious(it1,1) != NULL");

        vp1 = findNext(it1,1);
        fail_unless(vp1 == NULL, "error, findNext(it1,1) != NULL");

        result = deleteElm(it1);
        fail_unless(result == 0, "error, deleteElm(it1) != 0");

    }
END_TEST

/**
 * 重点测试老师给的测试case
 * @param _i
 */
START_TEST(test_teacher_given_cases)
    {
        // test
        int val, result;
        int *vp1;

        // value
        IteratorInt it1 = IteratorIntNew();

        /**
        add 20, returns 1
        ............................
        20   ^
        ............................
        */
        val = 20;
        result = add(it1, val);
        fail_unless(result == 1, "error, add(it1, %d) != 1", val);
        /**
        add 12, returns 1
        ............................
        20   12   ^
        ............................
        */
        val = 12;
        result = add(it1, val);
        fail_unless(result == 1, "error, add(it1, %d) != 1", val);

        /**
        add 33, returns 1
        ............................
        20   12   33   ^
        ............................
        */
        val = 33;
        result = add(it1, val);
                fail_unless(result == 1, "error, add(it1, %d) != 1", val);

        /**
        add 25, returns 1
        ............................
        20   12   33   25   ^
        ............................
        */
        val = 25;
        result = add(it1, val);
        fail_unless(result == 1, "error, add(it1, %d) != 1", val);

        /**
        previous, returns 25
        ............................
        20   12   33   ^   25
        ............................
        */
        vp1 = previous(it1);
        fail_unless(*vp1 == 25, "error, previous(it1) != 25");
        /**
        previous, returns 33
        ............................
        20   12   ^   33   25
        ............................
        */
        vp1 = previous(it1);
        fail_unless(*vp1 == 33, "error, previous(it1) != 33");

        /**
        next, returns 33
        ............................
        20   12   33   ^   25
        ............................
        */
        vp1 = next(it1);
        fail_unless(*vp1 == 33, "error, next(it1) != 33");
        /**
        delete, returns 1
        ............................
        20   12   ^   25
        ............................
        */
        result = deleteElm(it1);
        fail_unless(result == 1, "error, deleteElm(it1) != 1");

        /**
        previous, returns 12
        ............................
        20   ^   12   25
        ............................
        */
        vp1 = previous(it1);
        fail_unless(*vp1 == 12, "error, previous(it1) != 12");

        /**
        delete, returns 1
        ............................
        20   ^   25
        ............................
        */
        result = deleteElm(it1);
        fail_unless(result == 1, "error, deleteElm(it1) != 1");

        /**
        previous, returns 20
        ............................
        ^   20   25
         ............................
        */
        vp1 = previous(it1);
        fail_unless(*vp1 == 20, "error, previous(it1) != 12");
        /**
        delete, returns 1
        ............................
        ^   25
        ............................
        */
        result = deleteElm(it1);
        fail_unless(result == 1, "error, deleteElm(it1) != 1");

        /**
        next, returns 25
        ............................
        25   ^
        ............................
        */
        vp1 = next(it1);
        fail_unless(*vp1 == 25, "error, next(it1) != 25");

        /**
        delete, returns 1
        ............................
        ^
        ............................
        */
        result = deleteElm(it1);
        fail_unless(result == 1, "error, deleteElm(it1) != 1");
        /**
        add 55, returns 1
        ............................
        55   ^
        ............................
        */
        val = 55;
        result = add(it1, val);
                fail_unless(result == 1, "error, add(it1, %d) != 1", val);
        /**
        add 29, returns 1
        ............................
        55   29   ^
        ............................
        */
        val = 29;
        result = add(it1, val);
                fail_unless(result == 1, "error, add(it1, %d) != 1", val);

        /**
        reset
        ............................
        ^   55   29
        ............................
        */
        reset(it1);

        /**
        next, returns 55
        ............................
        55   ^   29
        ............................
        */
        // print(it1);
        vp1 = next(it1);
                fail_unless(*vp1 == 55, "error, next(it1) != 55");

        /**
        add 62, returns 1
        ............................
        55   62   ^   29
        ............................
        */
        val = 62;
        result = add(it1, val);
                fail_unless(result == 1, "error, add(it1, %d) != 1", val);
        /**
        add 44, returns 1
        ............................
        55   62   44   ^   29
        ............................
        */
        val = 44;
        result = add(it1, val);
                fail_unless(result == 1, "error, add(it1, %d) != 1", val);
        /**
        previous, returns 44
        ............................
        55   62   ^   44   29
        ............................
        */
        vp1 = previous(it1);
                fail_unless(*vp1 == 44, "error, previous(it1) != 12");

        /**
        next, returns 44
        ............................
        55   62   44   ^   29
        ............................
        */
        vp1 = next(it1);
                fail_unless(*vp1 == 44, "error, next(it1) != 55");
        /**
        delete, returns 1
        ............................
        55   62   ^   29
        ............................
        */
        result = deleteElm(it1);
                fail_unless(result == 1, "error, deleteElm(it1) != 1");

        /**
        previous, returns 62
        ............................
        55   ^   62   29
        ............................
        */
        vp1 = previous(it1);
                fail_unless(*vp1 == 62, "error, previous(it1) != 12");
        /**
        next, returns 62
        ............................
        55   62   ^   29
        ............................
        */
        vp1 = next(it1);
                fail_unless(*vp1 == 62, "error, next(it1) != 55");
        /**
        delete, returns 1
        ............................
        55   ^   29
        ............................
        */
        result = deleteElm(it1);
                fail_unless(result == 1, "error, deleteElm(it1) != 1");

        /**
        delete, returns 0
        ............................
        55   ^   29
        ............................
        */
        result = deleteElm(it1);
                fail_unless(result == 0, "error, deleteElm(it1) != 0");
        /**
        next, returns 29
        ............................
        55   29   ^
        ............................
        */
        vp1 = next(it1);
                fail_unless(*vp1 == 29, "error, next(it1) != 55");
        /**
        delete, returns 1
        ............................
        55   ^
        ............................
        */
        result = deleteElm(it1);
                fail_unless(result == 1, "error, deleteElm(it1) != 1");

        /**
        previous, returns 55
        ............................
        ^   55
        ............................
        */
        vp1 = previous(it1);
                fail_unless(*vp1 == 55, "error, previous(it1) != 12");
        /**
        delete, returns 1
        ............................
        ^
        ............................
        */
        result = deleteElm(it1);
                fail_unless(result == 1, "error, deleteElm(it1) != 1");
    }
END_TEST

START_TEST(test_next_case)
    {
        // test
        int val, result;
        int *vp1;

        // value
        IteratorInt it1 = IteratorIntNew();

        /**
        add 20, returns 1
        ............................
        20   ^
        ............................
        */
        val = 20;
        result = add(it1, val);
                fail_unless(result == 1, "error, add(it1, %d) != 1", val);
        /**
        add 12, returns 1
        ............................
        20   12   ^
        ............................
        */
        val = 12;
        result = add(it1, val);
                fail_unless(result == 1, "error, add(it1, %d) != 1", val);

        result = hasNext(it1);
                fail_unless(result == 0, "error, hasNext(it1) != 0", val);

        vp1 = previous(it1);
                fail_unless(*vp1 == 12, "error, previous(it1) != 12");

        result = hasNext(it1);
                fail_unless(result == 1, "error, hasNext(it1) != 1");
        result = hasPrevious(it1);
                fail_unless(result == 1, "error, hasPrevious(it1) != 1");

        vp1 = previous(it1);
                fail_unless(*vp1 == 20, "error, previous(it1) != 22");

        result = hasNext(it1);
                fail_unless(result == 1, "error, hasNext(it1) != 1");
        result = hasPrevious(it1);
                fail_unless(result == 0, "error, hasPrevious(it1) != 0");
    }
END_TEST

START_TEST(test_find_next_case)
    {
        // test
        int val, result;
        int *vp1;

        int params[9] = {20, 12, 15, 5, 14, 10, 5, 9, 3};

        // value
        IteratorInt it1 = IteratorIntNew();

        for (int i = 0; i < 9; i++) {
            result = add(it1, params[i]);
                    fail_unless(result == 1, "error, add(it1, %d) != 1", params[i]);
        }

        // 重置数据
        reset(it1);

        result = hasNext(it1);
                fail_unless(result == 1, "error, hasNext(it1) != 1");

        val = 20;
        result = add(it1, val);
                fail_unless(result == 1, "error, add(it1, %d) != 1", val);

        vp1 = next(it1);
                fail_unless(*vp1 == 20, "error, next(it1) != 20");

        vp1 = findNext(it1, 5);
                fail_unless(*vp1 == 5, "error, findNext(it1) != 5");

        vp1 = next(it1);
                fail_unless(*vp1 == 14, "error, next(it1) != 14");

        vp1 = previous(it1);
                fail_unless(*vp1 == 14, "error, previous(it1) != 14, current value is :%d", *vp1);

        vp1 = previous(it1);
                fail_unless(*vp1 == 5, "error, previous(it1) != 5");

    }
END_TEST


START_TEST(test_find_previous_case)
    {
        // test
        int val, result;
        int *vp1;

        int params[9] = {20, 12, 15, 5, 14, 10, 5, 9, 3};

        // value
        IteratorInt it1 = IteratorIntNew();

        for (int i = 0; i < 9; i++) {
            result = add(it1, params[i]);
                    fail_unless(result == 1, "error, add(it1, %d) != 1", params[i]);
        }

        result = hasNext(it1);
                fail_unless(result == 0, "error, hasNext(it1) != 0");

        vp1 = next(it1);
                fail_unless(vp1 == NULL, "error, next(it1) != NULL");

        result = hasPrevious(it1);
                fail_unless(result == 1, "error, hasPrevious(it1) != 1");

        vp1 = findPrevious(it1, 5);
                fail_unless(*vp1 == 5, "error, findPrevious(it1) != 5");

        vp1 = previous(it1);
                fail_unless(*vp1 == 10, "error, previous(it1) != 14, current value is :%d", *vp1);

        vp1 = findPrevious(it1, 5);
                fail_unless(*vp1 == 5, "error, findPrevious(it1) != 5");

    }
END_TEST

Suite *make_add_suite(void) {
    // 建立Suite
    Suite *s = suite_create("COMP9024 Assignment 1");
    // 建立测试用例集
    TCase *tc_case = tcase_create("test_cases");
    // 将测试用例加到Suite中
    suite_add_tcase(s, tc_case);


    // 测试用例加到测试集中
    // 测试添加数据
    tcase_add_test(tc_case, test_add);

    // 测试初始化为空的情况
    tcase_add_test(tc_case, test_iterator_init_null);
    // 测试老师给定的case
    tcase_add_test(tc_case, test_teacher_given_cases);
    // 测试用例加到测试集中
    tcase_add_test(tc_case, test_next_case);
    // 测试find next
    tcase_add_test(tc_case, test_find_next_case);

    // test find previous
    tcase_add_test(tc_case, test_find_previous_case);

    return s;
}

int main(void) {
    int n;
    SRunner *sr;
    sr = srunner_create(make_add_suite()); // 将Suite加入到SRunner
    // srunner_set_log (sr, "test.log");
    srunner_run_all(sr, CK_VERBOSE);
    // srunner_run_all(sr, CK_NORMAL);
    n = srunner_ntests_failed(sr);         // 运行所有测试用例
    srunner_free(sr);
    return (n == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}