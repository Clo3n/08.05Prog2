#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

bool compareByValue(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

int main() {
  ifstream Fails("Teksts.txt");
  if (!Fails) cout << "Nevar atvērt failu...\n";
  else{
    map<string, int> Vardnica;
    string Teksts;
    while(Fails >> Teksts)
      {
        // Check if the last character of the word is a punctuation mark
        if (!isalpha(Teksts.back()) && !isdigit(Teksts.back())) {
            Teksts.pop_back(); // Remove the last character (punctuation)
        }
        
        if(Teksts.size() > 4)
        {
          Vardnica[Teksts]++;
        }
      }
    multimap<string, int> sortedMap;
    for (const auto &pair : Vardnica) {
        sortedMap.insert(pair);
    }
    vector<pair<string, int>> sortedVector;
    copy(sortedMap.begin(), sortedMap.end(), back_inserter(sortedVector));
    sort(sortedVector.begin(), sortedVector.end(), compareByValue);
    for (const auto &pair : sortedVector) {
        cout << pair.first << " - " << pair.second << endl;
    }
  }
  Fails.close();
  
}