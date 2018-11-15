#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> combine(const int n, int k) {
        vector<vector<int>> res;
        if (n < 1 || k > n) return res;
        vector<int> tmp;
        combine(n, 1, k, tmp, res);
        return res;
    }
private:
    void combine(int n, int start, int k, vector<int> tmp, vector<vector<int>>& res) {
        if (tmp.size() == k) {
            res.push_back(tmp);
            //res.pop_back();
            return;
        }
        for (int i = start; i <= n; ++i) {
           tmp.push_back(i);
           combine(n, i + 1, k, tmp, res);
           tmp.pop_back();
        }
    }
};






int main() {
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);

    for (auto row: res) {
        for (auto cell : row) {
            cout<<cell<<" ";
        }
        cout<<endl;
    }
}


