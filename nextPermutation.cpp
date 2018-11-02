#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;




class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return;
        int i = nums.size()-2;
        //find first a[i-1] < a[i] starting from the end
        while(i && (nums[i] >= nums[i+1])) --i;
        cout<<"first a[i] < a[i+1] found at "<<i<<endl;
        if (i || nums[i] < nums[i+1]) {
            //find last element greater then a[i] in range [i+1: end) - binary search
            int target = nums[i];
            int begin = i+1;
            int end = nums.size() - 1;
            while (begin < end) {
                cout<<"begin = "<<begin<<" end = "<<end<<endl;
                int middle = (begin + end +1)/2; //+1 for rounding up to whole int
                if (nums[middle] <= target) {
                    end = middle - 1;
                } else {
                    begin = middle;
                }
            }
            cout<<"last element greater then a[i] found at "<<begin<<endl;
            //swap
            swap(nums[i++], nums[begin]); //element i should not partisipate in reversing
            cout<< "now i = "<<i<<endl;
        }
        //reverse [i:end)
        reverse(nums.begin() + i, nums.end());
    }
};

template <typename T>
void vector_print(const string& msg, const vector<T>& v) {
    cout<<msg<<endl;
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    cout<<endl;
}

int main() {
    Solution s;
    //vector<int> vec{1,2,3,4,7,6,5,1};
    vector<int> vec{1,5,4,1};
    vector_print("Initial:", vec);
    s.nextPermutation(vec);
    vector_print("Result:", vec);
}
