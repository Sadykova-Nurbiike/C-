#include <iostream>
#include <fstream>
#include "TextStat.h"

using namespace std;

int main()
{

    // Grade 2
    TextStat textStat;

    ifstream inputFile;
    inputFile.open("input.txt");
    if (!inputFile) {
        exit(0);
    }

    string tmp;
    while (getline(inputFile, tmp)) {
        textStat.addString(tmp);
    }

    cout << "Number of elements: " << textStat.size() << endl;
    textStat.print();

    // Grade 3

    cout << "Shortest: " << textStat.getShortest() << endl;
    cout << "Longest: " << textStat.getLongest() << endl;
    textStat.printLong(2);

    // Grade 4

    cout << "Number of unique words: " << textStat.numUnique() << endl;

    // Grade 5

    cout << "The most frequent word is: " << textStat.mostFrequent() << endl;


    return 0;
}
