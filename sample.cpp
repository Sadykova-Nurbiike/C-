#include <iostream>
#include "Date.h"
#include "Calendar.h"

using namespace std;

int main()
{
    Date d1 = Date(2020, 05, 30);
    Date d2 = Date(2018, 07, 21);

    Calendar calendar;

    std::vector<string> events1;
    events1.push_back("Gym");
    events1.push_back("Birthday surprise");
    calendar.insertEvent(d1, events1);

    std::vector<string> events2;
    events2.push_back("Studying");
    events2.push_back("Working");
    calendar.insertEvent(d2, events2);

    calendar.printEvents();


    return 0;
}
