#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator> // for ostream_iterator

using namespace std;


class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i< nums.size(); i+=2){
            sum+=nums[i];
        }
        return sum;
    }
};


int main(){
    vector <int> vec{-10, 0, 1,7};
    Solution s;
    copy(vec.begin(),vec.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    cout<<" Sum: "<< s.arrayPairSum(vec)<<endl;
}
