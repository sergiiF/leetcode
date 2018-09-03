#include <algorithm>    // std::transform
#include <string>
#include <ctype.h>
#include <iostream>

using namespace std;


class Solution {
public:
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};


int main () {
    string str{"Somopowekj  DDDDD sdlkal D kkkD"};
    Solution s;
    cout<<s.toLowerCase(str)<<endl;
}
