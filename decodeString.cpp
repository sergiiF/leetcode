/*
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

#include <string>
#include <iostream>
#include <cctype>
#include <stack>

using namespace std;
class Solution {
public:
    string decodeString1(string s) {
        int start_index= 0;
        return decodeString (s, start_index);
    }

    string decodeString(string s, int& i){
        string res = "";
        while (i < s.size() && s[i]!= ']') {
            if (!isdigit(s[i])) {
                res +=s[i];
                ++i;
            } else {
                int n = 0;
                while (i < s.size() && isdigit(s[i])) 
                    n = n * 10 + s[i++] - '0';
                ++i; //skip [
                string inner = decodeString(s, i);

                while (n--) {
                    res +=inner;
                }

                ++i; //skip ']'
            }
        }
        return res;
    }

    string decodeString(string s) {
        stack <int> numbers;
        stack <string> substrs;
        int n = 0;
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                n = n*10 + s[i] - '0';
//                numbers.push(s[i] - '0');
            } else if (isalpha(s[i])) {
                res +=s[i];
            }
            else if (s[i] == '['){
               // if (n)
                    numbers.push(n);
                //if (res!= "")
                    substrs.push(res);
                n = 0;
                res = "";
            } else if (s[i] == ']') {
                n = numbers.top(); numbers.pop();
                string str = res;
                while (--n) {
                    str +=res;
                }

                res = substrs.top() + str;
                substrs.pop();
            }
        }
       return res;
    }
};



int main () {
    Solution s;
    cout<<s.decodeString({"3[z]2[2[y]pq4[2[jk]e1[f]]]ef"})<<endl;
}