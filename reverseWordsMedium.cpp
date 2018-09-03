#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ctype.h>

using namespace std;
inline bool isSpace(char c) {
    return isspace(c);
}

class Solution {
public:
    void reverseWords(string &s) {
        s.erase(s.begin(), find_if_not(s.begin(), s.end(), [](char c){ return c == ' ';}));
        reverse(s.begin(), s.end());
        cout<<"Reversed: "<<s<<endl;
        auto it_start = s.erase(s.begin(), find_if_not(s.begin(), s.end(), [](char c){ return c == ' ';}));

        while (it_start < s.end()) {
            cout<<"start="<<*it_start<<endl;
            auto it_cur = find(it_start, s.end(), ' ');
            cout<<"cur="<<*it_cur<<endl;
            reverse(it_start, it_cur);
            it_start = find_if_not(++it_cur, s.end(), [](char c){ return c == ' ';});

            if (it_start != s.end() && it_start != it_cur) s.erase(it_cur, it_start);
            it_start = it_cur;
        }
    }
};



int main() {
    Solution s;
    string str{"   one.   +two three?   ~four   !five- "};
    cout<<str;
    s.reverseWords(str);
    cout<<" --->"<<str<<":"<<endl;
}
