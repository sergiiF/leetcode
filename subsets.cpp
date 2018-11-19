#include <vector>
#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        subsets(0, nums,tmp, res);
        return res;
    }
private:
    void subsets(int start, vector<int> nums, vector<int>& tmp, vector<vector<int>>& res) {
        res.push_back(tmp);
            for (int i = start; i < nums.size(); ++i) {
                tmp.push_back(nums[i]);
                subsets(i +1, nums, tmp, res);
                tmp.pop_back();
        }
    }
};


int main() {
    Solution s;
    vector<int> nums{1,2,3};
    vector<vector<int>> res = s.subsets(nums);

    for (auto row: res) {
        for (auto cell : row) {
            cout<<cell<<" ";
        }
        cout<<endl;
    }
}

