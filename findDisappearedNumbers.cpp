#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        for (int k = 0; k < nums.size(); k++) {
            if (0 < nums[k]) res.push_back(k + 1);
        }
        return res;
    }
};


int main () {
    vector<int> input{4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> vec = s.findDisappearedNumbers(input);
    copy(vec.begin(), vec.end(), ostream_iterator<int> (cout, " "));

}
