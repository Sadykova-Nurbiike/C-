#ifndef TEXTSTAT_H
#define TEXTSTAT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

class TextStat {
private:
    vector<string> words;

public:
    void addString(string word);
    int size();
    void print();
    string getLongest();
    string getShortest();
    vector<string> getSortedVector();
    void printLong(int n);
    int numUnique();
    string mostFrequent();
};


#endif // TEXTSTAT_H
