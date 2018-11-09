#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
        int res = 0;
        int prev = 0;
        for (int i = 0; i < s.length(); ++i) {
            int cur = convert(s[i]);
            if ((prev == 1 && (cur == 5 || cur == 10)) ||
            (prev == 10 && (cur == 50 || cur == 100)) ||
            (prev == 100 && (cur == 500 || cur == 1000)) )
            {
                res -= 2*prev;
            }
            res +=cur;
            prev = cur;
            
        }
        return res;
    }
private:

    int convert(char symbol) {
        switch(symbol) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M' : return 1000;
        }
        return 0;
    }
};


int main() {
    Solution s;
    string roman{"MCMXCIV"};
    cout<<s.romanToInt(roman)<< endl;
}