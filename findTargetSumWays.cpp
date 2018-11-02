#include <vector>
#include <queue>
#include <iostream>
#include <assert.h>
#include <stack>

using namespace std;

class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return 0;

        return dfs1 (nums, 0, S);
    }

    int dfs1(vector<int> nums, int len, int target) {
        stack<int> s;
        s.push(0);
        for (auto val : nums) {
            stack<int> temp;
            while (!s.empty()) {
                auto item = s.top(); s.pop();
                temp.push(item + val);
                temp.push(item - val);
            }
            swap(temp, s);
        }
        int count = 0;
        while (!s.empty()) {
            if (s.top() == target) ++count;
            s.pop();
        }
        return count;

    }


    int dfs2(vector<int> nums, int len, int target) {
        if (len == 1) {
            if (nums[0] == 0 && target == 0) return 2;
            return (abs(nums[0] == abs(target)) ? 1 : 0);
        }
        return dfs1(nums, len - 1, target - nums[len - 1]) + dfs1(nums, len - 1, target + nums[len - 1]);
    }


    int dfs(vector<int> nums, int idx, int sum, int target) {
        if (idx  == nums.size()) {
            return ((sum == target) ? 1 : 0);
        }
        return dfs(nums, idx + 1,sum + nums[idx], target) + dfs(nums, idx + 1, sum - nums[idx], target);
    }
};


int main () {

    //[10,34,28,5,10,26,9,17,28,10,9,6,10,15,0,28,42,39,25,19]
    //26
    Solution s;
    vector<int> vec = {33,36,38,40,25,49,1,8,50,13,41,50,29,27,18,25,37,8,0,48};
    cout << s.findTargetSumWays (vec, 0)<<endl;
}