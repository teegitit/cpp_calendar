//Names: Thy Le, Bilal Syed, Roberto Garcia

#ifndef _calendar_h
#define _calendar_h
#include <string>

class Calendar{
protected:
  int day;
  int month;
  int year;
  int toAdd;
  std::string cmd;
  //Splits up the string
  void splitString(std::string* splitArr, std::string original, std::string del);
public:

  //Constructor
  Calendar(std::string cmd, std::string input, std::string daysToAdd);

  //Counts how many days in a month
  int daysInMonth();

  //Determine if given year is a leap year
  bool isLeapYear();

  //Validates format of the input date
  bool validate();

  //Determines the weekday of the date based on Zeller's algorithm
  std::string determineWeekday();

  //Determines the date after adding a number of days
  std::string determineDate();

  //"Driver" of the program
  void analyze();

};
#endif
