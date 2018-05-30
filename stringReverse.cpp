#include <algorithm>
#include <sting>
#include <sstream>
using namespace std;


class Solution {
public:
    string reverseString(string s) {
        return s.reverse(s.begin(),s.end());
    }
};

class Solution {
public:
    string reverseString(string s) {
        stringstream ss;
        for (string it = s.end(); it != s.begin(); it--) {
            ss<<it;
        }
        return ss.string();
    }
};


class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        string res;
        res.resize(len);
        int j = 0;
        int i = len - 1;
        while (i >= 0) {
            res[j++] = s[i--];
        }
        return res;
    }
};
