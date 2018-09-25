#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> result;
        unordered_map<string, int> countPairedDomains;

        if (cpdomains.empty()) return result;
        stringstream ss;
        int count;
        string domain;

        for (auto& pair : cpdomains) {
            ss.clear();
            ss.str(pair);
            ss>>count>>domain;
            vector<string> subDomains = getSubDomains(domain);
            for (auto& item : subDomains) {
                countPairedDomains[item] +=count;
            }
        }
        for (const auto& pair : countPairedDomains) {
            result.push_back(string(to_string(pair.second) + " " + pair.first));
        }
        return result;
    }

    vector <string> getSubDomains(const string& domain) {
        vector<string> subDomainList;
        subDomainList.push_back(domain);
        int end = domain.length();
        for (int i = 0; i < end; ++i) {
            while ((i < end) && (domain[i] != '.')) ++i;
            if (i< end) {
                ++i;
                string token(domain, i, end - i);
                subDomainList.push_back(token);
            }
        }
        return subDomainList;
    }
};


int main() {
    vector<string> input = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    Solution s;
    vector<string> output = s.subdomainVisits(input);
    copy(output.begin(), output.end(), ostream_iterator<string>(cout, "\n"));
    cout<<endl;
}
