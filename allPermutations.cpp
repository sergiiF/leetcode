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


int factorial(int n) {
    return ((n == 0) ? 1 : n * factorial(n - 1));
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        res.reserve(factorial(nums.size()));





        return res;
    }
};



int main() {
    Solution s;
    //vector<int> vec{1,2,3,4,7,6,5,1};
    vector<int> vec{1,5,4,1};
    vector_print("Initial:", vec);
    vector<vector<int>> res = s.permute(vec);
    for (auto x: res) {
        vector_print("", vec);
    }
}
