#include <string> 
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <functional>     // std::greater, less
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>

// #include <list>
using namespace std;
template <typename T>
void vector_print(const string& msg, const vector<T>& v) {
    cout<<msg<<endl;
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    cout<<endl;
}


class Solution {
public:
    Solution(vector<int> nums): initial(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return initial;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        return initial;
    }

private:
    vector<int> initial;


};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main() {
    vector<int> nums{1,2,3,4,5};
    Solution s(nums);
    vector_print("shuffle: ", s.shuffle());
    vector_print("shuffle: ", s.shuffle());
    vector_print("shuffle: ", s.shuffle());
    vector_print("reset: ", s.reset());
    vector_print("shuffle: ", s.shuffle());
    vector_print("shuffle: ", s.shuffle());


}