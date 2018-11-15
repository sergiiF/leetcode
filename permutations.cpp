#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;

        permutate(nums, 0, res);
        return res;
    }
    private:
    void permutate(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            permutate(nums, start+1, res);
            swap(nums[start], nums[i]);
        }
    }
};


int main() {
    vector<int> vec = {1,2,3,4};
    Solution s;
    vector<vector<int>> res = s.permute(vec);

    for (auto row: res) {
        for (auto cell : row) {
            cout<<cell<<" ";
        }
        cout<<endl;
    }
}




// if(start >= nums.size()) {
//    res.push_back(nums);
//}
//for (i = start; i < nums.size(); ++i)
// 
//    swap(nums[start], nums[i]);
//    permutate(nums, start = i + 1)

      //inside permutate:  
        //for (j = i; j < nums.size(); ++j)
//            permutations (nums, start = j+i, end)