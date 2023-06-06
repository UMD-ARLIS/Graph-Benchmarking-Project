//summer2023/Code/Utilities/dataLoader/test.c

# include <stdio.h>
# include <stdlib.h>

# include "../c-utils/src/minunit.h"

MU_TEST(test_simple) {
    //No test yet
}


// Test from in memory
MU_TEST_SUITE(suite_in_memory) {
    //MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

    MU_RUN_TEST(test_simple);
}

//Test from in files

MU_TEST_SUITE(suite_from_file) {
    //MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

    MU_RUN_TEST(test_simple);
}

int main() {
    MU_RUN_SUITE(suite_in_memory);
    MU_REPORT();
    printf("Number failed tests: %d\n", minunit_fail);
    return minunit_fail;
}