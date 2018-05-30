#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto head = nums.begin();
        auto tail = nums.end();
        while (head != tail) {
            if (*head == 0) {
                iter_swap(head++,tail++);
            } else {
                head++;
            }
        }


    }
};
