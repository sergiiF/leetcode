#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string tmpStr;
        vector<string> res;
        if (n <=0) return res;
        generate(n, 0, 0, tmpStr, res);
        return res;
    }

private:
    void generate(int max, int open, int close, string tmp, vector<string>& res) {
        if (tmp.length() == max*2) {
            res.push_back(tmp);
            return;
        }
        if (open < max) {
            tmp.append("(");
            generate(max, open + 1, close, tmp, res);
            tmp.pop_back();
        }
        if (close < open) {
            tmp.append(")");
            generate(max, open, close + 1, tmp, res);
            tmp.pop_back();
        }
    }
};


int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(4);
    for (auto str: res) {
        cout<<str<<endl;
    }
    cout<<endl;

}