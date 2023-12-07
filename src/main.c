#include <check.h>

#include "tests/tests.h"

void run() {
  Suite *tests[] = {
      suite_to_lower(), suite_to_upper(), suite_trim(),     suite_insert(),
      suite_memchr(),   suite_memcmp(),   suite_memcpy(),   suite_memmove(),
      suite_memset(),   suite_strcat(),   suite_strchr(),   suite_strcmp(),
      suite_strcpy(),   suite_strcspn(),  suite_strerror(), suite_strlen(),
      suite_strncat(),  suite_strncmp(),  suite_strncpy(),  suite_strpbrk(),
      suite_strrchr(),  suite_strspn(),   suite_strstr(),   suite_strtok(),
      suite_sprintf(),  S21_NULL,
  };

  int total = 0;
  int failed = 0;

  for (Suite **current = tests; *current; current++) {
    SRunner *sr = srunner_create(*current);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    total += srunner_ntests_run(sr);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf("\n" WHITE_BG BLACK " total: %d " RESET RED_BG BLACK
         " failed: %d " RESET GREEN_BG BLACK " success: %d " RESET "\n",
         total, failed, total - failed);
}

int main() {
  run();

  return 0;
}
