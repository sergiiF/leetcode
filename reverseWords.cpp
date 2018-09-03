#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;



class Solution {
public:
    string reverseWords(string s) {
        string::iterator word_begin = s.begin();
        string::iterator word_end  = s.begin();
        //find " "
        while (word_end!= s.end() && word_begin != s.end()) {
            word_end = find(word_begin, s.end(), ' ');
            //reverse word
            reverseWord(s, word_begin, word_end);
            word_begin = word_end + 1;
       }
        return s;
    }
private:
    string reverseWord(string& s, string::iterator begin, string::iterator end) {
        --end;
        if (begin == end) return s;
        while (begin < end) {
            swap (*(begin++), *(end--));
        }
        return s;
    }
};


int main() {
    string str{" "};
    Solution s;
    cout<<str<<" ------> '"<<s.reverseWords(str)<<"'"<<endl;

}
