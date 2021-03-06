# Calendar CPP Application
This project aims to give users various answers to common date problems:
- Users can ask to find the date from x amount of days from a certain date(-a).
- Users can also find what day new years day is for a given year(-1).
- Users can find out which day of the week a certain date is(-w).
- Users can enter --help to learn more about the commands.

## Authors
Bilal Syed, Thy Le, Roberto Garcia

## Build Directions
Run command 'g++ main.cpp calendar.cpp' excluding the quotes while in the assignment directory.
This will generate an executable file.
Next, run './a.out' followed by the arguments you want.
If you are unsure which arguments are available or valid enter './a.out --help' to enter the help document.

## Testing Directions
In the terminal enter the command: 'docker build --rm ./' excluding quotes.
This will create a docker container that will build and run the tests.
It will display which tests passed and failed as well as an overall count of passing tests at the end.

## Versions
- C++ version: 14.0.0 or above
- G++ version: 9.2.0 or above
