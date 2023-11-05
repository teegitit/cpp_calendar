# Calendar CPP Application
This project aims to give users various answers to common date problems:
- Users can ask to find the date from x amount of days from a certain date(-a).
- Users can also find what day new years day is for a given year(-1).
- Users can find out which day of the week a certain date is(-w).
- Users can enter --help to learn more about the commands.

## Authors
Bilal Syed, Thy Le, Roberto Garcia

## Build and Run Directions
Run  the `calendar_builder.sh` script with the following command:
```
./calendar_builder.sh
```

This will generate an executable file called `calendar`. To run this executable file, run followed by the arguments you want.
```
./calendar <operation argument> <argument #1> <argument #2> ...
```
If you are unsure which arguments are available or valid enter './a.out --help' to enter the help document.

## Testing Directions
In the terminal enter the command: `docker build --rm ./`.
This will create a docker container that will build and run the tests.
It will display which tests passed and failed as well as an overall count of passing tests at the end.

## Versions
- C++ version: 14.0.0 or above
- G++ version: 9.2.0 or above
