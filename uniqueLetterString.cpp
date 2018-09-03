#include <string>
#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    int uniqueLetterString(string S) {
        int len = S.length();
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                sum += uniq(S, i, j);
            }
        }
        return sum;
    }
private:
    int uniq(const string& str, int start, int end) {
        int chars[26] = {0};
         for (;start <= end; ++start) {
            ++chars['Z' - str[start]];
        }
        int count = 0;
        for (int i : chars) {
            if (i == 1) ++count;
        }
        return count;
    }
};


int main () {
    Solution s;
    string str{"AB"};
    cout<<str<<endl;
    cout<<s.uniqueLetterString(str)<<endl;
}
