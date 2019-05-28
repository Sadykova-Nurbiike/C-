/*
Evan Sitt
C3JI5D
C++ Final Exam
2. Create a class named TextStat. This class can maintain a set of words and
   provide some statistics about them. The class has the following methods:
   - add(string): Adds a string to the collection.
   - size(): Returns the number of words in the collection.
   - print(): Prints the added words.
   Read some words from the standard input or from file and store them in a
   TextStat object. Print the stored words and their number to the standard
   output.
3. Add the following methods to the class:
   - getLongest(): Returns one of the longest words of the collection.
   - getShortest(): Returns one of the shortest words of the collection.
   - printLong(n): Prints the words longer than "n" characters to the standard
     output.
4. Add the following method to the class:
   - numUnique(): Returns the number of unique words of the collection. For
     example: apple, pear, apple, orange, orange, apple -> 3.
5. Add the following method to the class:
   - mostFrequent(): Returns the most frequent word of the collection. For
     example: apple, pear, apple, orange, orange, apple -> apple.
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<fstream>

namespace TibiLand
{
class TextStat
{
protected:
    std::vector<std::string> HoldMyStringsPlz;
public:
    TextStat()
    {
    }
    virtual ~TextStat()
    {
    }
    std::string add(const std::string & newString)
    {
        HoldMyStringsPlz.push_back(newString);
        return HoldMyStringsPlz.back();
    }
    int size()
    {
        return HoldMyStringsPlz.size();
    }
    bool print()
    {
        std::cout<<std::endl;
        for(int i=0; i<size(); ++i)
        {
            std::cout<<HoldMyStringsPlz.at(i)<<std::endl;
        }
    }
    std::string getLongest()
    {
        int biggestLength=0;
        int index=0;
        for(int i=0; i<size(); ++i)
        {
            if(HoldMyStringsPlz.at(i).size()>biggestLength)
            {
                index=i;
                biggestLength=HoldMyStringsPlz.at(i).size();
            }
        }
        return HoldMyStringsPlz.at(index);
    }
    std::string getShortest()
    {
        int shortestLength=HoldMyStringsPlz.front().size();
        int index=0;
        for(int i=1; i<size(); ++i)
        {
            if(HoldMyStringsPlz.at(i).size()<shortestLength)
            {
                index=i;
                shortestLength=HoldMyStringsPlz.at(i).size();
            }
        }
        return HoldMyStringsPlz.at(index);
    }
    int printLong(int n)
    {
        int WeGotEmLongs=0;
        for(int i=0; i<size(); ++i)
        {
            if(HoldMyStringsPlz.at(i).size()>=n)
            {
                std::cout<<HoldMyStringsPlz.at(i)<<std::endl;
                ++WeGotEmLongs;
            }
        }
        return WeGotEmLongs;
    }
    int numUnique()
    {
        std::set<std::string> GonnaUseDis(HoldMyStringsPlz.begin(),HoldMyStringsPlz.end());
        return GonnaUseDis.size();
    }
    std::string mostFrequent()
    {
        int frequencyOfThis=0;
        int index=0;
        for(int i=0; i<size(); ++i)
        {
            int counter=0;
            for(int j=0; j<size(); ++j)
            {
                if(HoldMyStringsPlz.at(i)==HoldMyStringsPlz.at(j))
                {
                    ++counter;
                }
            }
            if(counter>frequencyOfThis)
            {
                frequencyOfThis=counter;
                index=i;
            }
        }
        return HoldMyStringsPlz.at(index);
    }
};

bool loop(TextStat * InMotherHungaryTextStoresYou)
{
    std::string helloNope;
    std::cout<<"Do you have a text you would like to enter? (y/n) ";
    std::cin>>helloNope;
    if(helloNope=="n")
    {
        std::cout<<"Very well, I bid thee farewell!"<<std::endl;
        return false;
    }
    else if(helloNope!="y")
    {
        std::cout<<"Wo bu ming ba ni sho su mo!"<<std::endl;
        return true;
    }
    std::cout<<"Sounds good, plz gimme text: ";
    std::cin>>helloNope;
    InMotherHungaryTextStoresYou->add(helloNope);
    std::cout<<"Thank you! Me stores this for safekeeping."<<std::endl;
    return true;
}

std::string doSomethingPlz()
{
    TextStat * InMotherHungaryTextStoresYou = new TextStat();
    std::cout<<"Hello Hungary!"<<std::endl;
    bool omgCanHazBoolgerPlz=true;
    while(omgCanHazBoolgerPlz)
    {
        omgCanHazBoolgerPlz = loop(InMotherHungaryTextStoresYou);
    }
    std::cout<<"Entry completed!"<<std::endl;
    std::cout<<"Now printing your love messages!"<<std::endl;
    InMotherHungaryTextStoresYou->print();
    std::cout<<"Your longest word is: "<<InMotherHungaryTextStoresYou->getLongest()<<std::endl;
    std::cout<<"Your shortest word is: "<<InMotherHungaryTextStoresYou->getShortest()<<std::endl;
    int WeThinkDisBeLong;
    std::cout<<"Please enter a length that you would consider as long: ";
    std::cin>> WeThinkDisBeLong;
    std::cout<<"Your long words are:"<<std::endl;
    InMotherHungaryTextStoresYou->printLong(WeThinkDisBeLong);
    std::cout<<"Your love messages have "<<InMotherHungaryTextStoresYou->numUnique()<<" unique texts."<<std::endl;
    std::cout<<"Your most frequently entered text is: "<<InMotherHungaryTextStoresYou->mostFrequent()<<std::endl;
    delete InMotherHungaryTextStoresYou;
}

}

int main()
{
    TibiLand::doSomethingPlz();
    return 0;
}

