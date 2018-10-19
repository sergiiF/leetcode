#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    int scoreOfParentheses1(string S) {
        int start_pos = 0;
        return scoreOfParenthesesRecursion(S, start_pos);
    }

    int scoreOfParentheses(string S) {
    }

    int scoreOfParenthesesRecursion(string str, int& pos) {
        cout<<"inside recursion, pos ="<<pos<<endl;
        int score = 0;
        while (pos < str.length()) {
            if (str[pos] == '(') {
                cout<<"first ( "<<endl;
                if(str[++pos] == ')') {
                    cout<<"first ) "<<endl;
                    ++score;
                } else {
                    cout<<"nested ( "<<endl;
                    score += 2 * scoreOfParenthesesRecursion(str, pos);
                }
                ++pos;
            } else {
                cout<<"last ) "<<endl;
                return score;
            }
        }
        return score;
    }
};


int main () {
    string S {"()()"};
    cout<<S<<endl;
    Solution s;
    cout<< s.scoreOfParentheses(S)<<endl;
}
