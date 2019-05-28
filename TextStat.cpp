#include "TextStat.h"

void TextStat::addString(string word) {
    words.push_back(word);
}

int TextStat::size() {
    return words.size();
}

void TextStat::print() {
    for(int i=0; i<words.size(); i++) {
        cout << i+1 << ") " << words.at(i) << endl;
    }
}

vector<string> TextStat::getSortedVector() {
    vector<string> copyVector = words;
    sort(copyVector.begin(), copyVector.end(), [](string s1, string s2) {return s1.size() < s2.size();});

    return copyVector;
}

string TextStat::getLongest() {
    return getSortedVector().at(this->size() - 1);
}

string TextStat::getShortest() {
    return getSortedVector().at(0);
}

void TextStat::printLong(int n) {
    cout << "Words longer than " << n << " characters: " << endl;
    for(int i=0; i<words.size(); i++) {
        if(words.at(i).length() > n) {
            cout << words.at(i) << endl;
        }
    }
}

int TextStat::numUnique() {
    int counter = 0;
    bool increment;
    for(int i=0; i<words.size(); i++) {
        increment = true;
        for(int j=0; j<i; j++) {
            if(words.at(i) == words.at(j)) {
                increment = false;
                break;
            }
        }
        if(increment)
            counter++;
    }
    return counter;
}

string TextStat::mostFrequent() {
    vector<string> wordsSorted = getSortedVector();
    int counters[wordsSorted.size()];
    for(int i=0; i<wordsSorted.size(); i++) {
        int tmpCount = 0;
        for(int j=i+1; j<wordsSorted.size(); j++) {
            if(wordsSorted.at(i) == wordsSorted.at(j))
                tmpCount++;
        }
        counters[i] = tmpCount;
    }

    int maxCount = 0;
    int maxIndex = 0;

    for(int i=0; i<wordsSorted.size(); i++) {
        if(counters[i] > maxCount) {
            maxCount = counters[i];
            maxIndex = i;
        }
    }

    return wordsSorted.at(maxIndex);
}










