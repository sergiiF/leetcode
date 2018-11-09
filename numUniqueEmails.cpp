#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> distinct;
        if (emails.size() < 2 ) return emails.size();
        for (string mail : emails) {
            string core = getCore(mail);
            if (!core.empty())
                distinct.insert(core);
        }
        return distinct.size();
    }
private:
    string getCore(const string& orig){
        string res;
        if (orig.empty())
            return res;
        int i = 0;
        while (i < orig.size()) {
            if (orig[i] == '@') {
                res.append(orig, i++, string::npos);
                return res;
            }else if (orig[i] == '.') {
                //ignore dot
                ++i;
            } else if (orig[i] == '+') {
                //ignore till the @
                while (orig[i] != '@') ++i;
            } else {
                res.append(orig, i++,1);
            }
        }
        return res = {};
    }
};


int main() {
    vector<string> vec = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    Solution s;
    int res = s.numUniqueEmails(vec);
    cout<<res<<endl;
}