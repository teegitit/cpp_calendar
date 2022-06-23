//Names: Thy Le, Bilal Syed, Roberto Garcia

#include "calendar.h"
#include <gtest/gtest.h>

//creating this test to test docker configuration
TEST(calendarTest, daysInMonthValid) {
  //Arrange
  Calendar calendar("-a", "10/1/2021", "30");
  //Act
  int numDays = calendar.daysInMonth();
  //Assert
  EXPECT_EQ(numDays, 31);
}

TEST(calendarTest, daysInMonthValidLeap) {
  //Arrange
  Calendar calendar("-a", "2/1/2024", "30");
  //Act
  int numDays = calendar.daysInMonth();
  //Assert
  EXPECT_EQ(numDays, 29);
}

TEST(calendarTest, daysInMonthInvalid) {
  //Arrange
  Calendar calendar("-a", "15/1/2024", "30");
  //Act
  int numDays = calendar.daysInMonth();
  //Assert
  EXPECT_EQ(numDays, -1);
}

TEST(calendarTest, isLeap) {
  //Arrange
  Calendar calendar("-a", "10/1/2024", "30");
  //Assert
  EXPECT_TRUE(calendar.isLeapYear());
}

TEST(calendarTest, isNotLeap) {
  //Arrange
  Calendar calendar("-a", "9/1/2021", "30");
  //Assert
  EXPECT_FALSE(calendar.isLeapYear());
}

TEST(calendarTest, dateInvalid) {
  //Arrange
  Calendar calendar("-a", "15/1/2021", "30");
  //Assert
  EXPECT_FALSE(calendar.validate());
}

TEST(calendarTest, dateValid) {
  //Arrange
  Calendar calendar("-a", "10/1/2021", "30");
  //Assert
  EXPECT_TRUE(calendar.validate());
}

TEST(calendarTest, determineWeekdayTest) {
  //Arrange
  Calendar calendar("-w", "10/28/2021", "");
  //Assert
  EXPECT_EQ("Thursday",calendar.determineWeekday());
}

TEST(calendarTest, determineWeekdayNewYear) {
  //Arrange
  Calendar calendar("-1", "2022", "");
  //Assert
  EXPECT_EQ("Saturday",calendar.determineWeekday());
}

TEST(calendarTest, determineDateValid) {
  //Arrange
  Calendar calendar("-a", "10/1/2021", "30");
  //Assert
  EXPECT_EQ("10/31/2021",calendar.determineDate());
}

TEST(calendarTest, addDaysLeapYear) {
  //Arrange
  Calendar calendar("-a", "10/1/2021", "1095");
  //Assert
  EXPECT_EQ("9/30/2024",calendar.determineDate());
}


int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
