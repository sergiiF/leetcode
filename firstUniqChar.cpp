#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        vector<int> chars(26);
        //for each letter increment counter in chars
        cout<<s<<endl;
        for (char c : s) {
            chars[getId(c)]++;
        }
        copy(chars.begin(), chars.end(), ostream_iterator<int>(cout, " "));
        cout<<endl;

        //while letters if counter ==1 return
        for (int i = 0; i < s.length(); i++) {
            if (chars[getId(s[i])] == 1) return i;
            cout<<getId(s[i])<<" is "<<chars[getId(s[i])]<<endl;
        }
        return -1;
    }
private:
    inline const int getId(char c) { return (c - 'a'); }
};


int main () {
    Solution s;
    cout<<s.firstUniqChar({"y"})<<endl;
}
