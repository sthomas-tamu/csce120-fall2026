// this file is provided. do not modify.

#ifndef PROVIDED_FUNCTIONS_H_
#define PROVIDED_FUNCTIONS_H_

#include <cstdint>

struct plateaus_and_basins {
    int plateaus;
    int basins;
};

bool is_valid_range(int64_t a, int64_t b);
char classify_geo_type(int64_t number);
plateaus_and_basins count_pb_numbers(int64_t a, int64_t b);

#endif  // PROVIDED_FUNCTIONS_H_
