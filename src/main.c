/*
 * Copyright (c) 2024-2025, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "platform.h"
#include "McuRTOS.h"
#include <stdio.h>
#if PL_CONFIG_USE_GCOV
  #include "McuCoverage.h"
  #include "gcov_test.h"
#endif

int main(void) {
  PL_Init();
  vTaskStartScheduler();
#if PL_CONFIG_USE_GCOV
  gcov_test(0); /* i==0 path */
  gcov_test(1); /* i>0 path, value 5 */
  gcov_test(-1); /* i<0 path: i>0 is false */
  gcov_test(5); /* i>0 path with j=10: j<10 is false */
  McuCoverage_WriteFiles(); /* write coverage data files */
#endif /* PL_CONFIG_USE_GCOV */

  for(;;) {
    /* do not return from main() */
  }
  return 0;
}
