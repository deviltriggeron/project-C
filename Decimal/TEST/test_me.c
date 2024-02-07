#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *decimal_test[] = {test_add(),        test_decimal_to_int(),
                               test_div(),        test_float_to_decimal(),
                               test_floor(),      test_int_to_decimal(),
                               test_is_equal(),   test_is_greater_or_equal(),
                               test_is_greater(), test_is_less_or_equal(),
                               test_is_less(),    test_is_not_equal(),
                               test_mul(),        test_negate(),
                               test_round(),      test_sub(),
                               test_truncate(),   NULL};

  for (int i = 0; decimal_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(decimal_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
