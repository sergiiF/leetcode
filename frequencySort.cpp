#include <string> 
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <functional>     // std::greater, less
#include <iostream>
#include <algorithm>
using namespace std;

//all symbols with equal frequency are mixed up
struct frequencyCmp {
    public:
    frequencyCmp(int* arr):symbols(arr) {}
    bool operator()(char c1, char c2){
        if (symbols[c1] == symbols[c2])
            return c1 < c2;
        return symbols[c1] > symbols[c2];
    }
    private:
    int* symbols = nullptr;

};


class Solution {
public:
    string frequencySort(string s) {
        if(s.size() <2) return s;
        for (char c:s) {
            ++symbols[c];
        }
        frequencyCmp fCmp(symbols);
        sort(s.begin(), s.end(), fCmp);
        return s;

    }
private:
    int symbols[256]{0};
};

/*
class Solution {
public:
    string frequencySort(string s) {
        if(s.size() <2) return s;
        return s;

    }
private:
};
*/
int main () {
    Solution s;
    string str{"loveleetcode"};
    cout<<s.frequencySort(str)<<endl;
}