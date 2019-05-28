#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <vector>
#include <map>
#include "Date.h"
#include <algorithm>

class Calendar
{
private:
    std::vector<Date> dates;
    std::vector< std::vector<std::string> > events;

public:

    void insertEvent(const Date &date, std::vector<std::string> contents) {
         /*for(int i=0; dates.size(); i++) {
            if(dates[i] == date) {
                for(int j=0; j<contents.size(); j++) {
                    events[i].push_back(contents[j]);
                }
                return;
            }
        }*/

        dates.push_back(date);
        events.push_back(contents);
    }

    std::vector<std::string> getEvents(const Date &date) {
        std::vector<std::string> eventsToReturn;
        for(int i=0; i<dates.size(); i++) {
            if(dates.at(i) == date) {
                for(int j=0; j<events[i].size(); j++) {
                    eventsToReturn.push_back(events[i].at(j));
                }
            }
        }
        return eventsToReturn;
    }


    void printEvents() {

        std::sort (dates.begin(), dates.end());

        for(int i=0; i<dates.size(); i++) {
            std::cout << i+1 << ") " << dates.at(i).getYear() << "\\" << dates.at(i).getMonth() << "\\" << dates.at(i).getDay() << std::endl;
            for(int j=0; j<events.at(i).size(); j++) {
                    std::cout << events.at(i).at(j) << std::endl;
                }
        }
    }


};

#endif // CALENDAR_H
