#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <string>
using namespace std;



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            //remove elements that are smaller than nums[i] from dq
            while (!dq.empty() && nums[i] >= dq.back()) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for (int i = k; i < nums.size(); ++i) {
            //get max
            result.push_back(nums[dq.front()]);
            //slide window
            while (!dq.empty() && dq.front() <= (i - k)) {
                dq.pop_front();
            }
            //add new elements
            while (!dq.empty() && nums[i] >= dq.back()) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        return result;
    }
};


int main () {
    //vector<int> nums = {1,3,-1,-3,5,3,6,7};
    //int k = 3;
    //Output: [3,3,5,5,6,7] 


    vector<int> nums = {7,2,4};
    int k = 2;
    //Output: 7,4
    Solution s;
    vector<int> res = s.maxSlidingWindow(nums, k);

    for(auto elem: res) {
        cout<<elem<<" ";
    }
    cout<<endl;
}
