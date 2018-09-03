#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length() != B.length()) return false;
        if (A == B) return true;

        string revA{A};
        reverse(revA.begin(), revA.end());
        int length = revA.length();
        cout<<A<<"------>"<<B<<endl;
        cout<<"reversed: "<<revA<<endl;
        for (int k = 0; k < length; k++) {
            string tmp{revA};
            reverse(tmp.begin(), tmp.begin() + k + 1);
            reverse (tmp.begin() + k + 1, tmp.end());
            cout<<tmp<<endl;
            if (tmp == B) return true;
        }
        return false;
    }
};


int main() {
    string str_start{"abcde"};
    string str_dest{"cdeab"};

    Solution s;
    string res = s.rotateString(str_start, str_dest)?"true" : "false";
    cout<<res<<endl;
}
