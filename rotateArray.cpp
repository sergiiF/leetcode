#include <vector>
#include <algorithm>    // std::copy
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size())
            k = k % nums.size();
        int count  = 0;
        for (int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k)%nums.size();

                int tmp = nums[next];
                nums[next] = prev;
                prev = nums[next];

                current = next;
                ++count;
            } while (start != current);
        }
//        vector <int> nums2(nums.size());
//        copy(nums.end()-k, nums.end(), nums2.begin());
//        copy(nums.begin(),nums.end()-k, nums2.begin()+k);
    }
};
