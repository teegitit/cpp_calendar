//Names: Thy Le, Bilal Syed, Roberto Garcia

// calendar.cpp

#include "calendar.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Constructor
Calendar::Calendar(string command, string input, string daysToAdd)
{
    cmd = command;
    if (cmd == "-1")
    {
        day = 1;
        month = 1;
        year = stoi(input);
    }
    else
    {
        string *toSplit = new string[3];
        splitString(toSplit, input, "/");
        month = stoi(toSplit[0]);
        day = stoi(toSplit[1]);
        year = stoi(toSplit[2]);
        if(cmd == "-a")
        {
            toAdd = stoi(daysToAdd);
        }
    }
    //analyze();
}

//"Driver" of the program
void Calendar::analyze()
{
    if (cmd == "-1")
    {
        if (validate())
        {
            cout << "1/1/" << year << " is on ";
            cout << determineWeekday() << endl;
        }
    }
    else
    {
        if (validate())
        {
            if (cmd == "-a")
            {
                if(toAdd == 0)
                {
                    cout << month << "/" << day << "/" << year;
                    cout << " after " << toAdd << " days is on ";
                    cout << month << "/" << day << "/" << year;
                }
                else if (isnan(toAdd) || toAdd < 0)
                {
                    cout << "Please check your input for the days to add again!" << endl;
                }
                else if(toAdd > 0)
                {
                    cout << month << "/" << day << "/" << year;
                    cout << " after " << toAdd << " days is on " << determineDate();
                }
            }
            else if (cmd == "-w")
            {
                cout << month << "/" << day << "/" << year;
                cout << " is on a " << determineWeekday() << endl;
            }
        }
        else {
            cout << "Please check your input again!" << endl;
        }
    }
}

//Counts how many days in a month
int Calendar::daysInMonth()
{
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((!isnan(month)) && month >= 1 && month <= 12)
    {
      if (month == 2 && isLeapYear())
        return 29;
      return months[month - 1];
    }
    return -1;
}

//Determine if given year is a leap year
bool Calendar::isLeapYear()
{
    if ((year % 4 == 0) || (year % 100 == 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}

//Validates format of the input date
bool Calendar::validate()
{
    if (day < 1 || day > 31 || isnan(day))
        return false;
    if (month < 1 || month > 12 || isnan(month))
        return false;
    if (isnan(year) || year <= 1000 || year >= 9999)
        return false;
    if(isLeapYear() && month == 2 && day > 29)
        return false;
    if(!isLeapYear() && month == 2 && day > 28)
        return false;
    return true;
}

//Splits up the string
void Calendar::splitString(string *splitArr, string original, string del)
{
    int i = 0;
    int start = 0;
    int end = original.find(del);
    while (end != -1 && i < 2)
    {
        splitArr[i] = original.substr(start, end - start);
        start = end + del.size();
        end = original.find(del, start);
        i += 1;
    }
    splitArr[2] = original.substr(start, end - start);
}

//Determines the weekday of the date based on Zeller's algorithm
string Calendar::determineWeekday()
{
    string weekdays[] = {"Saturday",
                         "Sunday",
                         "Monday",
                         "Tuesday",
                         "Wednesday",
                         "Thursday",
                         "Friday"};
    int tempMonth;
    if (month > 2)
    {
        tempMonth = month;
    }
    else
    {
        tempMonth = month + 12;
        year -= 1;
    }
    int tempYearLast = year % 100;  //last 2 digit
    int tempYearFirst = year / 100; //first 2 digit
    int week = day + floor((13 * (tempMonth + 1)) / 5) + tempYearLast + floor(tempYearLast / 4) + floor(tempYearFirst / 4) + (5 * tempYearFirst);
    week = week % 7;
    string weekdayReturn = weekdays[week];
    return weekdayReturn;
}

//Determines the date after adding a number of days
string Calendar::determineDate()
{
    while (toAdd >= 365)
    {
        toAdd -= 365;
        if (isLeapYear())
        {
            toAdd -= 1;
        }
        year += 1;
    }
    if (toAdd < 365)
    {
        if (toAdd <= 0){
            month -= 1;
            day = daysInMonth();
        }
        else {
            while (toAdd > daysInMonth())
            {
                toAdd -= daysInMonth();
                month += 1;
            }
            if(toAdd <= daysInMonth())
            {
                day += toAdd;
                while(day > daysInMonth()){
                    day -= daysInMonth();
                    month += 1;
                }
            }
        }
    }

    string toReturn = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    return toReturn;
}
