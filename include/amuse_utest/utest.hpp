#pragma once

#include <iostream>
#include <vector>

enum : int
{
    SUCCESS = 0,
    UPDATE_ERRORS = 0x01,
    CONFIGURE_ERRORS = 0x02,
    BUILD_ERRORS = 0x04,
    TEST_ERRORS = 0x08,
    MEMORY_ERRORS = 0x10,
    COVERAGE_ERRORS = 0x20,
    SUBMIT_ERRORS = 0x40
};

typedef int (*TestFunction)();

namespace amuse
{
    class utest
    {
    public:
        static void register_test(const char *name, TestFunction test, const char *desc);
        static int run_tests();

    private:
        utest() = delete;

        struct test
        {
            const char *name;
            TestFunction func;
            const char *desc;
        };

        static std::vector<test> &get_tests();
    };
}

#define ASSERT(expr)                                                                                      \
    if (!(expr))                                                                                          \
    {                                                                                                     \
        std::cerr << "Assertion failed: " << #expr << " at " << __FILE__ << ":" << __LINE__ << std::endl; \
        return TEST_ERRORS;                                                                               \
    }

#define TEST(t, desc)                                 \
    int t();                                          \
    struct t##_registrar                              \
    {                                                 \
        t##_registrar()                               \
        {                                             \
            amuse::utest::register_test(#t, t, desc); \
        }                                             \
    } t##_registrar_instance;                         \
    int t()
