#include <string>
#include <stack>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> st;
        for (char symbol : s) {
            if (corresponding(st, symbol)) {
                st.pop();
            } else {
                st.push(symbol);
            }
        }
        return st.empty();
    }

    bool corresponding(const stack<char>& st, char symbol) {
        if (st.empty () ) return false;
        enum parentethis{ 
            roundLeft = '(',
            roundRight = ')',
            curlLeft = '{',
            curlRight = '}',
            squareLeft = '[',
            squareRight = ']'
        };

        switch (symbol) {
            case roundLeft: case curlLeft: case squareLeft:
                return false;
            case roundRight:
                return roundLeft == st.top();
            case curlRight:
                return curlLeft == st.top();
            case squareRight:
                return squareLeft == st.top();
            default:
                return false;
        }

    }
};



int main () {
    Solution s;

    string str = "";

    assert (s.isValid(str) == true);
}