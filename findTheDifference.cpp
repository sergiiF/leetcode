#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char diff ='\0';
         for (int i = 0; i<s.size(); i++) {
             diff ^=s[i];
             diff^=t[i];
        }
        diff^=t[t.size() - 1];
        return diff;
    }
};

int main()
{
    string a("qwert");
    string b("wqeutr");

    Solution s;
    char diff = s.findTheDifference(a,b);
    //s.findTheDifference(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<diff<<endl;

}
