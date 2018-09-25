#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;

        auto end = s.end();
        auto start = find_if_not(s.begin(), end, [](char c){ return c == ' ';});

        int count = 0;
        while (start < end) {
            auto pos = find_if(start, end, [](char c){ return c == ' ';});
            ++count;
            start = find_if_not(pos, end, [](char c){ return c == ' ';});
        }
        return count;


    }
};

int main() {
    Solution s;
    string str{"     Hello, my    name is John     "};
    cout<<str<<"---->"<<s.countSegments(str)<<endl;
}
