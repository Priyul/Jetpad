#include <gtest/gtest.h>

#include "unitTest.h"

TEST(unitTest, random) {
  double res;

  double number = rand() % 100 + 1;

  res = randomNumber(1.0);

  if(number <= 1.0*100){
    EXPECT_EQ(res, 1);
  } else {
    EXPECT_EQ(res, 0);
  }
}