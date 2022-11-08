#include <gtest/gtest.h>

#include "unitTest.h"
using namespace std;
#include <string>

//============================ChooseArmyType Test============================

TEST(unitTest, PchooseArmyType1){

    int input = 1;

    string res = chooseArmyType(input);

    EXPECT_EQ(res, "Build soldiers");

}
TEST(unitTest, NchooseArmyType1){

    int input = 1;

    string res = chooseArmyType(input);

    EXPECT_NE(res, "Not Build soldiers");

} 

TEST(unitTest, PchooseArmyType2){
    
    int input = 2;

    string res = chooseArmyType(input);

    EXPECT_EQ(res, "Build vehicles");

}

TEST(unitTest, NchooseArmyType2){
    
    int input = 2;

    string res = chooseArmyType(input);

    EXPECT_NE(res, "Not Build vehicles");

}


TEST(unitTest, PchooseArmyType3){

    
    int input = 3;

    string res = chooseArmyType(input);

    EXPECT_EQ(res, "invalid selection");

}

TEST(unitTest, NchooseArmyType3){

    
    int input = 3;

    string res = chooseArmyType(input);

    EXPECT_NE(res, "valid selection");

}

//============================ChooseSoldierRank Test============================

TEST(unitTest, PchooseSoldierRank1){
    int input = 1;

    string res = chooseSoldierRank(input);

    EXPECT_EQ(res, "Major [R 50 000]");

}

TEST(unitTest, NchooseSoldierRank1){
    int input = 1;

    string res = chooseSoldierRank(input);

    EXPECT_NE(res, "NOT Major [R 50 000]");

}

TEST(unitTest, PchooseSoldierRank2){
    int input = 2;

    string res = chooseSoldierRank(input);

    EXPECT_EQ(res, "Sergeant [R 30 000]");
    
}

TEST(unitTest, NchooseSoldierRank2){
    int input = 2;

    string res = chooseSoldierRank(input);

    EXPECT_NE(res, "NOT Sergeant [R 30 000]");
    
}

TEST(unitTest, PchooseSoldierRank3){
    int input = 3;

    string res = chooseSoldierRank(input);

    EXPECT_EQ(res, "Private [R 20 000]");
    
}

TEST(unitTest, NchooseSoldierRank3){
    int input = 3;

    string res = chooseSoldierRank(input);

    EXPECT_NE(res, "Not Private [R 20 000]");
    
}

TEST(unitTest, NchooseSoldierRank4){
    int input = 4;

    string res = chooseSoldierRank(input);

    EXPECT_NE(res, "Not Private [R 20 000]");
    
}


//============================ChooseVehicleType Test============================

TEST(unitTest, PchooseVehicleType1){
    int input = 1;

    string res = chooseVehicleType(input);

    EXPECT_EQ(res, "Planes [R 200 000]");
}

TEST(unitTest, NchooseVehicleType1){
    int input = 1;

    string res = chooseVehicleType(input);

    EXPECT_NE(res, "Not Planes [R 200 000]");
}


TEST(unitTest, PchooseVehicleType2){
    int input = 2;

    string res = chooseVehicleType(input);

    EXPECT_EQ(res, "Tanks [R 200 000]");
}


TEST(unitTest, NchooseVehicleType2){
    int input = 2;

    string res = chooseVehicleType(input);

    EXPECT_NE(res, "Not Tanks [R 200 000]");
}


TEST(unitTest, PchooseVehicleType3){
    int input = 3;

    string res = chooseVehicleType(input);

    EXPECT_EQ(res, "Ships [R 200 000]");
}


TEST(unitTest, NchooseVehicleType3){
    int input = 3;

    string res = chooseVehicleType(input);

    EXPECT_NE(res, "Not Ships [R 200 000]");
}


TEST(unitTest, InvalidchooseVehicleType4){
    int input = 4;

    string res = chooseVehicleType(input);

    EXPECT_EQ(res, "invalid selection");
}

