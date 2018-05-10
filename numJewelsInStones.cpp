#include <map>
using namespace std;



class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // map<char, int> jewels;
        int count = 0;
        for (int i = 0; i < S.length(); i++) {
            if (J.find(S[i]) != string::npos) {
                // jewels[S[i]]++;
                count++;
            }
        }
        return count;
    }
};
