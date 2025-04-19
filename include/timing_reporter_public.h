#pragma once

// Std libs required for these macros to work.
#include <chrono>
#include <iostream>

#define TIMING_REPORT_ENABLE 0


#if TIMING_REPORT_ENABLE

#define TIMING_REPORT_START(name) auto timing_report_start_##name{ std::chrono::high_resolution_clock::now() }

#define TIMING_REPORT_END_AND_PRINT(name, msg_before)                                        \
do                                                                                           \
{                                                                                            \
    auto duration{ std::chrono::high_resolution_clock::now() - timing_report_start_##name }; \
    std::cout << msg_before << duration << std::endl;                                        \
} while (false)

#else  // TIMING_REPORT_ENABLE

#define TIMING_REPORT_START(name)
#define TIMING_REPORT_END_AND_PRINT(name, msg_before)

#endif  // TIMING_REPORT_ENABLE
