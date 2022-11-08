#include <gtest/gtest.h>

#include "unitTest.h"
using namespace std;
#include <string>


TEST(unitTest, positiveGetState){

    string mock = getState("");

    EXPECT_EQ(mock, "(Choose Player phase.)");
}

TEST(unitTest, negativeGetState){

    string mock = getState("");

    EXPECT_NE(mock, "(Choose Player phase)");

}