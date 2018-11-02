#include <vector>
#include <stack>
#include <string>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cctype>


using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;

        stringstream ss;
        int number;
        stack<int> st;

        for (string tok : tokens) {
            if (isdigit(tok[0])||(tok[0] == '-' && tok.size() > 1)) {
                ss<<tok;
                ss>>number;
                ss.clear();

                st.push(number);
            } else {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                if (tok == "+") first += second;
                else if (tok == "-") first -= second;
                else if (tok == "*") first *=second;
                else if (tok == "/") first /=second;

                st.push(first);
            }
        }
        return st.top();
    }
};

int main() {
    vector <string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution s;
    cout<<s.evalRPN(tokens)<<endl; 
}