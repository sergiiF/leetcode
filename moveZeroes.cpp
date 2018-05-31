#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto i = nums.begin();
        auto j = i +1;
        while(j != nums.end()) {
            if (*i == 0) {
                while ((*j == 0)&&(j!=nums.end())) j++;
                if (j!= nums.end()) {
                    iter_swap(i++,j++);
                }
            } else {
                i++;j++;
            }
        }
    }
};
