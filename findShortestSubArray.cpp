#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
using namespace std;

struct ArrEntry{
    int n;
    int first;
    int last;
    ArrEntry():n(0),first(0),last(0){};
};

class Solution {
public:
    class Solution {
    public:
        int arrangeCoins(int n) {
            return count = (int)sqrt(2.0*n);
        }
    };

    int findShortestSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

         cout<< "Input Vector: ";
         copy(nums.begin(), nums.end(), ostream_iterator<int> (cout, " "));
         cout <<endl;

        int mx = 0;
        unordered_map<int, ArrEntry> dict;
        for (int i = 0; i < nums.size(); i++) {
            if (dict[nums[i]].n++ == 0){
                dict[nums[i]].first = i;
            }
            dict[nums[i]].last = i;
            mx = max(mx, dict[nums[i]].n);
        }

        int minDist = nums.size();
        for (const auto& x : dict) {
            if (x.second.n == mx){
                minDist = min(minDist, 1 + x.second.last - x.second.first);
            }
        }
        return minDist;

    }
};



int main() {
    Solution s;
    vector<int> vec{1,2,2,3,2,4,4};
    cout<<s.findShortestSubArray(vec)<<endl;
}
