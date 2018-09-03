#include <vector>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i]>nums[i+1]) {
                if (changed)
                    return false;
                if (!canBeChanged(nums, i)) return false;
                changed = true;
            }
        }
        return true;
    }
private:
    bool canBeChanged(vector<int>& nums, int i) {
        return ((i == 0) || (i >= nums.size()-2) ||
                (nums[i] <= nums[i+2]) || (nums[i-1] < nums[i+1]));
    }
};
