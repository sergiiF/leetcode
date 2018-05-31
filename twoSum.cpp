#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> res;

        int first = 0;
        int second = 1;
        int size = numbers.size();
        if (size < 2)  return res;

        while (first < size) {
            while (second < size) {
                int sum = numbers[first] + numbers[second];
                if (sum == target) {
                    res.push_back(first+1);
                    res.push_back(second+1);
                    return res;
                }
                if (sum > target){
                    break;
                }
                second++;
            }
            first++;
            second = first + 1;
        }
        return res;
    }
};
