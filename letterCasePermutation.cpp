#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector <string> res;
        getPermutations(S, 0, res);

        return res;
    }
private:
 void getPermutations(string S, int i, vector<string>& res) {
     while (!isalpha(S[i]) && i < S.size()) ++i;
        if (i == S.size()) {
            res.push_back(S);
            return;
        }
        if (islower(S[i])) S[i] = toupper(S[i]);
        else S[i] = tolower(S[i]);
        getPermutations(S, i + 1, res);

        if (islower(S[i])) S[i] = toupper(S[i]);
        else S[i] = tolower(S[i]);
        getPermutations(S, i + 1, res);
 }

};


int main() {
    Solution s;
    string str{"asd"};
    vector<string> res = s.letterCasePermutation(str);
    for (auto str: res) {
        cout<<str<<endl;
    }
    cout<<endl;

}