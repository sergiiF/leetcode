#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
void vector_print(const string& msg, const vector<T>& v) {
    cout<<msg<<endl;
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    cout<<endl;
}





class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return -1;

        int begin = 0, end = nums.size() -1, mid;
        if (nums[begin] <= nums[end]) return nums[begin]; //sorted
        while (begin < end) {
            mid = (begin + end)/2;
            //check for rotating point
            if (nums[mid] > nums[end]) { //go to right
                begin = mid + 1;
            } else {
                end = mid;
            }
        }

        return nums[begin];
    }
};


int main ()
{
    vector<int> vec {6,0};
    vector_print("Init:", vec);

    Solution s;
    cout<<s.findMin(vec)<<endl;
}
