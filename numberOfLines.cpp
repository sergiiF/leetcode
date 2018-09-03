#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;


class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res;
        if (S.empty()) return res;
        int lines = 1;
        const int lineLength = 100;
        int remainder = lineLength;

        for (int i = 0; i< S.length(); i++) {
            int id = getId(S[i]);
            remainder -= widths[id];
            if(remainder == 0) {
                lines++;
                remainder = lineLength;
            } else if (remainder < 0) {
                lines++;
                remainder =lineLength - widths[id];
            }
            cout<<S[i]<<": "<<remainder<< " "<<lines<<endl;
        }
        res.push_back(lines);
        res.push_back(lineLength - remainder);
        return res;
    }
private:
    int getId(char c) {
        return (c -'a');
    }
};



int main() {
    vector<int> widths{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string str {"abcdefghijklmnopqrstuvwxyz"};
    Solution s;

    vector <int> vec = s.numberOfLines(widths, str);

    cout<<vec[0]<<":"<<vec[1]<<endl;
}
