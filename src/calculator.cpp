#include "calculator.h"
#include <stdexcept>

int add(int a, int b) { return a + b; }

double divide(int a, int b) {
  if (b == 0) {
    throw std::invalid_argument("除数不能为 0");
  }
  return static_cast<double>(a) / b;
}