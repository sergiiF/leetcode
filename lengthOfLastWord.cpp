#include <vector>
#include <iostream>
#include <string>         // std::string
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = 0;
        const char space = ' ';
        vector<string> vec;

        size_t found = 0;
        while (found != string::npos && pos < s.length()){
            //skip all white spaces
            while (s[pos] == space) ++pos;
            found = s.find(space, pos);
            if (found == string::npos) found = s.length();
            cout<<"Pos: "<<pos<<" Found: "<<found<<endl;
            if (found != pos) {
                vec.push_back(s.substr(pos, found - pos));
                cout<< "Adding \"" <<s.substr(pos, found - pos)<<"\" to vector"<<endl;
            }
            pos = found + 1;
        }
        if(vec.empty()) return 0;
        return vec[vec.size() - 1].length();
    }
};


int main ()
{
    string str = "    ";
    Solution s;
    cout<< str<< "\nLast word length is: "<< s.lengthOfLastWord(str)<<endl;
}
