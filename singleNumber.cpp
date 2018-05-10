#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;
        int vecSize = nums.size();
        for (int i = 0;i< vecSize; ++i)
            singleNum = nums[i] ^ singleNum;
        return singleNum;
    }
};


int main() {

    const int NUM = 7;
    int initArray[NUM] = {10,1,1,22,22,34,34};
    vector<int> v(initArray, initArray + NUM);
    Solution s;

    cout<<s.singleNumber(v)<<endl;
    return 0;
}
