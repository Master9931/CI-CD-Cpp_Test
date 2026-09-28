#include "calculator.h"
#include <cmath>
#include <iostream>
#include <stdexcept>


static int failures = 0;

void check(bool cond, const std::string &msg) {
  if (!cond) {
    std::cerr << "FAIL: " << msg << "\n";
    ++failures;
  } else {
    std::cout << "PASS: " << msg << "\n";
  }
}

int main() {
  check(add(1, 2) == 3, "add(1,2)==3");
  check(add(-1, 1) == 0, "add(-1,1)==0");
  check(std::abs(divide(10, 2) - 5.0) < 1e-9, "divide(10,2)==5");

  bool threw = false;
  try {
    divide(1, 0);
  } catch (const std::invalid_argument &) {
    threw = true;
  }
  check(threw, "divide(1,0) throws invalid_argument");

  if (failures == 0) {
    std::cout << "所有测试通过\n";
    return 0;
  }
  std::cerr << failures << " 个测试失败\n";
  return 1;
}