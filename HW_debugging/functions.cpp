#include <stdexcept>
#include <limits>
#include <cstdint>
#include "functions.h"

int largest(int a, int b, int c) {
  int d = a;
  if (b > d) {
    d = b;
  }
  if (c > d) {
    d = c;
  }
  return d;
}

bool sum_is_even(int a, int b) {
  // % can give -1 for negative sums, so just compare against 0
  return (a + b) % 2 == 0;
}

int boxes_needed(int apples) {
  if (apples <= 0) {
    return 0;
  }
  // round up instead of down.  adding 19 first would overflow for
  // apples near INT_MAX, so do the division first and add the partial box.
  int boxes = apples / 20;
  if (apples % 20 != 0) {
    boxes++;
  }
  return boxes;
}

bool smarter_section(int A_correct, int A_total, int B_correct, int B_total) {
  if (A_total <= 0 || B_total <= 0) {
    throw std::invalid_argument("section size must be positive");
  }
  if (A_correct < 0 || B_correct < 0 || A_correct > A_total || B_correct > B_total) {
    throw std::invalid_argument("bad number correct");
  }
  // cross multiply so we don't lose the fraction to integer division
  return (int64_t)A_correct * B_total > (int64_t)B_correct * A_total;
}

bool good_dinner(int pizzas, bool is_weekend) {
  if (pizzas < 10) {
    return false;
  }
  if (is_weekend) {
    return true;
  }
  return pizzas <= 20;
}

int32_t sum_between(int32_t low, int32_t high) {
  if (low > high) {
    throw std::invalid_argument("low is bigger than high");
  }
  // sum of an arithmetic series, done in 64 bits so it can't wrap around
  int64_t count = (int64_t)high - (int64_t)low + 1;
  int64_t total = ((int64_t)low + (int64_t)high) * count / 2;

  if (total > std::numeric_limits<int32_t>::max() ||
      total < std::numeric_limits<int32_t>::min()) {
    throw std::overflow_error("sum doesn't fit in 32 bits");
  }
  return (int32_t)total;
}

int64_t product(int64_t a, int64_t b) {
  if (a == 0 || b == 0) {
    return 0;
  }

  int64_t max = std::numeric_limits<int64_t>::max();
  int64_t min = std::numeric_limits<int64_t>::min();

  // check with division before multiplying so we never actually overflow
  if (a > 0 && b > 0) {
    if (a > max / b) {
      throw std::overflow_error("product too big");
    }
  } else if (a < 0 && b < 0) {
    // min / b is positive here
    if (a < max / b) {
      throw std::overflow_error("product too big");
    }
  } else if (a > 0) {  // a positive, b negative
    if (b < min / a) {
      throw std::overflow_error("product too small");
    }
  } else {  // a negative, b positive
    if (a < min / b) {
      throw std::overflow_error("product too small");
    }
  }

  return a * b;
}
