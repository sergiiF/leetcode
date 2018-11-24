#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return;
        int zeros = 0;
        while (nums[zeros] == 0) ++zeros;
        int twos = nums.size() - 1;
        while (nums[twos] == 2) --twos;
        //if (zeros >= twos) return;
        int cur = zeros;
        while (cur <= twos) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[zeros++]);
                ++cur;
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[twos--]);
            } else 
                ++cur;
        }
        return;
    }
};



int main() {
    vector<int> vec{2,1,0};
    Solution s;
    s.sortColors(vec);
    for (auto item: vec) {
        cout<<item<<" ";
    }
    cout<<endl;
}