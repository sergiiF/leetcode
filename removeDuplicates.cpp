#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator> // for ostream_iterator

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;

        int i = 0;
        for(int j = 1; j < nums.size();j++) {
            if (nums[j]!=nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i +1;
    }
};

int main(){
    vector <int> vec{1,2,2,3,3,3,3,4};
    Solution s;
    copy(vec.begin(),vec.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    int len =  s.removeDuplicates(vec);
    cout<<" Length: "<<len<<endl;
    copy(vec.begin(),vec.begin() + len, ostream_iterator<int>(cout, " "));

}
