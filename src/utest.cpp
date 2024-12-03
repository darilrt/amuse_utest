#include "amuse_utest/utest.hpp"

#include <iostream>

void amuse::utest::register_test(const char *name, TestFunction test, const char *desc)
{
    get_tests().push_back({name, test, desc});
}

int amuse::utest::run_tests()
{
    auto &tests = get_tests();

    for (const test &t : tests)
    {
        std::cout << "Running test: " << t.name << " (" << t.desc << ")" << std::endl;
        TestResult ret;
        t.func(ret);

        if (ret.error != SUCCESS)
        {
            std::cerr << "Test failed: " << t.name << " (" << t.desc << ")" << std::endl;
            return ret.error;
        }
    }

    return SUCCESS;
}

std::vector<amuse::utest::test> &amuse::utest::get_tests()
{
    static std::vector<test> tests;
    return tests;
}

#ifndef AMUSE_UTEST_NO_MAIN
int main()
{
    return amuse::utest::run_tests();
}
#endif