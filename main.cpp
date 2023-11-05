//Names: Thy Le, Bilal Syed, Roberto Garcia

#include "calendar.h"
#include <iostream>
using namespace std;

void print_help_message()
{
    //Prints all the options/feature we had
    cout << "--help:  " << "Help page: You are here" << endl;
    cout << "\n-a:\t" << "Adds number of days to input days and get the date" << endl;
    cout << "   \t" << "Syntax: -a <date to start> <number of days to add>" << endl;
    cout << "\n-w:\t" << "Gets a weekday of the input date" << endl;
    cout << "   \t" << "Syntax: -w <date to be determined>" << endl;
    cout << "\n-1:\t" << "Determine the weekday of 1/1 of the input year" << endl;
    cout << "   \t" << "Syntax: -1 <year to look for>" << endl;
}
int main(int argc, char *argv[])
{
    string cmd = "";
    if(argc > 0 && argc <= 4){
        cmd = string(argv[1]);
        if(cmd == "--help")
        {
            print_help_message();
        }
        else if(cmd == "-a")
        {
            string date = string(argv[2]);
            string daysToAdd = string(argv[3]);
            Calendar a(cmd, date, daysToAdd);
            a.analyze();
        }
        else if(cmd == "-w")
        {
            string date = string(argv[2]);
            Calendar w(cmd, date, "");
            w.analyze();
        }
        else if(cmd == "-1")
        {
            string year = string(argv[2]);
            Calendar o(cmd, year, "");
            o.analyze();
        }
    }
    return 0;
}
