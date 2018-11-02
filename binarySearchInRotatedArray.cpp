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
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int begin = 0;
        int end = nums.size() -1;
        int mid;
        while (begin <= end) {
            int mid = (begin + end) /2;
            cout<<"mid element = "<<nums[mid];
            if ( target < nums[mid]) {
                if ((nums[begin] <= target) || (nums[mid] < nums[begin] )) { //go left
                    cout<<" , greater, going left"<<endl;
                    end = mid - 1;
                } else { //go right
                    cout<<" , greater, going right"<<endl;
                    begin = mid + 1;
                }
            } else if (nums[mid] < target) {
                if ((target <= nums[end]) || (nums[end] < nums[mid]) ) {//go right
                    cout<<" , less, going right"<<endl;
                    begin = mid + 1;
                }
                else { //go left
                    cout<<" , less, going right"<<endl;
                    end = mid -1;
                }
            } else { //nums[mid] == target
                cout<<" found"<<endl;
                return mid;
            }
        }

        return -1;
    }

    //Search in Rotated Sorted Array II - with duplicates
    bool searchWithDuplicates(vector<int>& nums, int target) {
        //TODO::have not finished yet
        if (nums.empty()) return false;
        int begin = 0;
        int end = nums.size() -1;
        int mid;
        while (begin <= end) {
            int mid = (begin + end) /2;
            cout<<"mid element = "<<nums[mid];
            if ( target < nums[mid]) {
                if ((nums[begin] <= target) || (nums[mid] < nums[begin] )) { //go left
                    cout<<" , greater, going left"<<endl;
                    end = mid - 1;
                } else { //go right
                    cout<<" , greater, going right"<<endl;
                    begin = mid + 1;
                }
            } else if (nums[mid] < target) {
                if ((target <= nums[end]) || (nums[end] < nums[mid]) ) {//go right
                    cout<<" , less, going right"<<endl;
                    begin = mid + 1;
                }
                else { //go left
                    cout<<" , less, going right"<<endl;
                    end = mid -1;
                }
            } else { //nums[mid] == target
                cout<<" found"<<endl;
                return true;
            }
        }

        return false;
    }


    int search1(vector<int>& nums, int target) { //takes O(n), not optimal
        if (nums.empty()) return -1;
        if (nums.size() == 1) return (target == nums[0])? 0 : -1;

        int i = nums.size() - 2;
        while(i && nums[i] < nums[i+1]) --i;
        cout<<"Found a[i] > a[i+1] at "<<i<<endl;

        if ((nums[0]<= target) && (target <= nums[i])) {
            cout<<"looking in first half"<<endl;
            return binarySearch(nums, 0, i, target);
        }
        if((nums[i+1] <= target) && (target <= nums[nums.size() - 1])) {
            cout<<"looking in second half"<<endl;
            return binarySearch(nums, i + 1, nums.size() - 1, target);
        }

        return -1;
    }
private:
    int binarySearch(vector<int>& vec, int begin, int end, int target) {
        int mid;
        cout<<"In binary search: begin = "<<begin<<" end = "<<end<<endl;
        while (begin <= end) {
            int mid = (begin + end)/2;
            if (vec[mid] == target) return mid;
            if (vec[mid] < target) {
                begin = mid +1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};


int main () {
    /*
    vector<int> vec {1,2,3,4,5};
    int target = 2;
    vector_print("Init:", vec);
    cout<<"target: "<<target<<endl;
    Solution s;

    int res= s.search(vec, target);

    cout<<res<<endl;
    */
    vector<int> vecWithDupl {1,1,3,1};
    int target = 3;
    vector_print("Init:", vecWithDupl);
    cout<<"target: "<<target<<endl;
    Solution s;

    bool res= s.searchWithDuplicates(vecWithDupl, target);

    cout<<res<<endl;
}
