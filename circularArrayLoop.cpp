#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int i = 0;
        int steps = nums.size() +1;
        int size = nums.size();
        while(--steps){
            i = getNextIdx(i, nums[i], size);
        }
        return (i != 0);
    }
private:
    int getNextIdx(int current, int offs, int border) {
        int next = current + offs;
        if (next >= border) {
            next %= border;
        } else if (next < 0) {
            next = border - ((-next) % border);
        }
        return next;
    }
};



int main () {
    //vector<int> nums = {1,3,-1,-3,5,3,6,7};
    //int k = 3;
    //Output: [3,3,5,5,6,7] 


    vector<int> nums = {2, -1, 1, 2, 2};
    Solution s;
    cout<< s.circularArrayLoop(nums);


    cout<<endl;
}
