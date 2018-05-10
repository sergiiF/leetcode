#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int arr[32] = {0};
        for (int i = 0; i < nums.size(); i++){
            int num = nums[i];
            for (int offset = 0; offset < 32; offset++) {
                if (num & (1 << offset))
                    arr[offset]++;
                else
                    arr[offset]--;
            }
        }
        int result = 0;
        for (int offset = 0; offset < 32; offset++) {
            if (arr[offset] > 0) result |= 1 << offset;
        }
        return result;

        //sort(nums.begin(),nums.end());
        //return nums[nums.size()/2];
    }
};
int main()
{
    const int NUM = 9;
    int initArray[NUM] = {1,4,5,4,1,4,3,4,4};
    vector<int> v(initArray, initArray+NUM);

    Solution s;
    cout << s.majorityElement(v) << endl;
    return 0;
}
