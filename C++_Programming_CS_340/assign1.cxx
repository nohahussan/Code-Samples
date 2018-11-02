#include <string>
#include <map>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    string s; // string object to read from input stream
    map<string, unsigned> hist; // histogram map container
    int longestEntrySize; // int variable to store the size of the longest word

    // get input from user until eof or stream error
    while (cin >> s)
        ++hist[s]; // add strings to the histogram map container

    // find the longest element in map
    // lambda function to find longest entry in map
    auto longestEntryLambda = [](auto elem1, auto elem2)
    {
        return (elem1.first.size()< elem2.first.size());
    };
    // invoke max_element algorithm to itrate over map elements
    auto const longestEntryInMap = max_element(begin(hist), end(hist), longestEntryLambda);
    // test if map was empty before accesing longest element to get its size
    longestEntrySize = (longestEntryInMap == end(hist)) ? 0:longestEntryInMap->first.size();

    // print out heading for output results
    cout << "\n\nAn unsorted frequency histogram of the input is:\n";

    // produce histogram output
    // lambda function to print hist output for an element
    auto histPrintLambda = [longestEntrySize](auto const& elem)
    {
        cout
         << left
         << setfill(' ')
         << setw(longestEntrySize)
         << elem.first
         << " |"
         << setfill('*')
         << setw(elem.second)
         << ""
         << "\n";
    };

    // loop over container elements and print out histogram results
    for_each(begin(hist), end(hist), histPrintLambda);
}
